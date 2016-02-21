// letter.c

inherit ITEM;

void create()
{
        set_name("信", ({"letter"}));
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "封");
                set("long","这是一封任盈盈给令狐冲的情书。\n");
//		set("no_drop", "这样东西不能离开你。\n");
                set("material", "paper");
        }
}

