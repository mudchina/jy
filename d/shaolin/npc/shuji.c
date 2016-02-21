// shuji.c 户部书记

inherit NPC;

void create()
{
	set_name("刘书记", ({ "liu shuji", "liu", "shuji" }));
	set("title", "户部九品文官");
	set("nickname", "全靠一支笔");
	set("shen_type", 1);

	set("str", 50);
	set("gender", "男性");
	set("age", 35);
	set("long",
		"这个刘书记是户部里最小的一名官员，掌管玩家的户口。\n");
	set("combat_exp", 1500);
	set("attitude", "friendly");
	set("inquiry", ([
		"改名" : "要改名先得交钱。",
	]));
	
	setup();
	carry_object("/clone/misc/cloth")->wear();
}

void init()
{
	object ob;
	
	::init();
	if (interactive(ob = this_player()) && !is_fighting()) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}

	add_action("do_name","改");
}

void greeting(object ob)
{
	if (!ob || environment(ob) != environment())
		return;
	switch(random(2)) {
	case 0 :
		say("刘书记笑眯眯地说道：这位" + RANK_D->query_respect(ob) +
			"，快请进来歇口气吧。\n");
		break;
	case 1 :
		say("刘书记说道：哟！这位" + RANK_D->query_respect(ob) + 
			"您来了啊！您要改名吗？\n");
		break;
	}
}

int accept_object(object who, object ob)
{
	
	if (ob->query("money_id") && ob->value() >= 1000000)
	{
		tell_object(who, "刘书记笑眯眯地说到：好吧，让我们看看您想取个什么样的新名字。\n");
		tell_object(who, "请键入：改 新的中文名字\n");
		who->set_temp("fee_paid",1);
		return 1;
	}
	else if (ob->query("money_id") && ob->value() < 1000000) 
	{
		tell_object(who, "刘书记嘿嘿一笑，说道：给我这麽多钱？ 将来我可没法还你啊。\n");
		return 1;
	}

	return 0;
}

int do_name(string target)
{
	object me;
	string old_name;

	me = this_player();
	old_name = me->query("name");

	if( !me->query_temp("fee_paid") ) 
		return notify_fail("刘书记冷冷地说道：不管叫我做什麽，您可得先付钱哪！\n");

	if( !target || target==" ") 
		return notify_fail("刘书记迷惑不解地说道：快告诉我您新的名字呀！\n");

	if( old_name == target )
		return notify_fail("刘书记奇怪地对你说到：您的钱是不是来得太容易了！\n");

	command("chat " + old_name + "从现在开始改名为：" + target + "。大家以后别认错了人！\n");
	me->delete_temp("fee_paid");
	me->set("name", target);
		
	return 1;
}