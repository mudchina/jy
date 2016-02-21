// yuxiao.c

#include <ansi.h>
#include <weapon.h>

inherit SWORD;

void create()
{
    set_name("绣花针", ({"zhen"}));
    set_weight(500);

	if (clonep())
		set_default_object(__FILE__);
	else {
        set("unit", "枚");
        set("long", "一枚精钢打制的绣花针，看上去雪亮雪亮的。武林中人很少以它为兵器。\n");
		set("value", 10000);
		set("material", "steel");
        set("wield_msg", "$N手腕一抖，手中已多了一枚雪亮的绣花针。\n");
        set("unwield_msg", "$N手腕一转，眨眼间绣花针已然不见影踪。\n");
	}
    init_sword(100);
	setup();
}	
