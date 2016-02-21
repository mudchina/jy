//wolf2.c

inherit NPC;

void create()
{
	set_name("狼", ({ "wolf2", "lang" }) );
	set("race", "野兽");
	set("age", 5);
	set("long", "一匹昂首直立，两眼放着绿光的狼。\n");
	set("attitude", "aggressive");

	set("str", 26);
	set("cor", 30);
	set("limbs", ({ "头部", "身体", "腿部", "尾巴",}) );
	set("verbs", ({ "bite" }) );

	set("combat_exp", 5000);

        set("chat_chance",50);
	set_temp("apply/attack", 25);
	set_temp("apply/damage", 20);
	set_temp("apply/armor", 18);
	set_temp("apply/defence",20);

	setup();
}

