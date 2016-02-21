// NPC /d/npc/caihuashe.c
inherit NPC;

void create()
{
        set_name("菜花蛇", ({ "caihua she", "she" }) );
        set("race", "野兽");
        set("age", 1);
        set("long", "一只青幽幽的菜花蛇，头部呈椭圆形。\n");
        set("attitude", "peaceful");
 
        set("str", 15);
        set("cor", 16);

        set("limbs", ({ "头部", "身体", "七寸", "尾巴" }) );
        set("verbs", ({ "bite" }) );
 
        set("combat_exp", 100+random(50));

        set_temp("apply/attack", 7);
        set_temp("apply/damage", 4);
	set_temp("apply/defence",6);
	set_temp("apply/armor",5);

	setup();
}

void die()
{
	object ob;
	message_vision("$N抽搐两下，$N死了。\n", this_object());
	ob = new(__DIR__"obj/sherou");
	ob->move(environment(this_object()));
	destruct(this_object());
}
