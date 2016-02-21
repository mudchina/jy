//songshu.c
inherit NPC;

void create()
{
        set_name("松鼠", ({ "song shu", "shu" }) );
        set("race", "野兽");
        set("age", 2);
        set("long", "一只可爱的松鼠。\n");
        set("attitude", "peaceful");
 
        set("str", 15);
        set("cor", 16);

        set("limbs", ({ "头部", "身体", "爪子", "尾巴" }) );
        set("verbs", ({ "bite" }) );
 
        set("combat_exp", 300);

        set_temp("apply/attack", 5);
        set_temp("apply/damage", 3);
	set_temp("apply/defence",5);
	set_temp("apply/armor",3);

	setup();
}
