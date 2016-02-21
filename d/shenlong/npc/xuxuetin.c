#include <ansi.h>
inherit NPC;

int ask_gao();

void create()
{
	set_name("许雪亭", ( { "xu xueting", "xu" }) );
	set("title", "神龙教青龙使");
	set("nickname", HIR "热血神龙" NOR);
	set("gender", "男性" );
	set("age", 55);
	set("long",
	      "这是个五十来岁的高瘦汉子，着一袭青衣，昂然挺立。\n"
	     );

	set("int", 30);
	set("str", 25);
	set("con", 23);
	set("dex", 22);
	
	set_temp("apply/attack", 100);
	set_temp("apply/defense", 100);
	set_temp("apply/damage", 100);
	set("qi",10000);
	set("max_qi", 10000);
	set("jing", 1000);
	set("max_jing", 1000);
	set("neili", 1000);
	set("max_neili", 1000);
	set("jiali", 150);
	set("combat_exp", 5000000);
	set("score", 250000);

	set_skill("force", 90);
	set_skill("taiji-shengong", 80);
	set_skill("dodge", 90);
	set_skill("tiyunzong", 80);
	set_skill("unarmed", 90);
	set_skill("taiji-quan", 80);
	set_skill("parry", 90);
	set_skill("sword", 100);
	set_skill("taiji-jian", 90);
	set_skill("taoism", 150);
	set_skill("literate", 60);

	map_skill("force", "taiji-shengong");
	map_skill("dodge", "tiyunzong");
	map_skill("unarmed", "taiji-quan");
	map_skill("parry", "taiji-jian");
	map_skill("sword", "taiji-jian");



       set("inquiry", ([
	    "百花腹蛇膏" : (: ask_gao :),
		"神龙教" :  "\n一般人是入不了我神龙教的(join shenlongjiao).\n",
		"洪安通" :  "\n教主脾气不好,要讨他欢心才好。\n",
		"教主" :  "\n教主脾气不好,要讨他欢心才好。\n",
		"入教" :  "\n一般人是入不了我神龙教的(join shenlongjiao).\n",
		"口号" : "\n万年不老!永享仙福!寿与天齐!文武仁圣!\n",
	]));
		set("chat_chance", 3);
        set("chat_msg", ({
"许雪亭忽然一怕脑袋，说：对了，可以用百花腹蛇膏！\n",
"许雪亭怒道：唉，偌大一个神龙教，都毁在一个娘么手里了！\n",
"许雪亭叹口气，说道：唉，不杀了洪安通，谁也活不了。\n",
        }) );
	setup();
        carry_object("/d/city/obj/duanjian")->wield();
}

int ask_gao()
{
say(
"\n许雪亭悄声对你说：这可是本教禁物啊。它一遇鲜血，便生浓香，\n"
"我们住在这灵蛇岛上，人人都服惯了雄黄酒，以避毒蛇，这股香气\n"
"一碰到雄黄酒，便使人筋骨酥软，不能动弹。对了，你怎么也知道？\n"
		);
return 1;
}

int accept_object(object who, object ob)
{
	object obn;

	if( !who || environment(who) != environment() ) return 0;
	if ( !objectp(ob) ) return 0;
	if ( !present(ob, who) ) return notify_fail("你没有这件东西。\n");

	if (  (string)ob->query("name") != "腹蛇胆"
		&& (string)ob->query("name") != HIG "百香花" NOR )
		    return notify_fail("许雪亭摇头道：如果杀不了洪安通，给我什么也没用啊。。。\n");
	if ( (string)ob->query("name") == "腹蛇胆" )
		{
		  if(query_temp("baixianghua"))
		  {
		  message_vision("\n许雪亭见是腹蛇胆，大喜道：腹蛇胆百香花都有了,百花腹蛇膏练成了!\n",who);
		  obn=new("/d/shenlong/obj/baihua");
                  obn->move(who);
		  delete_temp("fushedan");
		  delete_temp("baixianghua");
 	           return 1;		 
		  } 		
		  else	
		  {	
		  if(query_temp("fushedan"))
                  {
		  message_vision("\n许雪亭见是腹蛇胆，对$N摇头道：腹蛇胆我有了，就差百香花了。\n",who);
			   return 0;
		  }
		  else	  
                  {
		  message("vision","许雪亭看见腹蛇胆，大喜道：有了腹蛇胆，只差百香花了。\n",environment(who));
		  set_temp("fushedan",1);	
	          return 1;
		  }
		}
	}
	if ( (string)ob->query("name") == HIG "百香花" NOR)
		{
		  if(query_temp("fushedan"))
		  {
		  message_vision("\n许雪亭见是百香花，大喜道：腹蛇胆百香花都有了,百花腹蛇膏练成了!\n",who);
		  obn=new("/d/shenlong/obj/baihua");
                  obn->move(who);
		  delete_temp("fushedan");
		  delete_temp("baixianghua");
 	          return 1;		 
		  } 		
		  else	
		  {	
		  if(query_temp("baixianghua"))
                  {
		  message_vision("\n许雪亭见是百香花，对$N摇头道：百香花我有了，就差腹蛇胆了。\n",who);
			   return 0;
		  }
		  else	  
                  {
		  message("vision","许雪亭看见百香花，大喜道：有了百香花，只差腹蛇胆了。\n",environment(who));
		  set_temp("baixianghua",1);	
	          return 1;
		  }
		 }	
	}
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
    if( !arg || arg!="xu" )
     return 0;
   if(wizardp(ob)) return 0;
  if (!ob->query("shenlongjiao"))
  {
   message_vision("$N摇了摇头。\n",this_object());
   write("许雪亭说道：你怎么能看我的武功呢？\n");
   return 1;
  }
   command("tell "+ob->query("id")+" 我所有的武功如下：\n"+
"  基本轻功 (dodge)                         - 一代宗师  90/    \n"+
"  基本内功 (force)                         - 一代宗师  90/    \n"+
"  读书写字 (literate)                      - 了然於胸  60/    \n"+
"  基本招架 (parry)                         - 一代宗师  90/    \n"+
"  基本剑法 (sword)                         - 深不可测 100/    \n"+
"□太极剑法 (taiji-jian)                    - 一代宗师  90/    \n"+
"□太极拳 (taiji-quan)                      - 登峰造极  80/    \n"+
"□太极神功 (taiji-shengong)                - 登峰造极  80/    \n"+
"  道学心法 (taoism)                        - 深不可测 150/    \n"+
"□梯云纵 (tiyunzong)                       - 登峰造极  80/    \n"+
"  基本拳脚 (unarmed)                       - 一代宗师  90/    \n");
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
	message_vision(HIC "许雪亭说道：你已经是神龙教弟子了。\n" NOR,this_player());
	return 1;
	}
   if ((int)ob->query("shen")>-1000)
        {
	message_vision(HIC "许雪亭对$N大怒道：还想入教?一看你就不是好人!\n" NOR,this_player());
	set_leader(this_player());
	remove_call_out("kill_ob");
	call_out("kill_ob", 1, this_player()); 
  	return 1;
	}
   if (ob->query("combat_exp")<20000)
        {
	message_vision(HIC "许雪亭对$N摇头道：你的实战经验太低。\n" NOR,this_player());
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
   message_vision(HIC "许雪亭对$N大怒道：还想入教?一看你就不是好人!\n" NOR,this_player());
	set_leader(this_player());
	remove_call_out("kill_ob");
	call_out("kill_ob", 1, this_player()); 
  	return 1;
	}
}
