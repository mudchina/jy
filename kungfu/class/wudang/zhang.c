// zhang.c 张三丰

#include <ansi.h>

inherit NPC;
inherit F_MASTER;
int ask_me();

void create()
{
	set_name("张三丰", ({ "zhang sanfeng", "zhang" }));
	set("nickname", HIG "邋遢真人" NOR);
	set("long", 
		"他就是武当派开山鼻祖、当今武林的泰山北斗张三丰真人。\n"
		"身穿一件污秽的灰色道袍，不修边幅。\n"
		"身材高大，年满百岁，满脸红光，须眉皆白。\n");
	set("gender", "男性");
	set("age", 100);
	set("attitude", "friendly");
	set("shen_type", 1);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	
	set("max_qi", 5000);
	set("max_jing", 3000);
	set("neili", 10000);
	set("max_neili", 10000);
	set("jiali", 100);
	set("combat_exp", 2000000);
	set("score", 500000);

	set_skill("force", 200);
	set_skill("taiji-shengong", 200);
	set_skill("dodge", 150);
	set_skill("tiyunzong", 150);
	set_skill("unarmed", 200);
	set_skill("taiji-quan", 200);
	set_skill("parry", 200);
	set_skill("sword", 200);
	set_skill("taiji-jian", 200);
	set_skill("blade", 200);
	set_skill("taiji-dao", 200);
	set_skill("taoism", 150);
	set_skill("literate", 100);

	map_skill("force", "taiji-shengong");
	map_skill("dodge", "tiyunzong");
	map_skill("unarmed", "taiji-quan");
	map_skill("parry", "taiji-jian");
	map_skill("sword", "taiji-jian");
	map_skill("blade", "taiji-dao");

	create_family("武当派", 1, "开山祖师");
	set("class", "taoist");

	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		(: perform_action, "sword.lian" :),
		(: perform_action, "sword.chan" :),
		(: perform_action, "sword.sui" :),
		(: exert_function, "recover" :),
	}) );

	//modified by jackyboy [98.9.9]
	set("inquiry", ([
		"作弊"       : (: ask_me :)
	]));


	setup();
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/d/wudang/obj/greyrobe")->wear();
}

//This function is added by jackyboy.[98.9.9]
int ask_me()
{
       mapping my_fam;
 
       object  me;
	int my_age, already_age, i;

	me = this_player();
       my_fam = (mapping)me->query("family");
	my_age = me->query("age");
	already_age = (int)me->query("already_age");

	if(random(5) >= 1)
	{
		me->add("con", 1);
		me->add("str", 1);
		me->add("int", 1);
		me->add("con_improve_time", 1);
		me->add("max_neili", 50);
 		me->add("neili", 50);
		me->add("dex", 1);
		me->add("max_jing", 1);
		me->add("max_qi", 1);
		me->add("jiali", 1);
		me->add("max_jingli", 1);
		me->add("score", 1);
		me->add("shen", 50);
		me->add("combat_exp", 100);
		me->add("potential", 10);
		me->set("already_age", my_age);
		tell_object(me,HIY"张三丰一掌击向你的头顶，你感到浑身暖暖的！\n"NOR);
	}
	else
	{
		me->add("potential",-10);	
		tell_object(me,HIY"张三丰大喝一声：“什么？想作弊！去死吧！”\n一掌下来，你感到好象从天上掉到了地下\n"NOR);
	}
	return 1;
	
}

void attempt_apprentice(object ob)
{
	if(wizardp(ob))
	{
		command("chat 哈哈哈哈！！！！");
		command("chat 想不到老道在垂死之年，又觅得一个可塑之才， 真是可喜可贺。");
		command("recruit " + ob->query("id"));
		return;
	}
	if ((int)ob->query_skill("taiji-shengong", 1) < 50) {
		command("say 我武当派乃内家武功，最重视内功心法。"); 
		command("say " + RANK_D->query_respect(ob) + 
			"是否还应该在太极神功上多下点功夫？");
		return;
	}
	if ((int)ob->query("shen") < 2000) {
		command("say 学武之人，德义为先，功夫的高低倒还在其次，未练武，要先学做人。");
		command("say 在德行方面，" + RANK_D->query_respect(ob) +
			"是否还做得不够？");
		return;
	}
	if (ob->query_int() < 30) {
		command("say 我武当派武功全从道藏悟出。");
		command("say 要能达到炉火纯青之境，体质什么的倒是无关紧要，悟性却是半点也马虎不得。");
		command("say " + RANK_D->query_respect(ob) + "的悟性还大有潜力可挖，还是请回吧。");
		return;
	}
	command("chat 哈哈哈哈！！！！");
	command("chat 想不到老道在垂死之年，又觅得一个可塑之才，真是可喜可贺。");
	command("recruit " + ob->query("id"));
}
