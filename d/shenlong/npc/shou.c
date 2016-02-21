
#include <ansi.h>

inherit NPC;
inherit F_UNIQUE;
inherit F_MASTER;
int do_skills(string arg);
int do_join(string arg);

void create()
{
	set_name("瘦头陀", ({ "shou toutuo", "shou" ,"toutuo"}));
	set("title", "神龙教右护法");
	set("nickname",HIR "辽东瘦尊者" NOR);
	set("long", "这头陀身材奇矮,而且胖得出奇,整个人就活脱脱是一个大冬瓜.\n光溜溜的脑袋上瞪着一对铜铃大眼,样子非常滑稽.\n" );
	set("gender", "男性");
	set("age", 44);
	set("str", 35);
	set("dex", 20);
	set("max_qi",1500);
        set("qi",1500);
	set("max_jing",500);
        set("jing",500);
	set("combat_exp", 200000);
	set("score", 30000);
	set("shen_type", -1);
	set("attitude", "peaceful");

	set_skill("force", 150);
	set_skill("unarmed", 100);
	set_skill("staff", 100);
	set_skill("parry", 100);
	set_skill("dodge", 90);
	set_skill("yixingbu", 80);
	set_skill("shenlong-bashi", 80);
	set_skill("shedao-qigong", 60);
	map_skill("staff", "shedao-qigong");
	map_skill("unarmed", "shenlong-bashi");
	map_skill("parry", "shenlong-bashi");
	map_skill("dodge", "yixingbu");

	set_temp("apply/attack", 50);
	set_temp("apply/defense", 50);
	set_temp("apply/armor", 30);
	set_temp("apply/damage", 50);
	set("neili", 1500); 
	set("max_neili", 1500);
	set("jiali", 75);
        set("inquiry", ([
		"神龙教" :  "一般人是入不了我神龙教的(join shenlongjiao).\n",
		"入教" :  "一般人是入不了我神龙教的(join shenlongjiao).\n",
		"洪安通" :  "教主脾气不好,要讨他欢心才好。\n",
		"教主" :  "教主脾气不好,要讨他欢心才好。\n",
		"口号" : "万年不老!永享仙福!寿与天齐!文武仁圣!\n",
       ]) );
	setup();
	carry_object("/clone/misc/cloth")->wear();
	add_money("silver", 30);
}

void init()
{
add_action("do_skills","skills");
add_action("do_skills","cha");
add_action("do_join","join");
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
    if( !arg || arg!="shou" )
     return 0;
   if(wizardp(ob)) return 0;
  if (!ob->query("shenlongjiao"))
  {
   message_vision("$N摇了摇头。\n",this_object());
   write("瘦头陀说道：你怎么能看我的武功呢？\n");
   return 1;
  }
   command("tell "+ob->query("id")+" 我所有的武功如下：\n"+
"  基本轻功 (dodge)                         - 一代宗师  90/    \n"+
"  基本内功 (force)                         - 深不可测 150/    \n"+
"  基本招架 (parry)                         - 深不可测 100/    \n"+
"□蛇岛奇功 (shedao-qigong)                 - 神乎其技  60/    \n"+
"□神龙八式 (shenlong-bashi)                - 登峰造极  80/    \n"+
"  基本杖法 (staff)                         - 深不可测 100/    \n"+
"  基本拳脚 (unarmed)                       - 深不可测 100/    \n"+
"□意形步 (yixingbu)                        - 登峰造极  80/    \n");
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
	message_vision(HIC "瘦头陀说道：你已经是神龙教弟子了。\n" NOR,this_player());
	return 1;
	}
   if ((int)ob->query("shen")>-1000)
        {
	message_vision(HIC "瘦头陀对$N大怒道：还想入教?一看你就不是好人!\n" NOR,this_player());
	set_leader(this_player());
	remove_call_out("kill_ob");
	call_out("kill_ob", 1, this_player()); 
  	return 1;
	}
   if (ob->query("combat_exp")<20000)
        {
	message_vision(HIC "瘦头陀对$N摇头道：你的实战经验太低。\n" NOR,this_player());
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
   message_vision(HIC "瘦头陀对$N大怒道：还想入教?一看你就不是好人!\n" NOR,this_player());
	set_leader(this_player());
	remove_call_out("kill_ob");
	call_out("kill_ob", 1, this_player()); 
  	return 1;
	}
}
