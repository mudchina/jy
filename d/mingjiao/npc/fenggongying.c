// FengGongYing.c
// pal 1997.05.11

#include <ansi.h>

inherit NPC;
inherit F_MASTER;
inherit F_UNIQUE;

string ask_me();

void create()
{
    set_name("封弓影", ({ "feng gongying", "feng", "gongying", }));
	set("long",
        "他是一个阴郁的瘦子，身穿一件白布长袍。\n"
        "他脸上阴沉沉的，看来心胸必不开阔。\n"
	);

    	set("title",HIG "明教" HIY "神蛇坛" NOR "坛主");

	set("gender", "男性");
	set("attitude", "friendly");
//    set("class", "bonze");

	set("age", 47);
	set("shen_type", 1);
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("max_qi", 450);
	set("max_jing", 300);
	set("neili", 600);
	set("max_neili", 600);
	set("jiali", 50);
	set("combat_exp", 50000);
	set("score", 100);

	set_skill("force", 70);
	set_skill("hunyuan-yiqi", 70);
	set_skill("dodge", 70);
	set_skill("shaolin-shenfa", 70);
	set_skill("finger", 68);
	set_skill("nianhua-zhi", 68);
	set_skill("parry", 70);
	set_skill("sword", 80);
	set_skill("damo-jian", 80);
	set_skill("buddhism", 70);
	set_skill("literate", 70);

	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("finger", "nianhua-zhi");
	map_skill("parry", "damo-jian");
	map_skill("sword", "damo-jian");

	prepare_skill("finger", "nianhua-zhi");

    create_family("明教", 4, "神蛇坛坛主");

	set("inquiry", ([
		"买铁" :    (: ask_me :),
	]));

	setup();

//        carry_object("/d/shaolin/obj/tiexigua")->wield();
        carry_object("/d/mingjiao/obj/baipao")->wear();
}

#include __DIR__"tanzhu.h"

string ask_me()
{
	return "买铁？ 他现在又不缺铁！ 前天老乔不是刚送来一堆铁块，铁手掌什麽的给他吗？！";
}
