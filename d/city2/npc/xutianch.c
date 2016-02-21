// xutianch.c 徐天川

#include <ansi.h>
inherit NPC;
inherit F_UNIQUE;
int ask_weiwang();
int do_skills(string arg);

void create()
{
	set_name("徐天川", ({ "xu tianchuan", "xu", "tianchuan" }));
	set("title", "天地会青木堂护法");
	set("nickname", "八臂猿猴");
	set("gender", "男性");
	set("long", "\n他是青木堂数一数二的好手，手上功夫十分了得，尤其擅使一套猴拳。\n");
	set("age", 55);

	set("int", 30);
	
	set("qi", 500);
	set("max_qi", 500);
	set("jing", 500);
	set("max_jing", 500);
	set("shen_type", 1);

	set("combat_exp", 75000);
	set("attitude", "friendly");

	set_skill("force", 70);
	set_skill("dodge", 70);
	set_skill("parry", 90);
	set_skill("unarmed", 90);
	set_skill("hand", 100);
	set_skill("hunyuan-yiqi", 70);
	set_skill("shaolin-shenfa", 70);
	set_skill("houquan", 100);

	set_temp("apply/attack", 50);
	set_temp("apply/defense", 50);
	set_temp("apply/damage", 35);
	set("env/wimpy", 50);

	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("hand", "houquan");
	map_skill("unarmed", "houquan");
	map_skill("parry", "houquan");

	set("chat_chance", 3);
	set("chat_msg", ({
	"徐天川想了想，说：有人想要进出皇宫，我得想个法子才好啊。\n",
	"徐天川说道: 江湖威望很重要，威望值高大有好处啊。\n",
        "徐天川突然说：自此传得众兄弟，后来相认团圆时。\n",
        "徐天川突然说：初进洪门结义兄，对天明誓表真心。\n",
	}));

        set("inquiry", ([
		"陈近南" :  "\n想见总舵主可不容易啊。\n",
		"天地会" :  "\n只要是英雄好汉，都可以入我天地会(join tiandihui)。\n",
		"入会" :  "\n只要入了我天地会，可以向会中各位好手学武功。\n",
                "威望" :  (: ask_weiwang :),
                "江湖威望" : (: ask_weiwang :),
                "去清复明膏" : "去药铺内室里仔细瞧瞧吧！\n",
                "去清复明" : "去药铺内室里仔细瞧瞧吧！\n",
                "反清复明" : "去药铺内室里仔细瞧瞧吧！\n",
                "暗号" : "敲三下！\n",
                "切口" : "敲三下！\n",
	]) );

	setup();
	carry_object("/clone/misc/cloth")->wear();
	add_money("gold", 5);
}

void init()
{
::init();
add_action("do_skills","skills");
add_action("do_skills","cha");
add_action("do_join","join");
}

int ask_weiwang()
{
command("tell "+this_player()->query("id")+" 你现在的江湖威望是 " +(string)(this_player()->query("weiwang")));
say("\n徐天川说：如果你威望值很高，有些人见了你不但不会杀你，还会教你武功，送你宝贝。\n"
+"而且你还可以加入帮会，率领会众去攻打目标，就连去钱庄取钱也会有利息 。。。。。\n");
say("徐天川又说：杀某些坏人或救某些好人可以提高江湖威望。\n");
return 1;
}

int recognize_apprentice(object ob)
{
    if (ob->query("weiwang")<50)
    {
    message_vision("$N摇了摇头。\n",this_object());
    command("tell "+ob->query("id")+" 不是天地会弟子我不教。\n"); 
    }
    return 1;
}

int do_skills(string arg)
{
   object ob ;
   ob = this_player () ;
   if( !arg || arg!="xu" )
     return 0;
  if (ob->query("weiwang")<50)
  {
   message_vision("$N摇了摇头。\n",this_object());
   if(wizardp(ob)) 
   {
   write("徐天川怒道：非天地会弟子不能察看！顿了一顿，又陪笑道:当然，巫师除外。\n");
   return 0;
   }	
   command("tell "+ob->query("id")+" 不是天地会弟子不能察看。\n"); 
   return 1;
   }
   command("tell "+ob->query("id")+" 我所有的武功如下：\n"+
"  基本内功 (force)                         - 出神入化  70 \n"+
"  基本轻功 (dodge)                         - 出神入化  70 \n"+    
"  基本招架 (parry)                         - 一代宗师  90 \n"+
"  基本拳脚 (unarmed)                       - 一代宗师  90 \n"+
"  基本手法 (hand)                          - 深不可测 100 \n"+
"□混元一气功 (hunyuan-yiqi)                - 出神入化  70 \n"+
"□少林身法 (shaolin-shenfa)                - 出神入化  70 \n"+
"□猴拳 (houquan)                           - 深不可测 100 \n");
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
	message_vision(HIC "徐天川对$N摇了摇头说：你的江湖威望值太低。\n" NOR,this_player());
  	return 1;
  	}
   if (ob->query("combat_exp")<20000)
        {
	message_vision(HIC "徐天川对$N摇了摇头说：你的实战经验太低。\n" NOR,this_player());
  	return 1;
  	}
    if(ob->query("weiwang")<50)
    {
    ob->set("weiwang",50);
    message_vision(HIC "$N的江湖威望提高了！\n" NOR,this_player());
    command("tell "+this_player()->query("id")+" 你现在的江湖威望是 " +(string)(this_player()->query("weiwang")));
    return 1;	
    }
    else message_vision(HIC "徐天川对$N摇了摇头说：你已经入过天地会了。\n" NOR,this_player());
    return 1;
}