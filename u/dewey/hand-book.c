inherit ITEM;

void create()
{
	set_name( "手法图册", ({ "hand book", "book","shu" }));
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "本");
		set("long", "这是手法图册，上面写着一些关于手法的招式及修练法门。\n");
		set("value", 500);
		set("material", "paper");
		set("skill", ([
			"name":	"hand",	
			"exp_required":	100,	// minimum combat experience required
			"jing_cost": 20, 	// jing cost every time study this
			"difficulty":	20,	// the base int to learn this skill
			"max_skill":	150,	// the maximum level you can learn
		]) );
	}
}
