// ding.c 丁春秋

#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("丁春秋", ({ "ding chunqiu", "ding" }));
	set("nickname", HIR "星宿老怪" NOR);
	set("long", 
		"他就是星宿派开山祖师、令正派人士深恶痛绝的星宿老怪丁春秋。\n"
		"可是他看起来形貌清奇，仙风道骨。\n");
	set("gender", "男性");
	set("age", 60);
	set("attitude", "friendly");
	set("shen_type", -1);
	set("str", 25);
	set("int", 30);
	set("con", 28);
	set("dex", 28);
	
	set("max_qi", 4000);
	set("max_jing", 3000);
	set("neili", 4000);
	set("max_neili", 4000);
	set("jiali", 100);
	set("combat_exp", 1500000);
	set("score", 400000);

        set_skill("force", 200);
	set_skill("huagong-dafa", 180);
        set_skill("dodge", 200);
	set_skill("zhaixinggong", 160);
        set_skill("unarmed", 150);
	set_skill("xingxiu-duzhang", 150);
        set_skill("parry", 150);
        set_skill("staff", 170);
	set_skill("tianshan-zhang", 165);
	set_skill("literate", 80);

	map_skill("force", "huagong-dafa");
	map_skill("dodge", "zhaixinggong");
	map_skill("unarmed", "xingxiu-duzhang");
	map_skill("parry", "tianshan-zhang");
        map_skill("staff", "tianshan-zhang");

	create_family("星宿派", 1, "开山祖师");
	set("class", "taoist");

	setup();
        carry_object("/clone/weapon/gangzhang")->wield();
	carry_object("/clone/misc/cloth")->wear();
}

void init()
{
        add_action("do_flatter", "flatter");
}

void attempt_apprentice(object me)
{
        if ((int)me->query("betrayer")) {
                command("say 我越看你越象是来卧底的。");
                return;
        }

        if( me->query_temp("pending/flatter") ) {
                command("say 你如此不把老仙放在眼里，老仙怎会收你？");
                return;
        } else {
                command("say 我星宿老仙比起古往今来的圣人怎么样啊？");
                message_vision("星宿老怪微闭双眼，手捻长须，一付等人拍马(flatter)的样子。\n",
                this_player());
                me->set_temp("pending/flatter", 1);
        }
}

int do_flatter(string arg)
{
        if( !this_player()->query_temp("pending/flatter") )
                return 0;
        if( !arg ) return notify_fail("你说老仙什么？\n");
        this_player()->set_temp("pending/flatter", 0);
        message_vision("$N大声说道：" + arg + "\n", this_player());
        if( strsrch(arg, "星宿老仙") >=0 && (strsrch(arg, "德配天地") >=0
         || strsrch(arg, "威震寰宇") >=0 || strsrch(arg, "古今无比") >=0 )) {
                command("smile");
                command("say 这还差不多。\n");
                command("recruit " + this_player()->query("id"));
        } else {
                command("say 你如此不把老仙放在眼里，老仙怎会收你？");
        }
        return 1;
}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                add("apprentice_available", -1);
}

// 星宿老仙，德配天地，威震寰宇，古今无比
