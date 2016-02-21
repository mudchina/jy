// puren1.c

#include <ansi.h>
inherit NPC;


void greeting(object);
void init();
void create()
{
	set_name("仆人", ({ "pu ren","ren","pu" }) );
	set("gender", "男性" );
	set("age", 30);
	set("long", "一个满面带笑的仆人,正笑吟吟地望着你。\n");
	set("combat_exp", 5000);
	set("str", 17);
	set("dex", 16);
	set("con", 18);
	set("int", 20);
	set("attitude", "peacely");
	set("max_qi", 150);
	set("max_jing", 150);

	set_skill("force", 15);
	set_skill("dodge", 15);
	set_skill("unarmed", 15);
	set_skill("parry", 15);

	setup();
	carry_object("/d/taohua/obj/cloth")->wear();
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
	if( !ob || environment(ob) != environment() ) return;
	if((string)ob->query("family/family_name")=="桃花岛")
	   { say(WHT "仆人笑吟吟地说道：这位" + RANK_D->query_respect(ob)
	     + "您辛苦了，快请进吧　。\n" NOR);
	     return;
	    }
	if(!ob->query("family/family_name"))
	   { say(WHT "仆人满脸笑容地说道：这位" + RANK_D->query_respect(ob)
	     + ",欢迎您到归云庄做客。\n不过不要乱走哦。\n" NOR);
	     return;
	    }

}

