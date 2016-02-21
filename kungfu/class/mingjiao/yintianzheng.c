// YinTianZheng.c
// pal 1997.05.09

#include "ansi.h"

inherit NPC;
inherit F_MASTER;
inherit F_UNIQUE;

void create()
{
    set_name("殷天正", ({"yin tianzheng", "yin", "tianzheng", }));
	set("long",
        "他是一位身材魁梧的秃老者，身穿一件白色长袍。\n"
        "他长眉胜雪，垂下眼角，鼻子钩曲，犹如鹰嘴。\n"
	);
                                                          
	set("title",HIG "明教" HIW "白眉鹰王" NOR);
	set("level",9);
	set("gender", "男性");
	set("attitude", "peaceful");

	set("age", 72);
	set("shen_type", 1);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);

	set("qi", 3500);
	set("max_qi", 3500);
	set("jing", 1500);
	set("max_jing", 1500);
	set("neili", 3000);
	set("max_neili", 3000);
	set("jiali", 150);
	set("combat_exp", 900000);
	set("score", 1000000);

	set_skill("force", 180);
	set_skill("dodge", 120);
	set_skill("unarmed", 185);
	set_skill("parry", 120);
	set_skill("claw", 185);
//	set_skill("hand", 185);
	set_skill("literate", 60);
	set_skill("huntian-qigong", 180);
	set_skill("zhaixinggong", 120);
	set_skill("sougu", 185);
	set_skill("longzhua-gong", 140);

	map_skill("force", "huntian-qigong");
	map_skill("dodge", "zhaixinggong");
	map_skill("claw", "sougu");
	map_skill("parry", "longzhua-gong");

	prepare_skill("claw", "sougu");

	set("chat_chance_combat", 20);
	set("chat_msg_combat", ({
		(: command("perform muyeyingyang") :),
	}) );

	setup();

	carry_object("/d/mingjiao/obj/baipao")->wear();
}

void init()
{
	object me,ob;
	me = this_object () ;
	ob = this_player () ;

	::init();

	if( interactive(ob) && !is_fighting() )
	{
		remove_call_out("greeting");
		call_out("greeting", 1, me, ob);
	}
}

#include "fawang.h"
