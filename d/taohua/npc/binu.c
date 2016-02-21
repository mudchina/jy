// /NPC binu.c

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("裨女", ({ "binu","nu", "girl"}));
	set("long",
	    "这是个容貌姣好的女子, 瓜子脸蛋,\n"+
	    "眼如点漆, 清秀绝俗.\n");
	set("gender", "女性");
	set("age", 15);
	set("shen_type",1);
	set("attitude", "peaceful");

	set("str", 14);
	set("int", 20);
	set("con", 15);
	set("dex", 16);

	set("qi", 100);
	set("max_qi", 100);
	set("jing", 100);
	set("max_jing", 100);

	set("combat_exp", 500);
	set("score", 100);
	set_skill("force", 10);
	set_skill("unarmed", 10);
	set_skill("dodge", 10);
	set_skill("parry", 10);
	set_skill("hand",10);
	set_skill("strike", 10);
	set_skill("sword",10);


	setup();
	carry_object("/d/taohua/obj/cloth")->wear();
       
}

