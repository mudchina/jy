// 天山折梅手法图

inherit ITEM;

void create()
{
	set_name( "天山折梅手法图下卷", ({ "shoufa tu", "tu" }));
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "幅");
		set("long", "这是一幅天山折梅手法图，上面画着一些纷繁复杂的招式。\n");
		set("value", 500);
		set("material", "paper");
		set("skill", ([
			"name":	"zhemei-shou",	
			"exp_required":	100000,	// minimum combat experience required
			"jing_cost": 30, 	// jing cost every time study this
			"difficulty":	30,	// the base int to learn this skill
			"max_skill":	150,	// the maximum level you can learn
		]) );
	}
}
