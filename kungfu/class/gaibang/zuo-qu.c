// gaibang npc code

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("左全", ({"zuo quan", "zuo", "quan"}));
	set("title", "丐帮七袋弟子");
	set("gender", "男性");
	set("age", 35);
	set("long", 
		"这是位豪爽大方的丐帮七袋弟子，看来是个北地豪杰。\n");
	set("attitude", "peaceful");
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 26);

	set("qi", 360);
	set("max_qi", 360);
	set("jing", 300);
	set("max_jing", 300);
	set("neili", 710);
	set("max_neili", 710);
	set("jiali", 36);
	
	set("combat_exp", 68000);
	
	set_skill("force", 73); 
	set_skill("huntian-qigong", 70); 
	set_skill("unarmed", 70); 
	set_skill("xianglong-zhang", 73); 
	set_skill("dodge", 70); 
	set_skill("xiaoyaoyou", 71); 
	set_skill("parry", 70); 
	set_skill("begging", 50); 
	set_skill("checking", 50); 
	
	map_skill("force", "huntian-qigong");
	map_skill("unarmed", "xianglong-zhang");
	map_skill("dodge", "xiaoyaoyou");
	
	create_family("丐帮", 19, "弟子");
	setup();
}

void attempt_apprentice(object ob)
{
	if( ob->query("gender") != "男性") return;
	command("say 好吧，希望你能好好学习本门武功，将来为丐帮争一口气！。");
	command("recruit " + ob->query("id"));
	if((string)ob->query("class") != "beggar")
		ob->set("class", "beggar");
}
