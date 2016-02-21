#include <ansi.h>

inherit ITEM;

void setup()
{}

void init()
{
	add_action("do_eat", "eat");
}

void create()
{
	set_name("雄黄", ({"xionghuang" }));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "包");
		set("long", "这是一包雄黄,据说可驱百毒。\n");
		set("value", 1000);
	}
	setup();
}

int do_eat(string arg)
{
	return notify_fail("想死啊？雄黄不能吃.\n");
}

