// yapu.c

inherit NPC;

void create()
{
	set_name("哑仆", ({ "ya pu","ya","pu" }) );
	set("gender", "男性" );
	set("age", 40);
	set("long", "一个表情呆板的老仆人。\n");
	set("combat_exp", 10000);
	set("str", 24);
	set("dex", 20);
	set("con", 23);
	set("int", 20);
	set("attitude", "peacely");
	set("max_qi", 200);
	set("max_jing", 200);

	set_skill("force", 20);
	set_skill("dodge", 20);
	set_skill("unarmed", 22);
	set_skill("parry", 20);


	setup();
	carry_object("/d/taohua/obj/cloth")->wear();

}

