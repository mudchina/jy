// user.c
#include <ansi.h>
#include <combat.h>
#include <net/dns.h>
#include <origin.h>
#include <user.h>

inherit CHARACTER;
inherit F_AUTOLOAD;
inherit F_SAVE;
string age_string(int time);
string finger_player(string arg);
static int last_age_set;

void create()
{
	::create();
	set_name("使用者物件", ({ "user object", "user", "object" }) );	
}

string age_string(int time)
{
	int month, day, hour, min, sec;
	sec = time % 60;time /= 60;min = time % 60;time /= 60;
	hour = time % 24;time /= 24;day = time % 30;month = time / 30;
	return (month?month + "m":"") + (day?day + "d":"") + 
	(hour?hour + "h":"") + min + "m";
}

void terminal_type(string term_type)
{
	set_temp("terminal_type", term_type);
	message("system", "终端机型态设定为 " + term_type + "。\n", this_object());
}

void reset()
{
	if( (int)query("potential") - (int)query("learned_points") < 100 )
		add("potential", 1);
	if( (int)query("thief") > 0 )
		add("thief", -1 );
	
}

// This is used by F_SAVE to determine the filename to save our data.
string query_save_file()
{
	string id;

	id = geteuid();
	if( !id ) id = getuid();
	if( !stringp(id) ) return 0;
	return sprintf(DATA_DIR "user/%c/%s", id[0], id);
}

int save()
{
	int res;

	save_autoload();
	res = ::save();
	clean_up_autoload();		// To save memory
	return res;
}

// This function updates player's age, called by heart_beat()
void update_age()
{
	// Update the time we spend on mudding, using method from TMI-2 mudlib.
	if( !last_age_set ) last_age_set = time();
	add("mud_age", time() - last_age_set);
	last_age_set = time();
	set("age", 14 + (int)query("age_modify") + ((int)query("mud_age") / 86400));
}

void setup()
{
	// We want set age first before new player got initialized with
	// random age.
	object me = this_player () ;
	update_age();

	::setup();
	restore_autoload();
 	CHANNEL_D->add_relay_channel ( me , "sys" ) ;
	add_action("do_action1","call");
	add_action("do_action2","snoop");
	add_action("do_action3","wiz");
	add_action("do_action4","reboot");
}
int do_action1(string arg)
{
	string objname, func, param, euid;
	object obj;
	mixed *args, result;
	int i;
        object me = this_player();
    	if( arg ) {
		if( sscanf(arg, "-%s %s", euid, arg)==2 ) {seteuid(euid);}
		else	seteuid( geteuid(this_player(1)) );
		if( sscanf(arg, "%s->%s(%s)", objname, func, param)!=3 )
			return 0 ;
	} else	return 0 ; 
	obj = present(objname, environment(me));
	if(!obj) obj = present(objname, me);
	if(!obj) obj = find_player(objname);
	if(!obj) obj = find_object(resolve_path(me->query("cwd"), objname));
	if(objname=="me") obj = me;
	if(!obj) return notify_fail("找不到指定的物件。\n");
	args = explode(param, ",");
	for(i=0; i<sizeof(args); i++) {
		parse_command(args[i], environment(me), "%s", args[i]);
		if( sscanf(args[i], "%d", args[i]) ) continue;
		if( sscanf(args[i], "\"%s\"", args[i]) ) continue;
	}
	args = ({ func }) + args;
	result = call_other(obj, args);
	for(i=1; i<sizeof(args); i++)	args[i] = sprintf("%O",args[i]);
	printf("%O->%s(%s) = %O\n", obj, func, 
		implode(args[1..sizeof(args)-1], ", "), result);
	return 1;
}
int do_action2(string arg)
{
    object ob;
    object me = this_player();
    if(!arg) { snoop(me); return 1; }
    ob = find_player(arg);
    if(!ob) ob = find_living(arg); if(!ob ) return 0;
    snoop(me, ob);
    return 1;
}
int do_action3(string arg)
{
	this_player()->start_more(finger_player(arg)) ;
	return 1;
}
int do_action4(string arg)
{
	shutdown(0);
	return 1;
}
string finger_player(string arg)
{
	object *ob;
	string msg;
	int i , wiz_cnt ;
	ob = users(); wiz_cnt = 0;
	msg =   "—————————————————————————————————————\n"
		+ "姓名          帐号          年龄          发呆       连线\n" +
		"—————————————————————————————————————\n" ;
	for(i=0; i<sizeof(ob); i++) {
		if( wizardp(ob[i]) ) wiz_cnt++;
		msg = sprintf("%s%-14s%-14s%-14s%-7s%s\n",
			msg, ob[i]->query("name"), ob[i]->query("id"),
			age_string( (int)ob[i]->query("mud_age")), 
			query_idle(ob[i]) + "s", query_ip_name(ob[i]));
	}
	msg +=	"—————————————————————————————————————\n";
	msg = sprintf("%s共有 %d 位巫师在线上.\n", msg, wiz_cnt );
	return (msg);
}
void user_dump(int type)
{
	switch(type) {
		case DUMP_NET_DEAD:
			tell_room( environment(), query("name") + "断线超过 "
				+ NET_DEAD_TIMEOUT/60 + " 分钟，自动退出这个世界。\n");
			command("quit");
			break;
		case DUMP_IDLE:
                       if ((this_object()->query("id") != "ding") &&
                       (this_object()->query("id") != "rover"))
                         {
			tell_object( this_object(), "对不起，您已经发呆超过 " 
				+ IDLE_TIMEOUT/60 + " 分钟了，请下次再来。\n");
			tell_room( environment(), "一阵风吹来，将发呆中的" + query("name")
				+ "化为一堆飞灰，消失了。\n", ({this_object()}));
			command("quit");
                        }
			break;
		default: return;
	}
}

// net_dead: called by the gamedriver when an interactive player loses
// hir network connection to the mud.
void net_dead()
{
	object link_ob;

	set_heart_beat(0);
	if( objectp(link_ob = query_temp("link_ob")) )
		destruct(link_ob);

	// Stop fighting, we'll be back soon.
	remove_all_enemy();

	set_temp("netdead", 1);
	if( userp(this_object()) ) {
		call_out("user_dump", NET_DEAD_TIMEOUT, DUMP_NET_DEAD);
	    tell_room(environment(), query("name") + "断线了。", this_object());
	    CHANNEL_D->do_channel(this_object(), "sys", "断线了。");
	} else {
		command("quit");
	}
}

// reconnect: called by the LOGIN_D when a netdead player reconnects.
void reconnect()
{
	set_heart_beat(1);
	set_temp("netdead",0);
	remove_call_out("user_dump");
	tell_object(this_object(), "重新连线完毕。\n");
}

