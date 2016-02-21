// tong.c  大水桶

inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name("大水桶", ({"shuitong", "tong"}));
	set_weight(80000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一个用来装水的大水桶，是用石头制成的，不过里面是空的。\n");
		set("unit", "个");
		set("value", 0);
		set("max_liquid", 15);
	}

}
