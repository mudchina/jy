inherit ITEM;

#include <ansi.h>

void create()
{
	set_name( HIM "正气歌" NOR, ({ "zhengqi ge", "book","shu" }));
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "本");
		set("long", "这是一本正气歌，是文天祥所著。\n");
		set("value", 500);
		set("material", "paper");
		set("skill", ([
			"name":	"zhengqijue",	
			"exp_required":	100,	// minimum combat experience required
			"jing_cost": 20, 	// jing cost every time study this
			"difficulty":	20,	// the base int to learn this skill
			"max_skill":	150,	// the maximum level you can learn
		]) );
	}
}
