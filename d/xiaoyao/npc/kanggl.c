// kanggl.c
// shilling 97.2

inherit NPC;
//inherit F_MASTER;

#include <ansi.h>

string ask_me();

void create()
{
	set_name("康广陵", ({ "kang guangling", "kang" }));
	set("long", 
		"只见他高额凸颡，容貌奇古，笑眯眯的脸色\n"
		"极为和谟，手中抱着一具瑶琴。\n");
	set("gender", "男性");
	set("age", 50);
	set("attitude", "friendly");
	set("shen_type", 1);
	set("str", 28);
	set("int", 28);
	set("con", 28);
	set("dex", 38);

	set("inquiry", ([
        "棋谱":(:ask_me:),
	]) );
	
	set("max_qi", 1000);
	set("max_jing", 1000);
	set("neili", 1000);
	set("max_neili", 1000);
	set("jiali", 60);
	set("combat_exp", 200000);
	set("score", 50000);

    set_skill("blade",100);
    set_skill("ruyi-dao",100);
	set_skill("force", 100);
	set_skill("dodge", 100);
	set_skill("unarmed", 100);
	set_skill("parry", 100);
	set_skill("lingboweibu", 100);
    set_skill("beiming-shengong",100);
	set_skill("liuyang-zhang", 100);

	map_skill("unarmed", "liuyang-zhang");
	map_skill("dodge", "lingboweibu");
	map_skill("force", "beiming-shengong");
	map_skill("blade", "ruyi-dao");

	set("book_count", 1);

	create_family("逍遥派", 3, "弟子");
	set("title","逍遥派“函谷八友”");
	set("nickname","琴颠");
	setup();
	carry_object("/d/xiaoyao/obj/cloth")->wear();
//	carry_object("/d/xiaoyao/obj/blade")->wield();

}


string ask_me()
{
	object me,ob;
	ob=this_player(); 
	if (query("book_count") < 1)
		return "你来晚了，棋谱我已经赠送给别入了。";   

	add("book_count", -1);                  
	command("say 好吧，那我就把它送给你了。\n");
	message_vision(HIY"康广陵微笑着从怀中拿出了一本书，交了给$N\n\n"NOR,ob);
	me=new(__DIR__"obj/qibook");
	me->move(ob);
	return "这本棋谱可千万不要随便给别人。\n";
}