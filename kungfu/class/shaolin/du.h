// du.h for apprentice.
//Hop 1997.01.23

void attempt_apprentice(object ob)
{
	object me  = this_object();
	mapping ob_fam;
	mapping my_fam  = me->query("family");

	string name, new_name;

	name = ob->query("name");

	if ( ob->query("betrayer") >= 2)
	{
		command("say " + RANK_D->query_respect(ob) + "判师次数太多了，我不能收你。");
		return;
	}

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

	if ( ob_fam["generation"] == (my_fam["generation"] + 1) )
	{
		command("say " + ob_fam["master_name"] + "的徒弟怎麽跑到我这儿来了，哈哈哈 !");
		command("recruit " + ob->query("id"));
	}

	if (ob->query("family/generation") == 37)
	{
		if ((int)ob->query_skill("dodge", 1) < 120 ||
		    (int)ob->query_skill("parry", 1) < 120 ||
		    (int)ob->query_skill("force", 1) < 120 ||
		    (int)ob->query_skill("buddhism", 1) < 120 ||
		    (int)ob->query_skill("hunyuan-yiqi", 1) < 120 ||
		    (int)ob->query_skill("shaolin-shenfa", 1) < 120) {
			command("say " + "你是否还应该在各项技能上多下点功夫？");
			return;
		}

		command("chat 哈哈哈哈！！！！");
		command("chat 想不到老纳在垂死之年，又觅得一个可塑之才，真是可喜可贺。");
		command("recruit " + ob->query("id"));
	
		command("say 是" + ob_fam["master_name"] + "叫你来找我的吧，哈哈哈 !");
		command("say 贫僧又得一可塑之才，真是可喜可贺 !");

		name = ob->query("name");
		new_name = "玄" + name[2..3];
		ob->set("name", new_name);
		ob->set("family/generation",36);

		ob->add("str",1);
		ob->add("int",1);
		ob->add("con",1);
		ob->add("dex",1);
		ob->add("max_neili",100);
	
		command("say 从今以后你的法名叫做" + new_name + "，恭喜你荣升为少林派玄字辈弟子 !");
		command("recruit " + ob->query("id"));
	}


}

