inherit ITEM;

#include <ansi.h>

void create()
{
	set_name(HIR "四书五经" NOR, ({  "book","shu" }));
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "本");
		set("long", "这是一套四书五经，是读书识字，应试科举的教材。\n");
		set("value", 500);
		set("material", "paper");
		set("skill", ([
			"name":	"literate",	
			"exp_required":	10,	// minimum combat experience required
			"jing_cost": 5, 	// jing cost every time study this
			"difficulty":	22,	// the base int to learn this skill
			"max_skill":	80,	// the maximum level you can learn
		]) );
	}
}
