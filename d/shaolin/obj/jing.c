inherit ITEM;
inherit F_UNIQUE;
 
void create()
{
        set_name("「法华经」", ({ "jing1", }));
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
             set("long",
                "书皮泛黄，看来已经保存很久了。\n",

        );
                set("value", 0);
                set("material", "silk");
                set("skill", ([
                        "name":       "hand",
		"exp_required":100000,
                        "jing_cost":  40,
                        "difficulty": 20,
                        "max_skill":  200
                ]) );
        }
}
