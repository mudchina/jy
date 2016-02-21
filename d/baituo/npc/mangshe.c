//mangshe.c

inherit NPC;

void create()
{
	set_name("蟒蛇", ({ "mang she", "she" }) );
	set("race", "野兽");
	set("age", 5);
	set("long", "一只昂首直立，吐着长舌芯的大蟒蛇。\n");
	set("attitude", "peaceful");

	set("str", 26);
	set("cor", 30);
	set("limbs", ({ "头部", "身体", "七寸", "尾巴" }) );
	set("verbs", ({ "bite" }) );

	set("combat_exp", 5000);

        set("chat_chance",50);
	set("chat_msg", ({
		"大蟒蛇虎视眈眈地注视着你，想把你一口吞下！\n",
		"大蟒蛇张了一下血盆大口，好象饿了。\n"
	}) );

	set_temp("apply/attack", 25);
	set_temp("apply/damage", 20);
	set_temp("apply/armor", 18);
	set_temp("apply/defence",20);

	setup();
}

void die()
{
	object ob;
	message_vision("$N倒在地上，死了！\n", this_object());
	ob = new("/d/baituo/obj/shepi");
	ob->move(environment(this_object()));
	destruct(this_object());
}
