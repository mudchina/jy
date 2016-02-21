// shidaizi.c 

inherit NPC;

void create()
{
	set_name("施戴子", ({ "shi daizi", "shi", "daizi" }));
	set("long", 
"施戴子身材高挑，长的普普通通，但双眼炯炯有神，他在\n"
"同门中排行第四，是华山派年轻一代中的好手。\n");
	set("gender", "男性");
	set("age", 28);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 23);
	set("int", 23);
	set("con", 24);
	set("dex", 28);
	
	set("max_qi", 850);
	set("max_jing", 650);
	set("neili", 850);
	set("max_neili", 850);
	set("jiali", 20);
	set("combat_exp", 60000);
	set("score", 6000);

	set_skill("force", 50);
	set_skill("dodge", 50);
	set_skill("parry", 60);
	set_skill("sword", 65);
	set_skill("blade", 65);
	set_skill("strike", 60);
	set_skill("zixia-shengong", 50);
	set_skill("hunyuan-zhang", 60);
	set_skill("fanliangyi-dao", 60);
	set_skill("huashan-jianfa", 65);
	set_skill("huashan-shenfa", 50);

	map_skill("force", "zixia-shengong");
	map_skill("parry", "huashan-jianfa");
	map_skill("dodge", "huashan-shenfa");
	map_skill("sword", "huashan-jianfa");
	map_skill("blade", "fanliangyi-dao");
	map_skill("strike", "hunyuan-zhang");

	prepare_skill("strike", "hunyuan-zhang");
	prepare_skill("cuff", "poyu-quan");

	create_family("华山派", 14, "弟子");

	setup();
	carry_object("/clone/misc/cloth")->wear();
	carry_object("/clone/weapon/changjian")->wield();
}
