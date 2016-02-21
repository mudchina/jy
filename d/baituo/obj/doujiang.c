// DOUJIANG.C 豆浆
// By Marz 03/29/96

inherit ITEM;

void init();
void do_eat();

void create()
{
	set_name("豆浆",({ "jiang"}));
	set_weight(50);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一杯热气腾腾的豆浆～～～\n");
		set("unit", "杯");
		set("value", 500);
        set("remaining", 2);
        set("drink_supply", 30);
    }
	
	setup();
}

void init()
{
	add_action("do_drink", "drink");
}


int do_drink(string arg)
{
    if( !this_object()->id(arg) ) return 0;
    if( this_player()->is_busy() )
        return notify_fail("你上一个动作还没有完成。\n");
    if(   (int)this_player()->query("water")
       >= (int)this_player()->max_water_capacity() )
     return notify_fail("你已经喝太多了，再也灌不下一滴水了。\n");

	set("value", 0);
    this_player()->add("water", (int)query("drink_supply"));
    destruct(this_object());
   return 1;
}
