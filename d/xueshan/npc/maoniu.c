// maoniu.c 牦牛
// by secret

inherit NPC;

void create()
{
        set_name("牦牛", ({ "mao niu", "niu" ,"yak"}) );
	set("race", "野兽");
	set("age", 5);
        set("long", "一只身强体壮的牦牛，全身长着长毛，似乎在觅食。\n");
	set("attitude", "peaceful");
        set("str",60);
        set("max_qi",1000);
        set("qi",1000);
        set("max_jing",1000);
        set("jing",1000);
	
	set("limbs", ({ "头部", "身体", "前脚", "后脚", "尾巴" }) );
        set("verbs", ({ "knock", "hoof" }) );

        set("combat_exp", 50000);

        set_temp("apply/attack", 200);
        set_temp("apply/defense", 500);
        set_temp("apply/damage", 20);
        set_temp("apply/armor", 100);

	setup();
}

