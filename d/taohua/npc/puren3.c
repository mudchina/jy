// puren.c

inherit NPC;

void create()
{
	set_name("仆人", ({ "pu ren","ren","pu" }) );
	set("gender", "男性" );
	set("age", 30);
	set("long", "一个满面带笑的仆人,正笑吟吟地望着你。\n");
	set("combat_exp", 5000);
	set("str", 17);
	set("dex", 16);
	set("con", 18);
	set("int", 20);
	set("attitude", "peacely");
	set("max_qi", 150);
	set("max_jing", 150);

	set_skill("force", 15);
	set_skill("dodge", 15);
	set_skill("unarmed", 15);
	set_skill("parry", 15);


	setup();
	carry_object("/d/taohua/obj/cloth")->wear();

}

