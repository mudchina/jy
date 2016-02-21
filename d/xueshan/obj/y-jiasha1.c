//
// y_jiasha.c 黄色袈裟
// by secret
//

#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void init()
{
        add_action("do_say", "say");
}


void create()
{
        set_name(HIY"黄色袈裟"NOR,({"jiasha","jia sha","cloth"}));
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
                set("material", "cloth");
                set("armor_prop/armor", 20);
                set("value",100);
        }
        setup();
}

int do_say(string arg)
{

        object me=this_player();
 
        object ob;
        string st1="jiasha";

        if(this_player()->query("family/family_name") != "雪山寺" )
                return 0;

        if (!id(st1))   return 0;

        if( !objectp(ob = present(st1, me)) )
                return 0;


	if( !ob->query("equipped") )
                return 0;


        if ( !arg )   return 0;

        else if ( arg=="wawa" )      {
                me->add("qi", 200);
                message("vision","你获得了雪山诸神的力量，顿觉气力百倍！\n", me);
                return 1;
        }
        else if ( arg=="haha" )      {
                me->add("jing", 200);
                message("vision","你获得了雪山诸神的力量，顿觉精神百倍！\n", me);
                return 1;
        }
        else if ( arg=="heihei" )      {
                me->add("combat_exp", 500);
                message("vision","你获得了雪山诸神的力量，顿悟天机！\n", me);
                return 1;
        }
        if ( arg=="xixi" )      {
                me->add("potential", 20);
                message("vision","你获得了雪山诸神的力量，顿悟玄机！\n", me);
                return 1;
        }

        if ( arg=="hehe" )      {
                me->add("mud_age", 200);
                message("vision","你获得了雪山诸神的力量，顿觉时光飞逝！\n", me);
                return 1;
        }
        return 0;


}
 
