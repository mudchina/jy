// /NPC xuzhu.c

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("虚竹", ({ "xu zhu", "xu", "zhu" }));
	set("long",
	    "这是一个二十五六岁的年轻人, 浓眉大眼,\n"+
	    "大大的鼻子扁平下塌, 容貌颇为丑陋. \n"+
	    "身穿一件华贵雅致的长袍, 倒使他更显几分精神.\n"+
	    "他就是天山童姥的救命恩人.\n");
	set("title", "灵鹫宫掌门人");
	set("gender", "男性");
	set("age", 26);
	set("nickname", HIR "梦郎" NOR);
	set("shen_type",1);
	set("attitude", "peaceful");

	set("str", 30);
	set("int", 25);
	set("con", 40);
	set("dex", 30);

	set("qi", 4000);
	set("max_qi", 4000);
	set("jing", 2000);
	set("max_jing", 2000);
	set("neili", 8000);
	set("max_neili", 8000);
	set("jiali", 100);

	set("combat_exp", 1500000);
	set("score", 20000);
	set_skill("force", 150);
	set_skill("unarmed", 180);
	set_skill("dodge", 150);
	set_skill("parry", 150);
	set_skill("hand",180);
	set_skill("strike", 180);

	set_skill("zhemei-shou",150);
	set_skill("liuyang-zhang",150);
	set_skill("yueying-wubu",100);
	set_skill("bahuang-gong", 150);

	map_skill("force", "bahuang-gong");
	map_skill("strike","liuyang-zhang");
	map_skill("dodge", "yueying-wubu");
	map_skill("unarmed", "liuyang-zhang");
	map_skill("hand", "zhemei-shou");
	map_skill("parry", "liuyang-zhang");

	prepare_skill("hand","zhemei-shou");
	prepare_skill("strike","liuyang-zhang");	
	create_family("灵鹫宫",2, "弟子");
	setup();
	carry_object("/d/lingjiu/obj/changpao")->wear();
	add_money("silver",50);
}

void attempt_apprentice(object ob)
{
   if ((int)ob->query_skill("bahuang-gong", 1) < 50) 
           {
		command("say " + RANK_D->query_respect(ob) + "是否还应该多练练八荒六合唯我独尊功？");
		return;
	   }  
   if ((string)ob->query("gender")=="女性")
   {
		message_vision("虚竹垂目沉思片刻, 说道：“好吧, 我就收下你了。”\n",ob);
       command("recruit " + ob->query("id"));
		if((string)ob->query("class") != "dancer")
			ob->set("class", "dancer");
       return;}
   else
      {
		message_vision("虚竹瞪着你看了半天,说道：“阁下不会是想来抢我的生意吧?”\n",ob);
       return;}
}
