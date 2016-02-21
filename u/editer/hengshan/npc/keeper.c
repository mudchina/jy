// miaozhu.c

#include <ansi.h>

inherit NPC;
inherit F_VENDOR;

void create()
{
        set_name("庙祝", ({ "miao zhu","zhu" }) );
        set("gender", "男性" );
        set("age", 74);
        set("long",
        "这个老人看起来七十多岁了，看著他佝偻的身影，你忽然觉得心情沈重了下来。\n");
        set("combat_exp", 1);
        set("str", 13);
        set("dex", 12);
        set("con", 14);
        set("int", 13);
        set("attitude", "friendly");
        setup();
        carry_object("/u/editer/hengshan/obj/cloth")->wear();
	add_money("coin", 200);
}

void init()
{       
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{
        if( !ob || !present(ob, environment(this_object())) ) return;
        say( WHT "庙祝说道：这位" + RANK_D->query_respect(ob)
                + "，捐点香火钱积点阴德吧。\n"NOR);
}
int accept_object(object who, object ob)
{
        int val;

        val = ob->value();
        if( !val )
                return notify_fail("庙祝不收物品的捐献。\n");
        else if( val > 100 ) {
                if( (who->query("bellicosity") > 0)
                &&      (random(val/10) > (int)who->query("con")) )
                        who->add("bellicosity", - 
(random((int)who->query("con")) + val/1000) );
        }
        say( "庙祝说道：多谢这位" + RANK_D->query_respect(who)
                + "，神明一定会保佑你的。\n");

        return 1;
}