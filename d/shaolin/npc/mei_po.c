// mei_po.c
#include <ansi.h>

inherit NPC;
inherit F_CLEAN_UP;

string marry();
string unmarry();

void create()
{
        set_name("媒婆", ({ "mei_po" }) );
        set("title", "红娘");
        set("gender", "女性" );
        set("age", 43);
        set("long",
                "一位精明能干的老媒婆\n");
        set("combat_exp", 100000);
        set("attitude", "friendly");
        set("inquiry", ([
                "婚约" : "是啊... 这里就可以缔结和解除婚约",
        ]) );
        set_skill("literate", 100);
        set_skill("dodge", 500);
        set_skill("unarmed", 300);
        setup();
        add_money("gold", 5);
	  carry_object("d/city/obj/cloth")->wear();
}

void init()
{
        object ob;

        ::init();

        add_action("do_marry", "marry");
        add_action("do_unmarry", "unmarry");
        add_action("do_name","拜");
}

int do_marry(string arg)
{
	object obj, me, old_target;

	me = this_player();

	if ( (string)me->query("gender") == "无性")
		return notify_fail("你无根无性，阴阳不调！\n");

	if (((int)me->query("age") < 18) && (me->query("gender") == "男性")
		||((int)me->query("age") < 16) && (me->query("gender") == "女性"))
		return notify_fail("你现在还年轻，以后再说吧！\n");

	if (me->is_busy())
		return notify_fail("媒婆说道：你现在正忙着呢。\n");

	if( me->is_fighting(this_object()) )
	{
		if( !this_object()->is_killing(me) )
			this_object()->kill_ob(me); 
		return notify_fail("媒婆说道：老娘送你去阴间成婚！\n"); 
	}

	if( this_object()->is_fighting() )
		return notify_fail("媒婆说道：没看见这儿有人捣乱吗！\n");

	if( !living(this_object()) )
		return notify_fail("你还是先想办法把媒婆救醒吧。\n"); 

	if( me->is_fighting() )
		return notify_fail("媒婆说道：嘿嘿，你先还是料理完你的朋友再说吧！\n");

	if( !environment() || base_name(environment()) != query("startroom"))
		return notify_fail("媒婆说道：真是抱歉，请您等一下到红娘庄来找我吧。\n");

	if( (string)me->query("class")=="bonze" ) 
		return notify_fail("媒婆笑道：哈哈！怎么，和尚也想开色戒了吗?\n");

	if(!arg || !objectp(obj = present(arg, environment(me)))
		|| !find_player(arg) )
		return notify_fail("媒婆说道：你想和谁喜结良缘？\n");

	if( me->query_temp("pending/pro") )
		return notify_fail("媒婆说道：你的婚礼正在进行中。\n");

	if( obj->query_temp("pending/pro") )
		return notify_fail("媒婆说道：你想给别人搅局吗？\n");

	if( !obj->is_character() )
		return notify_fail("媒婆说道：你这不是拿自己开涮吗。\n");

	if( (string)obj->query("class")=="bonze" ) 
		return notify_fail(
                "媒婆笑道：哈哈！人家可是出家人，别跟人家开玩笑了。\n");

	if( mapp( me->query("couple") ) )
	{
		if ( me->query("couple/have_couple") )
		{
			if ( obj == present((string)me->query("couple/couple_id"), environment(me)) )
				return notify_fail("媒婆说道：你们本来就是夫妻呀！\n");
			if ((string)me->query("gender") == "女性") 
				return notify_fail("媒婆说道：你已经是有夫之妇了，这里不允许重婚的。\n");
			else
				return notify_fail("媒婆说道：你已经是有妇之夫了，这里不允许重婚的。\n");
		}
	}

	if( mapp( obj->query("couple") ) )
	{
        	if( obj->query("couple/have_couple") )
		{
			if((string)obj->query("gender") == "女性") 
				return notify_fail(
                    "媒婆说道：可惜她已经是有夫之妇了，这里不允许重婚的。\n");
			else
				return notify_fail(
                    "媒婆说道：可惜他已经是有妇之夫了，这里不允许重婚的。\n");
		}
	}

	if( !living(obj) )
		return notify_fail("媒婆说道：" + obj->name() + "无法和你共结连理。\n"); 

	if((string)obj->query("gender") == (string)me->query("gender"))
		return notify_fail("媒婆说道：你不怕" + RED"AIDS"NOR + "吗？\n");

	if(obj == me)
		return notify_fail("媒婆说道：你这不是拿自己开涮吗。\n");

	if( !userp(obj) )
		return notify_fail("媒婆说道：对不起，你只能娶玩家。\n");

	if( (object)obj->query_temp("pending/marry")!=me )
	{
		if ((string)obj->query("gender") == "女性") 
			message_vision(MAG "\n$N对著$n说道：你愿意嫁给我吗？\n\n"NOR, me,obj);
		else
			message_vision(MAG "\n$N对著$n说道：你愿意娶我吗？\n\n"NOR, me,obj);

		if( objectp(old_target = me->query_temp("pending/marry")) && old_target != obj )
			tell_object(old_target, YEL + me->name() + 
                        "取消了和你结婚的念头。\n" NOR);
           
		me->set_temp("pending/marry", obj);

		if ((string)obj->query("gender") == "女性") 
			tell_object(obj, MAG "如果你愿意嫁给他，请你也对" + me->name()
			+ "("+(string)me->query("id") + ")"+ "下一次 marry 指令。\n" NOR);
		else
			tell_object(obj, MAG "如果你愿意娶她，请你也对" + me->name() + 
			"("+(string)me->query("id") + ")"+ "下一次 marry 指令。\n" NOR);

                write(MAG  
                        "现在你急切盼望着你的心上人说同意...\n" NOR);
                return 1;
	}

	message_vision(MAG "\n$N对著$n说道：我愿意！\n\n"NOR, me,obj);           
	message_vision(MAG "媒婆说道：$N和$n，现在开始拜堂啦! \n" NOR, obj, me);
	message_vision(MAG "媒婆说道：我来作你们的主婚人。\n\n" NOR,obj, me);
	message_vision(MAG "媒婆喊道：拜 天地喽！\n" NOR,obj, me);

	me->set_temp("pending/pro", 1);
	obj->set_temp("pending/pro", 1);

	me->set("couple/couple_name",(string)obj->name());
	me->set("couple/couple_id",obj->query("id"));

	obj->set("couple/couple_name",(string)me->name());
	obj->set("couple/couple_id",me->query("id"));

	if ((string)obj->query("gender") == "女性")
	{
		me->set("couple/couple_gender", "妻子");
		obj->set("couple/couple_gender", "丈夫");
	}
	else
	{
		obj->set("couple/couple_gender", "妻子");
		me->set("couple/couple_gender", "丈夫");
	}
          
	return 1;
}

int do_unmarry(string arg)
{
	object me, obj;

	me = this_player();       

	if (me->is_busy())
		return notify_fail("媒婆说道：你现在正忙着呢。\n");

	if( me->is_fighting(this_object()) )
	{
		if( !this_object()->is_killing(me) )
			this_object()->kill_ob(me); 
		return notify_fail("媒婆说道：老娘先送你去阴间！\n");
	}

	if( this_object()->is_fighting() )
		return notify_fail("媒婆说道：没看见这儿有人捣乱吗！\n");

	if( !living(this_object()) )
		return notify_fail("你还是先想办法把媒婆救醒吧。\n"); 

	if( me->is_fighting() )
		return notify_fail("媒婆说道：嘿嘿，你先还是料理完你的朋友再说吧！\n");

	if( !environment()||base_name(environment()) != query("startroom") )
		return notify_fail("媒婆说道：真是抱歉，请您等一下到红娘庄来找我吧。\n");

	if( !mapp( me->query("couple") ) || !me->query("couple/have_couple") ) 
	{
		if ((string)me->query("gender") == "女性") 
			return notify_fail("媒婆说道：你还未有丈夫啊。\n");
		else
			return notify_fail("媒婆说道：你还未有妻子啊。\n");
	}

	if( !objectp(obj = present((string)me->query("couple/couple_id"), environment(me)))
                 || !find_player(me->query("couple/couple_id")) )
		return notify_fail("媒婆说道：你的伴侣现在不在场。\n");
	if( (object)obj->query_temp("pending/unmarry")!=me )
	{
		message_vision(MAG "\n$N对著$n说道：对不起，不是我不爱你，只是... 咱们好聚好散，好吗?
\n\n"NOR, me,obj);           
		me->set_temp("pending/unmarry", obj);

		if ((string)obj->query("gender") == "女性") 
			tell_object(obj, MAG "如果你不爱他了，请你也对" 
                       	+me->name() + "("+(string)me->query("id")+
                       	")"+ "下一次 unmarry 指令。\n" NOR);
		else
			tell_object(obj, MAG "如果你不爱她了，请你也对" 
                       	+me->name() + "("+(string)me->query("id")+
                       	")"+ "下一次 unmarry 指令。\n" NOR);

		write(MAG "现在你正等待着你的伴侣的回答...\n" NOR);
		return 1;
	}
       
	message_vision(MAG "\n$N对著$n说道：既然无缘，咱们就各走各的路吧。\n\n"NOR, me,obj);           
	message_vision(MAG "媒婆说道：$N和$n，现在开始不是夫妇啦! \n" NOR, obj, me);

	CHANNEL_D->do_channel(this_object(), "chat",
	sprintf( "可惜%s和%s，一对璧人劳燕分飞... 但愿爱相随。\n", me->name(), obj->name()));
        
	me->add("unmarried", 1);
	me->set("couple/have_couple",0);

	obj->add("unmarried", 1);
	obj->set("couple/have_couple",0);

	return 1;
}

int do_name(string arg)
{
	object me, obj;
	string act;

	me = this_player();       

	if (me->is_busy())
		return notify_fail("媒婆说道：你现在正忙着呢。\n");

	if( me->is_fighting(this_object()) )
	{
		if( !this_object()->is_killing(me) )
			this_object()->kill_ob(me); 
		return notify_fail("媒婆说道：老娘送你去阴间成婚！\n");
	}

	if( this_object()->is_fighting() )
		return notify_fail("媒婆说道：没看见这儿有人搅局吗！\n");

	if( !living(this_object()) )
		return notify_fail("你还是先想办法把媒婆救醒吧。\n"); 

	if( me->is_fighting() )
		return notify_fail("媒婆说道：嘿嘿，你先还是料理完你的朋友再说吧！\n");

	if( !environment()||base_name(environment()) != query("startroom") )
		return notify_fail("媒婆说道：真是抱歉，请您等一下到红娘庄来找我吧。\n");

	if( !me->query_temp("pending/pro") )
		return notify_fail("媒婆笑道：哈哈，你犯什么傻呀！\n");

	if( !objectp(obj = present((string)me->query("couple/couple_id"), environment(me)))
		|| !find_player(me->query("couple/couple_id")) )
		return notify_fail("媒婆说道：你的爱人现在离开了，婚礼只好中断。\n");

	if(!arg && !(me->query_temp("pending/pro")==1 && arg=="天地")
		&& !(me->query_temp("pending/pro")==2 && arg=="高堂")
		&& !(me->query_temp("pending/pro")==3 && arg==(string)me->query("couple/couple_name")))
		return notify_fail("媒婆笑道：你乱拜什么呀？\n");

	obj->set_temp("pending/pro", me->query_temp("pending/pro"));
	{
		if( (string)obj->query_temp("pending/act")!=arg )
		{
			tell_object(obj, MAG"你的伴侣正等着和你拜" + arg + "呢...\n" NOR);
			write(MAG "现在你正等待着你的伴侣...\n" NOR);
			me->set_temp("pending/act", arg);
			return 1;
		}
	}
       
	message_vision(MAG "媒婆说道：$N和$n，现在是夫妻啦! \n" NOR, obj, me);
	CHANNEL_D->do_channel(this_object(), "chat",
		sprintf( "恭喜%s和%s，一对璧人喜结良缘。\n", me->name(), obj->name()));
        
	me->add("married", 1);
	me->set("couple/have_couple",1);
	obj->add("married", 1);
	obj->set("couple/have_couple",1);

	me->set_temp("pending/pro", 0);
	obj->set_temp("pending/pro", 0);
	
	return 1;
}