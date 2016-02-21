// suxingh.c
// shilling 97.2

inherit NPC;
inherit F_MASTER;

string ask_me();
string ask_book();

void create()
{
	set_name("苏星河",({"su xinghe","su"}));
	set("gender", "男性" );
    set("nickname", "聪辩老人");
	set("shen_type", 0);
    set("age",60);
	set("str", 30);
	set("con", 30);
	set("int", 45);
	set("dex", 35);
	set("per", 30);

	set("no_clean_up",1);

	set("long",
"此人就是号称聪辩老人的苏星河，据说他能言善辩， \n"
"是一个武林中的智者，而他的武功也是无人能知。\n");

	set("combat_exp", 500000);
	set("attitude", "peaceful");
	set("book_count", 1);
	set("chat_chance", 1);

	set("inquiry", ([
//        "秘密地道":(:ask_me:),
        "秘籍":(:ask_book:),
	]) );

	set("max_qi", 3400);
	set("max_jing", 400);
	set("neili", 3500);
	set("max_neili",3500);
	set("jiali", 60);
	set("env/wimpy", 60);

	set_skill("force", 150);
	set_skill("dodge", 150);
	set_skill("unarmed", 150);
	set_skill("parry", 150);
	set_skill("blade", 150);
	set_skill("lingboweibu", 150);
	set_skill("beiming-shengong", 150);
	set_skill("ruyi-dao", 150);
	set_skill("liuyang-zhang", 150);
	set_skill("zhemei-shou", 150);
	set_skill("literate", 100);

	map_skill("unarmed", "liuyang-zhang");
	map_skill("blade", "ruyi-dao");
	map_skill("dodge", "lingboweibu");
	map_skill("force", "beiming-shengong");

//	prepare_skill("hand","zhemei-shou");
//	prepare_skill("strike","liuyang-zhang");	

	create_family("逍遥派", 2, "弟子");
	set("title","逍遥派第二代大弟子");
	setup();
	carry_object("/d/xiaoyao/obj/cloth")->wear();
	carry_object("/d/xiaoyao/obj/blade")->wield();
}


void attempt_apprentice(object ob)
{

	if (ob->query_int() < 30) {
		command("shake"+ ob->query("id")); 
		command("say " + RANK_D->query_respect(ob) + 
			"是否还应该在学问上多下点功夫？");
		return;
	}

	command("say 好吧，我就收下你了，今后要多加努力啊！");
	command("recruit " + ob->query("id"));
 }

string ask_book()
{
	object me,ob;
	mapping fam; 
	ob=this_player();
	if (!(fam = ob->query("family")) 
		|| fam["family_name"] != "逍遥派")
	{
		return"想要秘籍就得加入逍遥派。";
	}
	command("sigh");
	return"本派的武功秘籍藏在一个很秘密的地方，我也没去过。";
}

void recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "xiaoyao");
}