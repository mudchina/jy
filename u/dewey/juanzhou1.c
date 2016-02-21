inherit ITEM;

#include <ansi.h>

void create()
{
	set_name( HIB "卷轴" NOR, ({ "juanzhou","book", "shu" }));
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "本");
		set("long", "这是一幅旧的卷轴，上面写着一些模糊的文字。\n");
		set("value", 500);
		set("material", "paper");
		set("skill", ([
			"name":	"bahuang-gong",	
			"exp_required":	1000,	// minimum combat experience required
			"jing_cost": 30, 	// jing cost every time study this
			"difficulty":	40,	// the base int to learn this skill
			"max_skill":	101,	// the maximum level you can learn
		]) );
	}
}
