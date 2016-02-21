// lingshan.c 

inherit NPC;

void create()
{
	set_name("岳灵珊", ({ "yue lingshan", "yue", "lingshan" }));
	set("nickname", "小师妹");
	set("long", 
"岳灵珊身材娇小，长的花容月貌，一点也不象是一个北方人，她在\n"
"同门中排行第七，是华山派掌门岳不群的独女。\n");
	set("gender", "女性");
	set("age", 19);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 18);
	set("int", 25);
	set("con", 24);
	set("dex", 28);
	
	set("max_qi", 600);
	set("max_jing", 500);
	set("neili", 600);
	set("max_neili", 500);
	set("jiali", 10);
	set("combat_exp", 30000);
	set("score", 5000);

	set_skill("force", 30);
	set_skill("zixia-shengong", 30);
	set_skill("dodge", 60);
	set_skill("parry", 40);
	set_skill("sword", 50);
	set_skill("blade", 40);
	set_skill("strike", 50);
	set_skill("hunyuan-zhang", 50);
	set_skill("huashan-jianfa", 50);
	set_skill("huashan-shenfa", 50);
	set_skill("fanliangyi-dao", 30);
//	set_skill("chongling-jianfa", 50);

	map_skill("force", "zixia-shengong");
	map_skill("blade", "fanliangyi-dao");
	map_skill("dodge", "huashan-shenfa");
	map_skill("parry", "huashan-jianfa");
	map_skill("sword", "huashan-jianfa");
	map_skill("strike", "hunyuan-zhang");

	prepare_skill("strike", "hunyuan-zhang");
	prepare_skill("cuff", "poyu-quan");

	create_family("华山派", 14, "弟子");

	setup();
	carry_object("/clone/misc/cloth")->wear();
	carry_object("/d/huashan/obj/bishuijian")->wield();
}
