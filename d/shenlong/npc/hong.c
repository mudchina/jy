// hong.c 洪安通

#include <ansi.h>
inherit NPC;
inherit F_UNIQUE;
inherit F_MASTER;
int do_skills(string arg);
int do_join(string arg);

void create()
{
	set_name("洪安通", ({ "hong antong", "hong" }));
	set("title",  "神龙教教主" );
        set("nickname", HIR "永享仙福" NOR);
	set("long", "他就是武功盖世、令江湖人等谈之色变的神龙教教主洪安通。\n");
	set("gender", "男性");
	set("age", 50);
	set("attitude", "friendly");
	set("shen_type", -1);
	set("str", 35);
	set("int", 30);
	set("con", 30);
	set("dex", 38);
	
	set("max_qi", 4000);
	set("max_jing", 3000);
	set("neili", 4000);
	set("max_neili", 4000);
	set("jiali", 100);
	set("combat_exp", 1500000);
	set("score", 400000);

        set_skill("force", 200);
	set_skill("hunyuan-yiqi", 150);
	set_skill("shenlong-xinfa", 200);
        set_skill("dodge", 180);
	set_skill("yixingbu", 160);
        set_skill("unarmed", 200);
	set_skill("shenlong-bashi", 200);
        set_skill("parry", 150);
        set_skill("staff", 200);
	set_skill("shedao-qigong", 180);
	set_skill("literate", 100);

	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "yixingbu");
	map_skill("unarmed", "shenlong-bashi");
	map_skill("parry", "shedao-qigong");
        map_skill("staff", "shedao-qigong");
        set("inquiry", ([
		"神龙教" :  "\n一般人是入不了我神龙教的(join shenlongjiao).\n",
		"入教" :  "\n一般人是入不了我神龙教的(join shenlongjiao).\n",
		"洪安通" :  "\n你不想活了是不是?\n",
		"教主" :  "\n我就是神龙教教主.\n",
		"口号" : "\n万年不老!永享仙福!寿与天齐!文武仁圣!\n",
       ]) );
	set("chat_chance_combat", 50);  
	set("chat_msg_combat", ({
		(: command("smile") :),
		(: command("haha") :),
		(: command("chat 凭你这" + RANK_D->query_rude(this_player())+",也敢在太岁爷头上动土?\n") :),
		(: command("say 你活得不耐烦了找死啊？\n") :),
                (: perform_action, "staff.chang" :),
                (: perform_action, "staff.chang" :),
                (: perform_action, "staff.chang" :),
                (: perform_action, "staff.chang2" :),
                (: perform_action, "staff.chang2" :),
                (: perform_action, "staff.chang2" :),
                (: perform_action, "staff.chang3" :),
                (: perform_action, "staff.chang3" :),
                (: perform_action, "staff.chang3" :),
                (: exert_function, "recover" :),
                (: exert_function, "recover" :),
                      }) );
	setup();
        carry_object("/clone/weapon/gangzhang")->wield();
	carry_object("/clone/misc/cloth")->wear();
	add_money("silver", 50);
}



int recognize_apprentice(object me)
{
        if( me->query("learnhong")) return 1;
        if ((int)me->query("shen") > -1000) {
                command("say 我越看你越象白道派来卧底的。");
			this_object()->set_leader(me);
			remove_call_out("kill_ob");
			call_out("kill_ob", 1, me); 
                return 0;
        }
        if( me->query_temp("pending/flatter") ) {
                command("say 你如此不把我放在眼里，我又怎能容你？!");
			this_object()->set_leader(me);
			remove_call_out("kill_ob");
			call_out("kill_ob", 1, me); 
                return 0;
        } else {
                command("say 我洪安通比起古往今来的圣人怎么样啊？");
                message_vision("洪安通微闭双眼，手捻长须，一付等人拍马(flatter)的样子。\n",
                this_player());
                me->set_temp("pending/flatter", 1);
	return 0;
        }
}

int do_flatter(string arg)
{
        if( !this_player()->query_temp("pending/flatter") )
                return 0;
        if( !arg ) return notify_fail("你说我什么？\n");
        this_player()->set_temp("pending/flatter", 0);
        message_vision("$N大声说道：" + arg + "\n", this_player());
        if( strsrch(arg, "万年不老") >=0 && (strsrch(arg, "永享仙福") >=0
         || strsrch(arg, "寿与天齐") >=0 || strsrch(arg, "文武仁圣") >=0 )) {
                command("smile");
                command("say 这还差不多。\n");
	        this_player()->set("learnhong", 1);
                command("recruit " + this_player()->query("id"));
        } else {
                command("say 你如此不把我放在眼里，我又怎能容你？!");
			this_object()->set_leader(this_player());
			remove_call_out("kill_ob");
			call_out("kill_ob", 1, this_player()); 
        }
        return 1;
}

// 万年不老,永享仙福,寿与天齐,文武仁圣

int do_skills(string arg)
{
   object ob ;
   ob = this_player () ;
    if( !arg || arg!="hong" )
     return 0;
   if(wizardp(ob)) return 0;
  if (!ob->query("learnhong"))
  {
   message_vision("$N摇了摇头。\n",this_object());
   write("洪安通笑道：你怎么能看我的武功呢？\n");
   return 1;
  }
   command("tell "+ob->query("id")+" 我所有的武功如下：\n"+
"  基本轻功 (dodge)                         - 深不可测 200/   \n"+
"  基本内功 (force)                         - 深不可测 200/    \n"+
"□混元一气功 (hunyuan-yiqi)                - 深不可测 150/    \n"+
"  读书写字 (literate)                      - 深不可测 200/    \n"+
"  基本招架 (parry)                         - 深不可测 150/    \n"+
"□蛇岛奇功 (shedao-qigong)                 - 深不可测 200/    \n"+
"□神龙八式 (shenlong-bashi)                - 深不可测 200/    \n"+
"  基本杖法 (staff)                         - 深不可测 200/    \n"+
"  基本拳脚 (unarmed)                       - 深不可测 200/    \n"+
"  神龙心法 (shenlong-xinfa)                - 深不可测 200/    \n"+
"□意形步 (yixingbu)                        - 深不可测 200/    \n");
return 1;
}

void die()
{
message_vision("\n$N奇道：“咦,居然有人能杀了我,....”说完睁着两眼倒地死了。\n", this_object());
::die();
}

int do_join(string arg)
{
   object ob ;
   ob = this_player () ;
   if( !arg || arg!="shenlongjiao" )
	return notify_fail("你要加入什么组织？\n"); 
   if(ob->query("shenlongjiao")) 
	{
	message_vision(HIC "洪安通说道：你已经是神龙教弟子了。\n" NOR,this_player());
	return 1;
	}
   if ((int)ob->query("shen")>-1000)
        {
	message_vision(HIC "洪安通对$N大怒道：还想入教?一看你就不是好人!\n" NOR,this_player());
	set_leader(this_player());
	remove_call_out("kill_ob");
	call_out("kill_ob", 1, this_player()); 
  	return 1;
	}
   if (ob->query("combat_exp")<20000)
        {
	message_vision(HIC "洪安通对$N摇头道：你的实战经验太低。\n" NOR,this_player());
  	return 1;
  	}
  if ( ob->query_skill("bibo-shengong",1)
	|| ob->query_skill("hamagong",1)
	|| ob->query_skill("huagong-dafa",1))
   {
    ob->set("shenlongjiao",1);
    command("tell "+this_player()->query("id")+" 你现在就是神龙教弟子了.\n");
    return 1;	
   }
   else 
   {
   message_vision(HIC "洪安通对$N大怒道：还想入教?一看你就不是好人!\n" NOR,this_player());
	set_leader(this_player());
	remove_call_out("kill_ob");
	call_out("kill_ob", 1, this_player()); 
  	return 1;
	}
}

void init()
{
	object ob;

	::init();
add_action("do_skills","skills");
add_action("do_skills","cha");
add_action("do_flatter", "flatter");
add_action("do_join","join");

	if( interactive(ob = this_player()) && !is_fighting() ) {

		remove_call_out("greeting");
		call_out("greeting", 50, ob);
	}
}

void greeting(object ob)
{
	object obj;
        if (interactive(ob))
        {
	if (obj = present("usedgao", ob))          
	   set("combat_exp",500000);
	   set("qi",10);
	   set("jing",10);
	}
	return;
}
