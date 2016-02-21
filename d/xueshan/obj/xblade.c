// xue-dao.c

#include <ansi.h>
#include <weapon.h>
inherit BLADE;

void create()
{
	set_name( HIR "血刀" NOR , ({ "xblade" }));
	set_weight(1000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", HIR "这是一把缠在腰间的宝刀，刀锋带着淡淡的血影。\n" NOR );
		set("value", 1000);
		set("material", "steel");
		set("wield_msg", "$N「唰」的一声抽出一柄$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n插回刀鞘。\n");
	}
	init_blade(20);
	setup();
}
