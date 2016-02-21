// yang.c 

inherit NPC;

void create()
{
	set_name("ÑîÁ«Í¤", ({ "yang lianting", "yang" }));
	set("long","ËûÉíĞÎ¿ıÎà, ÂúÁ³ò°÷×, ĞÎÃ²¼«ÎªĞÛ½¡. \n");
        set("gender", "ÄĞĞÔ");
	set("age", 40);

	set("max_qi",500);
	set_skill("unarmed", 50);
	set_skill("dodge", 50);
	set_skill("parry", 50);
	set_temp("apply/attack", 40);
	set_temp("apply/defense", 40);
	set_temp("apply/damage", 10);

	set("combat_exp", 50000);
	set("shen_type", -1);
	setup();
	add_money("silver", 50);
	carry_object(__DIR__"obj/yaoshi");
        carry_object(__DIR__"obj/zaohong")->wear();
}
	
