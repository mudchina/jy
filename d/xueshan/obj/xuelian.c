// xuelian.c 雪莲

inherit ITEM;


void init()
{
	add_action("do_eat", "eat");
}

void create()
{
        set_name("雪莲", ({"xue lian", "lian"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "株");
        set("long","这是一株冰山雪莲\n");
		set("value", 10000);
	}
	setup();
}

int do_eat(string arg)
{
	if (!id(arg))
	return notify_fail("你要吃什么？\n");

	this_player()->add("eff_qi", 200);
//	this_player()->add("max_qi", 100);

        message_vision("$N服下一株雪莲,顿觉精力百倍!\n", this_player());
	destruct(this_object());
	return 1;
}


