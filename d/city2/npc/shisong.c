// shisong.c 史松

inherit NPC;
//inherit F_SKILL;

void create()
{
	set_name("史松", ({ "shi song", "shi", "song" }));
	set("gender", "男性");
	set("title", "黑龙鞭");
	set("age", 35);
	set("str", 25);
	set("dex", 20);
	set("long", "这是一个精壮汉子，军官模样，腰间围一条长鞭。\n");
	set("combat_exp", 45000);
	set("shen_type", -1);
	set("attitude", "peaceful");
        set("startroom","/d/city/nanmen.c");

	set_skill("unarmed", 50);
	set_skill("force", 50);
	set_skill("whip", 80);
	set_skill("dodge", 50);
	set_skill("parry", 50);

	set_skill("yunlong-bian", 70);

	set_temp("apply/attack", 30);
	set_temp("apply/defense", 30);
	set_temp("apply/armor", 15);
	set_temp("apply/damage", 20);

	map_skill("whip", "yunlong-bian");
	map_skill("parry", "yunlong-bian");

	set("neili", 200); 
	set("max_neili", 200);
	set("jiali", 5);
	set("chat_chance", 15);
	set("chat_msg", ({
		"\n史松一拍腰间的软鞭，说道:在下黑龙鞭史松，奉鳌少保将令，\n"
                "擒拿天地会反贼。" ,
		"\n史松大叫: 反了，反了！通通给我拿下！ \n",
		"史松说道: 鳌少保天生神勇，武功盖世，曾在北京街上一拳\n"
                "打死一头疯牛，就凭你也配和鳌少保动手？\n" ,
		(: random_move :)
	}) );
	setup();
	carry_object("/d/city/obj/junfu")->wear();
	carry_object("/d/city2/obj/hlbian")->wield();
	add_money("silver",3);
}


