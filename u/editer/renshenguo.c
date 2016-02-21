/* renshen-guo.c 人参果*/
/* written by Dewey */

#include <ansi.h>

inherit ITEM;

 void create()
{
        set_name(HIG "人参果" NOR, ({"renshen guo", "guo"}));
        set_weight(20);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "枚");
                set("long", "一枚其貌不扬的果子。\n");
                set("value", 100000);
        }

        setup();
}

void init()
{
    if (!wizardp(this_player())) {
        set("no_get"," 嘿嘿，做梦吧! \n");
        set("no_drop","这么宝贵的人参果，哪能乱扔! \n");
       }
        add_action("do_eat", "eat");
       
}

int do_eat(string arg)
{
        object me = this_player();

        if (!id(arg))
           return notify_fail("你要吃什么？\n");
        me->set("qi",(int)this_player()->query("max_qi"));
	me->set("jing",(int)this_player()->query("max_jing"));
	me->set("force", (int)this_player()->query("max_force"));
        me->set("food", 300);
        me->set("water", 300);
        
        message_vision(HIG
        "$N吃下一枚人参果，只觉得精神健旺，气血充盈，体内真力源源滋生，甚至不再感到饥饿干渴! \n"NOR,me);

        destruct(this_object());
}


