// channeld.c 
// 3/23/96 modified by cleansword to prevent chat flooding
// 04/18/96 modified by Marz to provide specific channel blocking 

#include <ansi.h>
#include <net/dns.h>
inherit F_DBASE;

mapping channels = ([
	"sys":	([	"msg_speak": HIR "【系统】%s：%s\n" NOR, "wiz_only": 1 ]),
	"wiz":	([	"msg_speak": HIY "【巫师】%s：%s\n" NOR,
				"msg_emote": HIY "【巫师】%s" NOR,
				"wiz_only": 1
			]),
	"chat":	([	"msg_speak": HIC "【闲聊】%s：%s\n" NOR,
				"msg_emote": HIG "【闲聊】%s" NOR,
			 ]),
	"rumor":([	"msg_speak": HIM "【谣言】%s：%s\n" NOR,
				"msg_emote": HIM "【谣言】%s" NOR,
				"anonymous": "某人"
			]),
	"music":([	"msg_speak": HIY "【心笙乐府】%s唱著：%s\n" NOR,
				"msg_emote": HIY "【心笙乐府】%s" NOR
             ]),
/**			
	"vote":([	"msg_speak": HIM "【表决】%s %s\n" NOR,
				"msg_emote": HIM "【表决】%s" NOR,
				"vote_only": 1
			]),
**/			
]);

int block_rumor = 0;
int block_chat = 0;

void create()
{
	seteuid(getuid());	// This is required to pass intermud access check.
	set("channel_id", "频道精灵");
}

varargs int do_channel(object me, string verb, string arg, int emote)
{
	object *ob;
	string *tuned_ch, who;

	// check if one can write to channels
	if ((int)me->query("chblk_on") && !wizardp(me)) return 0;
//		return notify_fail("你的频道被关闭了！\n");

	if ((int)me->query("chblk_on") && wizardp(me))
	{
	//only block a wiz's rumor and chat...
		me->set("chblk_rumor", 1);
		me->set("chblk_chat", 1);
	}
	if ((int)me->query("chblk_rumor") && (verb == "rumor"||verb == "rumor*") )
		return notify_fail("ｏｏｐｓ！你的谣言频道被关闭了！\n");
	if ((int)me->query("chblk_chat") && (verb == "chat"||verb == "chat*") )
		return notify_fail("ｏｏｐｓ！你的聊天频道被关闭了！\n");
 	// check if rumor or chat is blocked		
	if ((int)block_rumor && (verb == "rumor"||verb == "rumor*") )
		return notify_fail("遥言频道被关闭了！\n");
	if ((int)block_chat && (verb == "chat"||verb == "chat*") )
		return notify_fail("聊天频道被关闭了！\n");
  
	//added by jungu

	if ((int)block_chat && (verb == "music"||verb == "music*") )
		return notify_fail("心笙乐府频道被关闭了！\n");   
	if ( verb == "music*" ) {
		if (!stringp(arg)) return 0 ;
		if ( (int) strsrch ( arg , "sing" , 1 ) == -1 )	return 0 ;    
	}
	//music ok
	// Check if this is a channel emote.
	
	if( verb[sizeof(verb)-1] == '*' ) {
		emote = 1;
		verb = verb[0..<2];
	}
	if (!stringp(arg) || arg == "" || arg == " ") arg = "...";

	if( !mapp(channels) || undefinedp(channels[verb]) )
		return 0;

	if( userp(me) ) {
		if(channels[verb]["wiz_only"] && !wizardp(me) )
			return 0;

		if( arg==(string)me->query_temp("last_channel_msg") )
			return notify_fail("用交谈频道说话请不要重复相同的讯息。\n");

		if( userp(me) ) 
			me->set_temp("last_channel_msg", arg);

		// If we speaks something in this channel, then must tune it in.
		tuned_ch = me->query("channels");
		if( !pointerp(tuned_ch) )
			me->set("channels", ({ verb }) );
		else if( member_array(verb, tuned_ch)==-1 )
			me->set("channels", tuned_ch + ({ verb }) );

		// Support of channel emote
		if( emote && !channels[verb]["intermud_emote"]) {
			string vb, emote_arg;

			if( sscanf(arg, "%s %s", vb, emote_arg)!= 2 ) {
				vb = arg;
				emote_arg = "";
			}
			arg = EMOTE_D->do_emote(me, vb, emote_arg, 1);
			if( !arg ) return 0;
		}
	}

	// Make the identity of speaker.

	if( channels[verb]["anonymous"] ) {
		who = channels[verb]["anonymous"];
		if (userp(me))
	        do_channel( this_object(), "sys", sprintf("谣言：%s。", me->name()));
	}
	else if( userp(me) || !stringp(who = me->query("channel_id")) )
		who = me->query("name") + "(" + capitalize(me->query("id")) + ")";

	// Ok, now send the message to those people listening us.

	ob = filter_array( users(), "filter_listener", this_object(), channels[verb] );
	if( !arg || arg == "" || arg == " " ) arg = "...";

	if( emote ) {
		// Support of old behavier of intermud emote.
//		if( channels[verb]["intermud_emote"] ) arg = who + " " + arg;
		if (!stringp(arg)) arg = "";
		message( "channel:" + verb,
			sprintf( channels[verb]["msg_emote"], arg ), ob );
	} else
		message( "channel:" + verb,
			sprintf( channels[verb]["msg_speak"], who, arg ), ob );

	if( arrayp(channels[verb]["extra_listener"]) ) {
		channels[verb]["extra_listener"] -= ({ 0 });
		if( sizeof(channels[verb]["extra_listener"]) )
			channels[verb]["extra_listener"]->relay_channel(me, verb, arg);
	}
	
//	if( !undefinedp(channels[verb]["intermud"])
//	&&	base_name(me) != channels[verb]["intermud"] )
//		channels[verb]["intermud"]->send_msg(
//			channels[verb]["channel"], me->query("id"), me->name(1), arg, 0,
//			channels[verb]["filter"] );

//	if( userp(me) ) 
//		me->set_temp("last_channel_msg", arg);

	return 1;
}

int filter_listener(object ppl, mapping ch)
{
	// Don't bother those in the login limbo.
	if( !environment(ppl) ) return 0;
	
	if( ch["wiz_only"] ) return wizardp(ppl);
	return 1;
}

void register_relay_channel(string channel)
{
	object ob;

	ob = previous_object();
	if( undefinedp(channels[channel]) || !ob) return;
	if( arrayp(channels[channel]["extra_listener"]) ) {
		if( member_array(ob, channels[channel]["extra_listener"]) >=0 ) return;
		channels[channel]["extra_listener"] += ({ ob });
	} else
		channels[channel]["extra_listener"] = ({ ob });
}
void add_relay_channel( object ob , string channel)
{
	if( undefinedp(channels[channel]) || !ob) return;
	if( arrayp(channels[channel]["extra_listener"]) ) {
		if( member_array(ob, channels[channel]["extra_listener"]) >=0 ) return;
		channels[channel]["extra_listener"] += ({ ob });
	} else
		channels[channel]["extra_listener"] = ({ ob });
}
int set_block(string channel, int d)
{
//	write("debug:  "+channel+" d="+sprintf("%d\n", d)); 
	if (channel == "rumor") block_rumor = d;
	if (channel == "chat") block_chat = d;
	return 1;
}

