
#include <ansi.h>

inherit NPC;
inherit F_UNIQUE;
inherit F_MASTER;
int do_skills(string arg);
int do_join(string arg);

void create()
{
	set_name("章老三", ({ "zhang laosan", "zhang" }));
	set("title", "神龙教小头目");
	set("gender", "男性");
	set("age", 44);
	set("str", 25);
	set("dex", 20);
	set("long", "这是一个干瘦老头,一双小眼睛贼闪发光。\n");
	set("combat_exp", 25000);
	set("score", 2000);
	set("shen_type", -1);
	set("attitude", "peaceful");

	set_skill("force", 50);
	set_skill("unarmed", 70);
	set_skill("dodge", 70);
	set_skill("parry", 70);
	set_skill("yixingbu", 40);
	set_skill("shenlong-bashi", 50);
	map_skill("parry", "shenlong-bashi");
	map_skill("dodge", "yixingbu");

	set_temp("apply/attack", 15);
	set_temp("apply/defense", 15);
	set_temp("apply/armor", 10);
	set_temp("apply/damage", 10);
	set("neili", 500); 
	set("max_neili", 500);
	set("jiali", 10);
        set("inquiry", ([
		"神龙教" :  "\n一般人是入不了我神龙教的(join shenlongjiao).\n",
		"入教" :  "\n一般人是入不了我神龙教的(join shenlongjiao).\n",
		"洪安通" :  "\n教主脾气不好,要讨他欢心才好。\n",
		"教主" :  "\n教主脾气不好,要讨他欢心才好。\n",
		"口号" : "\n万年不老!永享仙福!寿与天齐!文武仁圣!\n",
       ]) );
        set("chat_msg", ({
"章老三高声叫道:教主宝训,时刻在心,建功克敌,无事不成!\n",
"章老三高声叫道:众志齐心可成城,威震天下无比伦!\n",
"章老三高声叫道:神龙飞天齐仰望,教主声威盖八方!\n",
"章老三高声叫道:乘风破浪逞英豪,教主如同日月光!\n",
"章老三高声叫道:教主永享仙福,寿与天齐!\n",
        }) );
	setup();
	carry_object("/clone/misc/cloth")->wear();
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
    if( !arg || arg!="zhang" )
     return 0;
   if(wizardp(ob)) return 0;
  if (!ob->query("shenlongjiao"))
  {
   message_vision("$N摇了摇头。\n",this_object());
   write("章老三说道：你怎么能看我的武功呢？\n");
   return 1;
  }
   command("tell "+ob->query("id")+" 我所有的武功如下：\n"+
"  基本轻功 (dodge)                         - 出神入化  70/    \n"+
"  基本内功 (force)                         - 出类拔萃  50/    \n"+
"  基本招架 (parry)                         - 出神入化  70/    \n"+
"□神龙八式 (shenlong-bashi)                - 出类拔萃  50/    \n"+
"  基本拳脚 (unarmed)                       - 出神入化  70/    \n"+
"□意形步 (yixingbu)                        - 驾轻就熟  40/    \n");
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
	message_vision(HIC "章老三说道：你已经是神龙教弟子了。\n" NOR,this_player());
	return 1;
	}
   if ((int)ob->query("shen")>-1000)
        {
	message_vision(HIC "章老三对$N大怒道：一看你就不是好人!\n" NOR,this_player());
	set_leader(this_player());
	remove_call_out("kill_ob");
	call_out("kill_ob", 1, this_player()); 
  	return 1;
	}
   if (ob->query("combat_exp")<20000)
        {
	message_vision(HIC "章老三对$N摇头道：你的实战经验太低。\n" NOR,this_player());
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
   message_vision(HIC "章老三对$N大怒道：一看你就不是好人!\n" NOR,this_player());
	set_leader(this_player());
	remove_call_out("kill_ob");
	call_out("kill_ob", 1, this_player()); 
  	return 1;
	}
}
