// damo.c 达摩祖师

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("达摩祖师", ({ "damo zushi", "damo" }));
	set("nickname", "一苇渡江");
	set("long", 
		"他就是少林派开山鼻祖、当今武林的隐世高僧达摩祖师。\n"
		"身穿一件锦兰袈挲，手执禅杖。\n"
		"身材高大，年满百岁，满脸红光，须眉皆白。\n");
	set("gender", "男性");
	set("age", 500);
	set("attitude", "friendly");
	set("shen_type", 1);
	set("str", 50);
	set("int", 50);
	set("con", 50);
	set("dex", 50);
	
	set("max_qi", 10000);
	set("max_jing", 5000);
	set("neili", 10000);
	set("max_neili", 10000);
	set("jiali", 200);
	set("combat_exp", 10000000);
	set("score", 1000000);

	set_skill("force", 500);
	set_skill("jiuyang-shengong", 500);
	set_skill("dodge", 500);
	set_skill("shaolin-shenfa", 500);
	set_skill("cuff", 500);
	set_skill("sword", 500);
	set_skill("parry", 500);
	set_skill("finger", 500);
	set_skill("shaolin-shenfa", 500);
	set_skill("hand", 500);
	set_skill("strike", 500);
	set_skill("claw", 500);
	set_skill("staff", 500);
	set_skill("club", 500);
	set_skill("blade", 500);
	set_skill("whip", 500);
	set_skill("damo-jian", 500);
	set_skill("jingang-quan", 500);
	set_skill("buddhism", 500);
	set_skill("literate", 500);

	map_skill("force", "jiuyang-shengong");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("cuff", "jingang-quan");
	map_skill("parry", "jingang-quan");
	map_skill("sword", "damo-jian");
	map_skill("whip", "riyue-bian");

	create_family("少林派", 1, "开山祖师");
	set("class", "buddhism");

	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		(: perform_action, "whip.chan" :),
		(: exert_function, "recover" :),
	}) );

	setup();
	carry_object("/d/shaolin/obj/changbian")->wield();
}

void attempt_apprentice(object ob)
{
	object me; 
	mapping ob_fam, my_fam;
	string name, new_name;

	me = this_object();
	my_fam  = me->query("family");

	name = ob->query("name");

	if (!(ob_fam = ob->query("family")) || ob_fam["family_name"] != "少林派")
	{
		command("say " + RANK_D->query_respect(ob) + "与本派素无来往，不知此话从何谈起？");
		return;
	}

	if ( (string)ob->query("class")!="bonze" && ob_fam["family_name"] == "少林派") 
	{
		command("say " + RANK_D->query_respect(ob) + "是俗家弟子，不能在寺内学艺。");
		return;
	}

	if ( ob_fam["generation"] <= my_fam["generation"] )
	{
		command("say " + RANK_D->query_respect(ob) + "，贫僧哪里敢当 !");
		return;
	}
	if ((int)ob->query_skill("hunyuan-yiqi", 1) < 200) {
		command("say 我少林派乃内家武功，最重视内功心法。"); 
		command("say " + RANK_D->query_respect(ob) + 
			"是否还应该在内功上多下点功夫？");
		return;
	}
	if ((int)ob->query_skill("buddhism", 1) < 180) {
		command("say 悟禅之人，德义为先，功夫的高低倒还在其次，未练武，要先学做人。");
		command("say 在禅宗心法方面，" + RANK_D->query_respect(ob) +
			"是否还做得不够？");
		return;
	}
	if ((int)ob->query_skill("dodge", 1) < 200) {
		command("say 在轻功方面，" + RANK_D->query_respect(ob) +
			"是否还做得不够？");
		return;
	}
	if ((int)ob->query_skill("shaolin-shenfa", 1) < 200) {
		command("say 在轻功方面，" + RANK_D->query_respect(ob) +
			"是否还做得不够？");
		return;
	}
	if ((int)ob->query_skill("force", 1) < 200) {
		command("say 在内功方面，" + RANK_D->query_respect(ob) +
			"是否还做得不够？");
		return;
	}
	if ((int)ob->query_skill("parry", 1) < 200) {
		command("say 在基本功方面，" + RANK_D->query_respect(ob) +
			"是否还做得不够？");
		return;
	}
	if (ob->query_int() < 45) {
		command("say 万事都讲一个缘字。");
		command("say " + RANK_D->query_respect(ob) + "与佛无缘，还是请回吧。");
		return;
	}
	if (ob->query_MKS() > 0 ) {
		command("say 万事都讲一个缘字。");
		command("say " + RANK_D->query_respect(ob) + "与佛无缘，还是请回吧。");
		return;
	}
	if (ob->query_PKS() > 0 ) {
		command("say 万事都讲一个缘字。");
		command("say " + RANK_D->query_respect(ob) + "与佛无缘，还是请回吧。");
		return;
	}
//	if ( ( ob_fam["generation"] + 35 ) == (my_fam["generation"]) )
	if ( ob->query("family/generation") == 36 )
	{
	//	if ( ob->query("luohan_winner") )
	//	{	
			command("say 老衲垂死之年，又得一可塑之才，真是可喜可贺 !");

			name = ob->query("name");
			new_name = "渡" + name[2..3];
			ob->set("name", new_name);
			ob->set("family/generation", 35);

			command("say 从今以后你的法名叫做" + new_name + "，恭喜你荣升为少林派渡字辈罗汉之一 !");
			command("recruit " + ob->query("id"));
		
		
	}

	return;



}
