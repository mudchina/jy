// laodenuo.c 

inherit NPC;

void create()
{
	set_name("劳德诺", ({ "lao denuo", "lao", "denuo" }));
	set("nickname", "老好人");
	set("long", 
"劳德诺身材矮胖，满面红光，成天笑眯眯的，他在\n"
"同门中排行第二，是华山派年轻一代中唯一带艺投师的。\n");
	set("gender", "男性");
	set("age", 54);
	set("attitude", "peaceful");
	set("shen_type", -1);
	set("str", 18);
	set("int", 25);
	set("con", 20);
	set("dex", 20);
	
	set("max_qi", 1200);
	set("max_jing", 1000);
	set("neili", 1000);
	set("max_neili", 1000);
	set("jiali", 20);
	set("combat_exp", 90000);
	set("score", 8000);

	set_skill("force", 60);
	set_skill("zixia-shengong", 60);
	set_skill("dodge", 60);
	set_skill("parry", 70);
	set_skill("sword", 80);
	set_skill("strike", 80);
	set_skill("cuff", 80);
	set_skill("hunyuan-zhang", 80);
	set_skill("huashan-jianfa", 80);
	set_skill("huashan-shenfa", 60);
	set_skill("poyu-quan", 60);

	map_skill("dodge", "huashan-shenfa");
	map_skill("force", "zixia-shengong");
	map_skill("parry", "huashan-jianfa");
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
