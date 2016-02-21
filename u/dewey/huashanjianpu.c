inherit ITEM;

void create()
{
	set_name( "华山剑谱", ({ "jian pu", "pu" }));
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "本");
		set("long", "这是一本华山剑谱，上面画着一些剑法的招式及修练法门。\n");
		set("value", 500);
		set("material", "paper");
		set("skill", ([
			"name":	"sword",	
			"exp_required":	1000,	// minimum combat experience required
			"jing_cost": 20, 	// jing cost every time study this
			"difficulty":	20,	// the base int to learn this skill
			"max_skill":	80,	// the maximum level you can learn
		]) );
	}
}
