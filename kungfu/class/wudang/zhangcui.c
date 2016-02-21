// song.c 宋远桥

inherit NPC;

void create()
{
set_name("张翠山", ({ "zhang cuishan", "zhang" }));  
set("nickname","武当五侠");
	set("long", 
		"他就是张三丰的五弟子、武当七侠之中的张翠山。\n"
		"身穿一件干干净净的白色道袍。\n");
	set("gender", "男性");
        set("age",31);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 28);
	set("int", 28);
	set("con", 28);
	set("dex", 28);
	set("max_qi", 1000);
	set("max_jing", 1000);
	set("neili", 1500);
	set("max_neili", 1500);
	set("jiali", 10);
	set("combat_exp", 150000);
	set("score", 60000);

	set_skill("force", 100);
	set_skill("taiji-shengong", 80);
	set_skill("dodge", 120);
	set_skill("tiyunzong", 120);
	set_skill("unarmed", 100);
	set_skill("taiji-quan", 80);
	set_skill("parry", 80);
	set_skill("sword", 80);
//	set_skill("taiji-jian", 60);
	set_skill("literate", 50);

	map_skill("force", "taiji-shengong");
	map_skill("dodge", "tiyunzong");
	map_skill("unarmed", "taiji-quan");
	map_skill("parry", "taiji-quan");
//	map_skill("sword", "taiji-jian");

	create_family("武当派", 2, "弟子");
	setup();

	set("chat_chance_combat", 40);
	set("chat_msg_combat", ({
		(: perform_action, "unarmed.zhen" :),
		(: exert_function, "recover" :),
	}) );

//	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/d/wudang/obj/whiterobe")->wear();

}


