// zhixiang.c 制香
inherit NPC;

void create()
{
	set_name("制香道长", ({ "zhixiang daozhang", "zhixiang" }));
	set("long", 
		"他是武当山的制香道长, 兼在这里出售香烛。\n");
	set("gender", "男性");
	set("age", 30);
	set("attitude", "peaceful");
	set("shen_type", 1);

	set("str", 20);
	set("int", 20);
	set("con", 25);
	set("dex", 20);
	
	set("max_qi", 300);
	set("max_jing", 200);
	set("neili", 300);
	set("max_neili", 300);

	set("combat_exp", 5000);
	set("score", 1000);

	set_skill("force", 60);
	set_skill("dodge", 40);
	set_skill("unarmed", 40);
	set_skill("parry", 40);
	set_skill("sword", 40);
	set_skill("taiji-jian", 20);
	set_skill("taoism", 20);

	map_skill("parry", "taiji-jian");
	map_skill("sword", "taiji-jian");

	create_family("武当派", 4, "弟子");

	setup();
	carry_object("/clone/weapon/changjian")->wield();
}
