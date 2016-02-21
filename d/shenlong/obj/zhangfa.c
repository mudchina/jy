
inherit ITEM;

void create()
{
set_name( "天山杖法",({ "zhang book","book","shu"}));
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "本");
set("long","这是一本天山杖谱。\n");
		set("value", 5000);
		set("material", "paper");
		set("skill", ([
  "name": "tianshan-zhang",  //name of the skill
 "exp_required": 10000 , //minimum combat experience required
			"jing_cost": 20+random(30),// jing cost every time study this
			"difficulty":	20,	// the base int to learn this skill
			"max_skill":	60	// the maximum level you can learn
		]) );
	}
}
