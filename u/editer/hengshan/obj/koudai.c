// item: /d/hengshan/obj/koudai.c
// written by Dewey

inherit ITEM;

void create()
{
        set_name("口袋", ({"kou dai", "dai"}));
        set_weight(1000);
        set_max_encumbrance(20000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "个");
                set("long", "一个手工缝制的口袋，可以把东西装在里面。\n");
                set("value", 50);
        }
}

