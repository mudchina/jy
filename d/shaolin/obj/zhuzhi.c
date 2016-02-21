// zhuzhi.c 竹枝

#include <weapon.h>

inherit BLADE;

void create()
{
	set_name("竹枝", ({ "zhuzhi","zhi" }) );
	set_weight(350);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一根绿色的竹枝，好象刚刚折下来，还带着几片竹叶。\n");
		set("unit", "根");
		set("value", 0);
		set("wield_msg", "$N抓起一根$n，摘掉上面的叶子，握在手中当武器。\n");
	}
	init_blade(1);
	setup();
}

