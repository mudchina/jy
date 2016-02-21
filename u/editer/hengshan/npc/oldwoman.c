// oldwoman.c

#include <ansi.h>

inherit NPC;
inherit F_DEALER;

void create()
{
        set_name("老大娘", ({ "old woman", "woman" }) );
        set("gender", "女性" );
        set("age", 63);
        set("long", "一个满脸风霜之色的老婆婆,正在编制笼子。\n");
        set("shen", 1000);
	set("shen_type", 1);
	set("combat_exp", 150);
        set("env/wimpy", 60);
        set("chat_chance_combat", 50 );
        set("vendor_goods", ({
		"/u/editer/hengshan/obj/koudai"
	}));;
        set("str", 13);
        set("dex", 12);
        set("con", 14);
        set("int", 13);
        set("attitude", "friendly");
        set("inquiry", ([
                "口袋" : WHT "这位客官，你是不是想买口袋？五十文钱一个" NOR,
        ]) );
        setup();
        set("chat_chance", 10);
        set("chat_msg", ({
		"老大娘伤心的说道：宁为太平犬，不为乱世人呀。\n",
		"老大娘叹了口气，说道：年年打仗，这是个什麽世道啊。\n",
        }) );
	carry_object("/u/editer/hengshan/obj/cloth")->wear();
	add_money("coin", 100);
}

void init()
{	
	add_action("do_buy", "buy");
}

