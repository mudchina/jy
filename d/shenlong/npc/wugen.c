#include <ansi.h>
inherit NPC;

int ask_gao();

void create()
{
	set_name("无根道长", ( { "wugen daozhang", "wugen","daozhang" }) );
	set("title", "神龙教赤龙使");
	set("gender", "男性" );
	set("age", 55);
	set("long",
	      "这是个五十来岁的黑须道长,相貌威武,眼中略带杀气。\n"
	     );

	set("int", 30);
	set("str", 25);
	set("con", 25);
	set("dex", 25);

	set("qi", 2000);
	set("max_qi", 2000);
	set("jing", 500);
	set("max_jing", 500);
	set("neili", 1000);
	set("max_neili", 1000);
	set("jiali", 100);
	set("combat_exp", 250000);
	set("score", 15000);
	set_temp("apply/attack", 60);
	set_temp("apply/defense", 60);
	set_temp("apply/damage", 40);

	set_skill("huashan-zhangfa", 60);
	set_skill("unarmed",90);
	set_skill("force", 90);
	set_skill("zixia-shengong", 80);
	set_skill("dodge", 90);
	set_skill("parry", 90);
	set_skill("sword", 100);
	set_skill("huashan-jianfa", 90);
	set_skill("huashan-shenfa",80);
	set_skill("literate", 80);
	map_skill("force", "zixia-shengong");
	map_skill("unarmed", "huashan-zhangfa");
	map_skill("dodge", "huashan-shenfa");
	map_skill("parry", "huashan-jianfa");
	map_skill("sword", "huashan-jianfa");


       set("inquiry", ([
		"神龙教" :  "\n一般人是入不了我神龙教的(join shenlongjiao).\n",
		"洪安通" :  "\n教主脾气不好,要讨他欢心才好。\n",
		"教主" :  "\n教主脾气不好,要讨他欢心才好。\n",
		"入教" :  "\n一般人是入不了我神龙教的(join shenlongjiao).\n",
		"口号" : "\n万年不老!永享仙福!寿与天齐!文武仁圣!\n",
	]));
	setup();
        carry_object("/d/city/obj/duanjian")->wield();
	add_money("silver",10);
}

int recognize_apprentice(object ob)
{
    if (!ob->query("shenlongjiao"))
    {
    message_vision("$N摇了摇头。\n",this_object());
    command("tell "+ob->query("id")+"你我素不相识，我赁什么要教你呢？ \n"); 
    return 0;
    }
    return 1;	
}

int do_skills(string arg)
{
   object ob ;
   ob = this_player () ;
    if( !arg || (arg!="wugen"&&arg!="daozhang"))
     return 0;
   if(wizardp(ob)) return 0;
  if (!ob->query("shenlongjiao"))
  {
   message_vision("$N摇了摇头。\n",this_object());
   write("无根道长说道：你怎么能看我的武功呢？\n");
   return 1;
  }
   command("tell "+ob->query("id")+" 我所有的武功如下：\n"+
"  基本轻功 (dodge)                         - 一代宗师  90/    \n"+
"  基本内功 (force)                         - 一代宗师  90/    \n"+
"□华山剑法 (huashan-jianfa)                - 一代宗师  90/    \n"+
"□华山身法 (huashan-shenfa)                - 登峰造极  80/    \n"+
"□华山掌法 (huashan-zhangfa)               - 神乎其技  60/    \n"+
"  读书写字 (literate)                      - 举世无双  80/    \n"+
"  基本招架 (parry)                         - 一代宗师  90/    \n"+
"  基本剑法 (sword)                         - 深不可测 100/    \n"+
"  基本拳脚 (unarmed)                       - 一代宗师  90/    \n"+
"□紫霞神功 (zixia-shengong)                - 登峰造极  80/    \n");
 return 1;
}

int do_join(string arg)
{
   object ob ;
   ob = this_player () ;
   if( !arg || arg!="shenlongjiao" )
	return notify_fail("你要加入什么组织？\n"); 
   if(ob->query("shenlongjiao")) 
	{
	message_vision(HIC "无根道长说道：你已经是神龙教弟子了。\n" NOR,this_player());
	return 1;
	}
   if ((int)ob->query("shen")>-1000)
        {
	message_vision(HIC "无根道长对$N大怒道：还想入教?一看你就不是好人!\n" NOR,this_player());
	set_leader(this_player());
	remove_call_out("kill_ob");
	call_out("kill_ob", 1, this_player()); 
  	return 1;
	}
   if (ob->query("combat_exp")<20000)
        {
	message_vision(HIC "无根道长对$N摇头道：你的实战经验太低。\n" NOR,this_player());
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
   message_vision(HIC "无根道长对$N大怒道：还想入教?一看你就不是好人!\n" NOR,this_player());
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
	   set("combat_exp",100000);
	   set("qi",100);
	   set("jing",100);
	}
	return;
}
