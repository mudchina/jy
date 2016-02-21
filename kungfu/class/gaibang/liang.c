// sample master.c code
// xiake island master.c

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("梁长老", ({"liang zhanglao", "liang", "zhanglao"}));
	set("title", "丐帮九袋长老");
	set("nickname", "传功长老");
	set("gender", "男性");
	set("age", 55);
	set("long", 
		"梁长老是丐帮出道最久，武功最高的长老，在武林中享名已久。\n"
		"丐帮武功向来较强，近来梁长老一力整顿，更是蒸蒸日上。\n");

	set("attitude", "peaceful");
	
	set("str", 28);
	set("int", 24);
	set("con", 24);
	set("dex", 25);

	set("qi", 900);
	set("max_qi", 900);
	set("jing", 400);
	set("max_jing", 400);
	set("neili", 1000);
	set("max_neili", 1000);
	set("jiali", 120);
	
	set("combat_exp", 250000);
	
	set_skill("force", 100); 
	set_skill("huntian-qigong", 105); 
	set_skill("unarmed", 115); 
	set_skill("xianglong-zhang", 110); 
	set_skill("dodge", 97); 
	set_skill("xiaoyaoyou", 90); 
	set_skill("parry", 80); 
	set_skill("staff", 90); 
	set_skill("dagou-bang", 90); 
	set_skill("begging", 80); 
	set_skill("checking", 90);
	
	map_skill("force", "huntian-qigong");
	map_skill("unarmed", "xianglong-zhang");
	map_skill("staff", "dagou-bang");
	map_skill("parry", "xianglong-zhang");
	map_skill("dodge", "xiaoyaoyou");
	
	create_family("丐帮", 18, "九袋长老");

	set("chat_chance_combat", 20);
	set("chat_msg_combat", ({
		(: perform_action, "unarmed.xianglong" :),
		(: exert_function, "recover" :),
	}) );

	setup();
}

void init()
{
        object ob;
	mapping myfam;
        
        ::init();
        if (interactive(ob = this_player()) && !is_fighting()) 
	{
		myfam = (mapping)ob->query("family");
		if (!myfam || myfam["family_name"] != "丐帮")
		{
			remove_call_out("saying");
			call_out("saying",1,ob);
		}
        }
}

void saying(object ob)
{
        if (!ob || environment(ob) != environment()) return;

	message_vision("\n粱长老看到$N闯进来，大喝一声：你不是丐帮弟子，给我滚出去！\n\n", ob);
	call_out("kicking", 0, ob);	
}

void kicking(object ob)
{
        if (!ob || environment(ob) != environment()) return;

	ob->move("/d/gaibang/inhole");
	message("vision","只听“乒”地一声，" + ob->query("name") +
		"从小门里飞了出来。\n", environment(ob), ob);
}

void attempt_apprentice(object ob)
{
	if ((int)ob->query("str") < 25) {
		command("say 我们丐帮的武艺一向以刚猛为主，" + 
		RANK_D->query_respect(ob) + "臂力太弱，似乎不宜学丐帮的功夫？");
		return;
	}

	command("say 好吧，希望" + RANK_D->query_respect(ob) +
	"能好好学习本门武功，将来在江湖中闯出一番作为。");
	command("recruit " + ob->query("id"));
	if((string)ob->query("class") != "beggar")
		ob->set("class", "beggar");
}
