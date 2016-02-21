// gao.c 

inherit NPC;

void create()
{
	set_name("高根明", ({ "gao genming", "gao", "genming" }));
	set("nickname", "市井豪杰");
	set("long", 
"高根明身材较胖，是一个小贩，手里总是拿着一杆秤，他在\n"
"同门中排行第五，是华山派年轻一代中的好手。\n");
	set("gender", "男性");
	set("age", 28);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 28);
	set("int", 24);
	set("con", 20);
	set("dex", 20);
	
	set("max_qi", 850);
	set("max_jing", 650);
	set("neili", 850);
	set("max_neili", 850);
	set("jiali", 20);
	set("combat_exp", 60000);
	set("score", 6000);

	set_skill("force", 50);
	set_skill("dodge", 50);
	set_skill("parry", 50);
	set_skill("sword", 65);
	set_skill("strike", 60);
	set_skill("cuff", 60);
	set_skill("zixia-shengong", 50);
	set_skill("hunyuan-zhang", 60);
	set_skill("huashan-jianfa", 65);
	set_skill("huashan-shenfa", 50);
	set_skill("poyu-quan", 50);

	map_skill("force", "zixia-shengong");
	map_skill("parry", "huashan-jianfa");
	map_skill("dodge", "huashan-shenfa");
	map_skill("sword", "huashan-jianfa");
	map_skill("cuff", "poyu-quan");
	map_skill("strike", "hunyuan-zhang");

	prepare_skill("strike", "hunyuan-zhang");
	prepare_skill("cuff", "poyu-quan");

	create_family("华山派", 14, "弟子");

	setup();
	carry_object("/clone/misc/cloth")->wear();
	carry_object("/clone/weapon/changjian")->wield();
}
