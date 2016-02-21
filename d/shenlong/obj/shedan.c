inherit ITEM;


void init()
{
        add_action("do_eat", "eat");
}

void create()
{
	set_name("¸¹Éßµ¨", ({"dan"}));
        set("unit", "Ã¶");
	set("long", "ÕâÊÇÒ»Ã¶»ðºìµÄ¸¹Éßµ¨¡£\n");
	set("value", 500);
        setup();
}

int do_eat(string arg)
{
if (!id(arg))  return notify_fail("ÄãÒª³ÔÊ²Ã´£¿\n");
if(arg=="dan") this_player()->unconcious();
}
