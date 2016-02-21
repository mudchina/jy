// dunan.c

inherit NPC;
inherit F_MASTER;

string ask_me();

void create()
{
	set_name("渡难", ({ "du nan", "nan" }) );
	set("title", "少林长老");
	set("gender", "男性");
	set("age", 90);
	set("long",
		"这是一个面颊深陷，瘦骨零丁的老僧，他脸色漆黑，象是生铁铸成。\n");

	set("attitude", "peaceful");
	set("combat_exp", 1000000);
	set("score", 200000);

	set("str", 30);
	set("int", 30);
	set("cor", 30);
	set("cps", 30);
	set("con", 30);

	set("qi", 4000);
	set("max_qi", 2000);
	set("neili", 4000);
	set("max_neili", 2000);
	set("jiali", 80);

	create_family("少林派", 35, "弟子");
	assign_apprentice("弟子", 0);

	set_skill("force", 150);
	set_skill("whip", 160);
	set_skill("parry", 180);
	set_skill("dodge", 180);

	set_skill("hunyuan-yiqi", 150);
	set_skill("riyue-bian", 200);
	set_skill("shaolin-shenfa", 180);

	map_skill("force", "hunyuan-yiqi");
	map_skill("whip",  "riyue-bian");
	map_skill("parry", "riyue-bian");
	map_skill("dodge", "shaolin-shenfa");

	set("inquiry", ([
		"菩提子"     : (: ask_me :),
	]));

	set("count", 1);

	set("chat_chance_combat", 50);
	set("chat_msg_combat", ({
		(: perform_action, "whip.chan" :),
		(: exert_function, "recover" :),
	}) );

	setup();

	carry_object("/d/shaolin/obj/changbian")->wield();
}

void init()
{
	object me, ob;
	mapping fam;

	me = this_player();
	ob = this_object();

	::init();
	if( interactive(me) ) 
	{
		if ( mapp(fam = me->query("family")) && fam["family_name"] == "少林派" 
		&& fam["generation"] == 36 ) return;

		if ( mapp(fam = me->query("family")) && fam["family_name"] == "少林派" 
		&& fam["generation"] > 36 		
		&& me->query("qi") < 50 ) 
		{
			me->move("/d/shaolin/qyping");
			me->unconcious();
			return;
		}

		COMBAT_D->do_attack(ob, me, query_temp("weapon") );

		me->set_temp("fighter", 1);
		
		ob->fight_ob(me);
		me->fight_ob(ob);

		call_out("halt", 10);

		return;
	}

	return;
}

void halt()
{
	command("halt");
}

string ask_me()
{
	mapping fam; 
	object ob;
	
	if ( !this_player()->query_temp("fighter") 
	||    this_player()->query("combat_exp") < 5000 )
	{
		command("say 大胆鼠辈，乳臭未干，竟敢偷入金刚伏魔圈，且让老衲来超度与你！");
		this_object()->kill_ob(this_player());
		this_player()->kill_ob(this_object());
	}

	if ( present("puti zi", this_player()) )
		return RANK_D->query_respect(this_player()) + 
		"菩提子只有一颗，而且就在你身上，真是贪得无餍！";

	if ( present("puti zi", environment()) )
		return RANK_D->query_respect(this_player()) + 
		"菩提子只有一颗，而且就在这里任你取走，真是贪得无餍！";

	if (query("count") < 1)
		return "菩提子乃天地之灵物，采集艰难无比，我这里现在可没有。";

	if(random((int)this_player()->query("kar")) < 24)
	{
		command("kick " + this_player()->query("id"));
		this_player()->set_temp("marks/no_putizi",1);
		return "哼！";
	}
	else if(this_player()->query_temp("marks/no_putizi",1))
		return "不是说过没有吗，歪缠什么？？";

	ob = new("/d/shaolin/obj/puti-zi");
	ob->move(this_player());

	add("count", -1);

	message_vision("\n渡难惨然一笑，接着长叹一声，从树洞里取出个白玉磁瓶，倒出菩提子递给$N。\n\n", this_player());

	return "我等昔年于佛祖座前发下宏愿，每十年遍访名山大川，历尽艰险，\n" +
	       "方采得数颗菩提子，君乃有缘人，能得此造化奇物，望好自为之！";
}

#include "/kungfu/class/shaolin/du.h"
