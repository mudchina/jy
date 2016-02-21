// shouyuan.c 守园

inherit NPC;

void create()
{
	set_name("守园道长", ({ "shouyuan daozhang", "shouyuan" }));
	set("long", 
		"他是武当山的守园道长。\n");
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
	set_skill("blade", 40);
	set_skill("taiji-dao", 25);
	set_skill("taoism", 20);

	set_skill("blade", 40);
	set_skill("taiji-dao", 25);
	map_skill("blade", "taiji-dao");
	create_family("武当派", 4, "弟子");

	setup();
	carry_object("/clone/weapon/gangdao")->wield();
}
