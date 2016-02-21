// hong.c 洪七公
inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("洪七公", ({"hong qigong", "hong", "qigong"}));
	set("nickname", "九指神丐");
	set("gender", "男性");
	set("age", 75);
	set("long", 
		"他就是丐帮第十七任帮主，号称“北丐”的洪七公老爷子。\n");
	set("attitude", "peaceful");
	
	set("str", 30);
	set("int", 24);
	set("con", 30);
	set("dex", 24);

	set("chat_chance", 1);
	set("chat_msg", ({
		"洪七公叹了口气道：“唉……何时能再吃到蓉儿做的「叫化鸡」啊……”\n",
		"洪七公说道：“俗话说「吃在江南」，所以老叫化特地跑来扬州看看。”\n",
		"洪七公喃喃道：“我们丐帮的「降龙十八掌」是天下最霸道的掌法。”\n",
	}));

	set("chat_chance_combat", 30);
	set("chat_msg_combat", ({
		(: perform_action, "unarmed.xianglong" :),
		(: exert_function, "recover" :),
	}) );

	set("inquiry", ([
		"青竹林" : "东北西北东西北。\n",
		"丐帮" : "东北西北东西北。\n",
		"拜师" : "你可以去东城门找我帮总舵的鲁有脚，拜他为师。\n",
	]));

	set("qi", 4000);
	set("max_qi", 4000);
	set("jing", 2500);
	set("max_jing", 2500);
	set("neili", 4000);
	set("max_neili", 4000);
	set("jiali", 300);
	
	set("combat_exp", 1500000);
	set("score", 200000);
	 
	set_skill("force", 170);             // 基本内功
	set_skill("huntian-qigong", 170);    // 混天气功
	set_skill("unarmed", 200);           // 基本拳脚
	set_skill("xianglong-zhang", 200);   // 降龙十八掌
	set_skill("dodge", 150);      	     // 基本躲闪
	set_skill("xiaoyaoyou", 150);        // 逍遥游
	set_skill("parry", 180);             // 基本招架
	set_skill("staff", 170);             // 基本棍杖
	set_skill("dagou-bang", 150);        // 打狗棒法
	set_skill("begging", 100);           // 叫化绝活
	set_skill("checking", 100);          // 道听途说
	
	map_skill("force", "huntian-qigong");
	map_skill("unarmed", "xianglong-zhang");
	map_skill("dodge", "xiaoyaoyou");
	map_skill("parry", "xianglong-zhang");
	map_skill("staff", "dagou-bang");
	
	create_family("丐帮", 17, "帮主");

	setup();
	
	carry_object(__DIR__"yuzhu_zhang");
	carry_object(__DIR__"jiaohuaji");
}

void attempt_apprentice(object ob)
{
	if ((int)ob->query_str() < 20 || (int)ob->query_con() < 20) {
		command("say 当叫化子需要能吃苦耐劳，依我看" + RANK_D->query_respect(ob) + "的资质似乎不适合当叫化子？");
		return;
	}

	if ((string)ob->query("family/family_name") != "" &&
	    (string)ob->query("family/family_name") != "丐帮") {
		command("say " + RANK_D->query_respect(ob) + "既然已有名师指点，何必又来拜老叫化呢？");
		return;
	}

	command("recruit " + ob->query("id"));

	if((string)ob->query("class") != "beggar")
		ob->set("class", "beggar");
	
}

int accept_object(object who, object ob)
{
	object ob_yzz, me = this_object();

	if (ob->query("food_supply") <= 0)
		return 0;
	if ((string)ob->query("name") != "叫化鸡") {
		command("say 老叫化对" + (string)ob->query("name") + "没什么兴趣……");
		return 0;
	}
	if (query("food") >= max_food_capacity() - ob->query("food_supply")) {
		command("say 老叫化现在饱得很。");
		return 0;
	}
	command("say 啊……这正是我想吃的叫化鸡呀！");
	command("eat ji");
	command("say 想不到你小小年纪，心思却很细，就跟当年的蓉儿一样！");

	if ((string)ob->query("family/family_name") != "" &&
	    (string)ob->query("family/family_name") != "丐帮") {
		command("say " + RANK_D->query_respect(ob) + "你还呆在这里干什么？");
		return 1;
	}

	if( ob_yzz = present("yuzhu_zhang", me) )
    {
		ob_yzz->move(who);
		write("这根竹杖跟随我多年了，就送给你作见面礼吧。");
        return 1;
    }

	else
	{
		write("不过你来得不是时候，玉竹杖已经给别人了。");
        return 1;
	}

//	command("recruit " + who->query("id"));
	return 1;
}