// guxu.c 清虚

inherit NPC;
//inherit F_MASTER;

string ask_me();

void create()
{
	set_name("清虚道长", ({ "qingxu daozhang", "qingxu" }));
	set("long", 
		"他就是俞莲舟的弟子清虚道长。\n"
		"他今年二十多岁，主管复真观的杂事。\n"
		"专门在这里看守本派的各种道经");
	set("gender", "男性");
	set("age", 40);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 25);
	set("int", 25);
	set("con", 25);
	set("dex", 25);
	
	set("max_qi", 1000);
	set("max_jing", 800);
	set("neili", 1000);
	set("max_neili", 1000);
	set("jiali", 30);

	set("combat_exp", 70000);
	set("score", 8500);

	set_skill("force", 60);
	set_skill("taiji-shengong", 40);
	set_skill("dodge", 70);
	set_skill("tiyunzong", 50);
	set_skill("unarmed", 60);
	set_skill("taiji-quan", 60);
	set_skill("parry", 60);
	set_skill("sword", 60);
	set_skill("taiji-jian", 60);
	set_skill("taoism", 60);
  	set_skill("literate", 80);

	map_skill("force", "taiji-shengong");
	map_skill("dodge", "tiyunzong");
	map_skill("unarmed", "taiji-quan");
	map_skill("parry", "taiji-jian");
	map_skill("sword", "taiji-jian");

	create_family("武当派", 3, "弟子");
	set("class", "taoist");

	set("inquiry", 
		([
			"道德经" : (: ask_me :),
		]));
                                
	set("book_count", 1);

	setup();
	carry_object("/clone/weapon/changjian")->wield();
}


string ask_me()
{
        mapping fam; 
        object ob;

        if (!(fam = this_player()->query("family")) 
	    || fam["family_name"] != "武当派")
                return RANK_D->query_respect(this_player()) + 
                "与本派素无来往，不知此话从何谈起？";
        if (query("book_count") < 1)
                return "你来晚了，本派的道德真经不在此处。";
        add("book_count", -1);
        ob = new("/d/wudang/obj/daodejing-ii");
        ob->move(this_player());
        return "好吧，这本「道德经」你拿回去好好钻研。";
}
