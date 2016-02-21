// b_jiasha.c ºÚÉ«ôÂôÄ
//

#include <armor.h>

inherit CLOTH;

void create()
{
        set_name("ºÚÉ«ôÂôÄ",({"jiasha","jia sha","cloth"}));
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "¼ş");
                set("material", "cloth");
                set("armor_prop/armor", 20);
                set("value",100);
        }
        setup();
}

