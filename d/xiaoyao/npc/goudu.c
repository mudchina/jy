// goudu.c
// shilling 97.2

inherit NPC;
//inherit F_MASTER;

#include <ansi.h>

string ask_me();

void create()
{
	set_name("苟读", ({ "gou du", "gou" }));
	set("long", 
		"他看上去也是几十岁的人了，却是纯然一个书呆子的模样。\n");
	set("gender", "男性");
	set("age", 50);
	set("attitude", "friendly");
	set("shen_type", 1);
	set("str", 25);
	set("int", 35);
	set("con", 25);
	set("dex", 25);

	set("inquiry", ([
	  "论语":(:ask_me:),
	]) );
	
	set("max_qi", 800);
	set("max_jing", 800);
	set("neili", 800);
	set("max_neili", 800);
	set("jiali", 60);
	set("combat_exp", 150000);
	set("score", 40000);

    set_skill("blade",60);
    set_skill("ruyi-dao",60);
	set_skill("force", 60);
	set_skill("dodge", 60);
	set_skill("unarmed", 60);
	set_skill("parry", 60);
	set_skill("lingboweibu", 60);
    set_skill("beiming-shengong",60);
	set_skill("zhemei-shou", 60);

	map_skill("unarmed", "zhemei-shou");
	map_skill("dodge", "lingboweibu");
	map_skill("force", "beiming-shengong");
	map_skill("blade", "ruyi-dao");

	set("book_count", 1);

	create_family("逍遥派", 3, "弟子");
	set("title","逍遥派“函谷八友”");
	set("nickname","书呆");
	setup();
	carry_object("/d/xiaoyao/obj/cloth")->wear();
//	carry_object(__DIR__"obj/blade")->wield();

}


string ask_me()
{
	object me,ob;
	ob=this_player(); 

	if (query("book_count") < 1)
		return "你来晚了，那本《论语》我已经赠送给别入了。";   
	add("book_count", -1);                  
	command("say 哈哈，《论语》就没有了，这里有我派高手从少林盗来的书");
	command("say 既然你那么好学，我就把它送给你吧。\n");
	message_vision(HIY"苟读翻箱倒柜找了半天，找出一本旧书，交了给$N \n\n"NOR,ob);
	me=new(__DIR__"obj/book-paper");
	me->move(ob);

	return "这本书可千万不要借给别人啊，他们一借就不还的了。\n";
}