//fen.c
inherit ITEM;
void init()
{
	add_action("do_eat", "eat");
	add_action("do_eat", "use");
}

void create()
{
	set_name("蛇胆粉", ({ "fen"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "包");
		set("long", "这是疗伤的『蛇胆粉』。\n");
		set("value", 2000);
	}
	setup();
}

int do_eat(string arg)
{
	object me = this_player();
	if (!arg||arg!="fen")
		return notify_fail("你要吃什么？\n");
	if ((int)this_player()->query("eff_qi") >= 
	    (int)this_player()->query("max_qi"))
		return notify_fail("你现在不需要用金创药。\n");
	if(random(2)==0)
	 {message_vision( "$N吃下一包蛇胆粉，觉得象是土豆粉，连呼上当￣￣\n" , me);
	  destruct(this_object());
	  return 1;
	 }
	 me->add("qi",30);
	 me->add("eff_qi",20);
	message_vision( "$N吃下一包蛇胆粉，顿觉真气上涌，精神好了些。\n" , me);
	destruct(this_object());
	return 1;
}