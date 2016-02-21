// gaoyanchao.c 高彦超

#include <ansi.h>

inherit NPC;
inherit F_UNIQUE;
inherit F_MASTER;
int ask_weiwang();
int do_skills(string arg);

void create()
{
	set_name("高彦超", ({ "gao yanchao", "gao", "yanchao" }));
	set("gender", "男性");
	set("age", 32);
	set("str", 25);
	set("dex", 20);
	set("long", "他不过三十出头，却显得异常老练。一言不发地往那儿一站，\n"
            "真是威风凛凛。\n");
	set("combat_exp", 40000);
	set("score", 5000);
	set("shen_type", 1);
	set("attitude", "peaceful");

	set_skill("force", 70);
	set_skill("unarmed", 70);
	set_skill("dodge", 70);
	set_skill("club", 80);
	set_skill("parry", 70);
	set_skill("literate", 50);
	set_skill("hunyuan-yiqi", 60);
	set_skill("shaolin-shenfa", 60);
	set_skill("zui-gun", 70);

	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("club", "zui-gun");
	map_skill("parry", "zui-gun");



	set_temp("apply/attack", 25);
	set_temp("apply/defense", 25);
	set_temp("apply/armor", 5);
	set_temp("apply/damage", 25);
	set("qi", 400);
	set("max_qi", 400);
	set("jing", 300);
	set("max_jing", 300);
	set("neili", 250); 
	set("max_neili", 250);
	set("jiali", 35);
        set("inquiry", ([
		"陈近南" :  "\n想见总舵主可不容易啊。\n",
		"天地会" :  "\n只要是英雄好汉，都可以入我天地会(join tiandihui)。\n",
		"入会" :  "\n只要入了我天地会，可以向会中各位好手学武艺。\n",
                "反清复明" : "去棺材店内室仔细瞧瞧吧！\n",
                "暗号" : "敲三下！\n",
                "切口" : "敲三下！\n",
                "威望" :  (: ask_weiwang :),
                "江湖威望" : (: ask_weiwang :),
       ]) );
	setup();
        carry_object("/d/shaolin/obj/qimeigun")->wield();
	carry_object("/clone/misc/cloth")->wear();
	add_money("gold", 1);
}

int ask_weiwang()
{
command("tell "+this_player()->query("id")+" 你现在的江湖威望是 " +(string)(this_player()->query("weiwang")));
say("\n高彦超说道：如果你威望值很高，有些人见了你不但不会杀你，还会教你武功，送你宝贝。\n"
+"而且你还可以加入帮会，率领会众去攻打目标，就连去钱庄取钱也会有利息 。。。。。\n");
say("高彦超又说：杀某些坏人或救某些好人可以提高江湖威望。\n");
return 1;
}

void init()
{
::init();
add_action("do_skills","skills");
add_action("do_skills","cha");
add_action("do_join","join");
}

int recognize_apprentice(object ob)
{
    if (ob->query("weiwang")<50)
    {
    message_vision("$N摇了摇头。\n",this_object());
    command("tell "+ob->query("id")+" 不是天地会弟子我不教。\n"); 
    return 0;
    }
	return 1;
}

int do_skills(string arg)
{
   object ob ;
   ob = this_player () ;
    if( !arg || arg!="gao" )
     return 0;
   if(wizardp(ob))    return 0;
  if (ob->query("weiwang")<50)
  {
   message_vision("$N摇了摇头。\n",this_object());
   command("tell "+ob->query("id")+" 不是天地会弟子不能察看。\n"); 
   return 1;
   }

   command("tell "+ob->query("id")+" 我所有的武功如下：\n"+
"  基本棍法 (club)                          - 登峰造极  80/    \n"+
"  基本轻功 (dodge)                         - 出神入化  70/    \n"+
"  基本内功 (force)                         - 出神入化  70/    \n"+
"□混元一气功 (hunyuan-yiqi)                - 神乎其技  60/    \n"+
"  读书写字 (literate)                      - 心领神会  50/    \n"+
"  基本招架 (parry)                         - 出神入化  70/    \n"+
"□少林身法 (shaolin-shenfa)                - 神乎其技  60/    \n"+
"  基本拳脚 (unarmed)                       - 出神入化  70/    \n"+
"□少林醉棍 (zui-gun)                       - 出神入化  70/    \n");
return 1;
}

int do_join(string arg)
{
   object ob ;
   ob = this_player () ;
   if( !arg || arg!="tiandihui" )
	return notify_fail("你要加入什么组织？\n"); 
   if (ob->query("weiwang")<20)
        {
	command("tell "+this_player()->query("id")+" 你现在的江湖威望是 " +(string)(this_player()->query("weiwang")));
	message_vision(HIC "高彦超对$N摇了摇头说：你的江湖威望值太低。\n" NOR,this_player());
	return 1;
  	}
   if (ob->query("combat_exp")<20000)
        {
	message_vision(HIC "高彦超对$N摇了摇头说：你的实战经验太低。\n" NOR,this_player());
  	return 1;
  	}
   if(ob->query("weiwang")<50)
   {
    ob->set("weiwang",50);
    message_vision(HIC "$N的江湖威望提高了！\n" NOR,this_player());
    command("tell "+this_player()->query("id")+" 你现在的江湖威望是 " +(string)(this_player()->query("weiwang")));
    return 1;	
   }
   else message_vision(HIC "高彦超对$N摇了摇头说：你已经入过天地会了。\n" NOR,this_player());
   return 1;
}
