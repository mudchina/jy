//zhangwuji.c

#include <ansi.h>

inherit F_MASTER;
inherit F_UNIQUE;
inherit NPC;

void greeting(object ob);
void create()
{
    seteuid(getuid());
	set_name("张无忌", ({ "zhang wuji", "zhang", "wuji" }));
	set("long", "明教教主张无忌，统领天下十万教众，豪气干云，叱咤千秋，\n"
               +"「九阳神功」、「乾坤大挪移」独步天下，是江湖中不世出的\n"
               +"少年英雄。\n");
    set("title","明教教主");
	set("gender", "男性");
    set("age", 20);
	set("shen_type",1);
    set("attitude", "friendly");

    set("str", 30);
    set("int", 30);
    set("con", 30);
    set("dex", 30);

    set("qi", 3050);
    set("max_qi", 3050);
    set("jing", 3050);
    set("max_jing", 3050);
    set("neili", 5000);
    set("max_neili", 5000);
    set("jiali", 120);

    set("combat_exp", 2900000);
    set("score", 455000);
    
	set_skill("force", 350);
    set_skill("unarmed", 240);
    set_skill("dodge", 500);
    set_skill("parry", 255);
    set_skill("hand",370);
    set_skill("sword",400);
    set_skill("blade", 370);
    set_skill("jiuyang-shengong", 480);
//  set_skill("qiankun-danuoyi", 500);
//  set_skill("qishang-quan", 170);
//  set_skill("wuxue-xinfa", 485);
    set_skill("taiji-quan",200);
    set_skill("taiji-jian",200);
    set_skill("taiji-dao",200);

	map_skill("force", "jiuyang-shengong");
//	map_skill("dodge", "qiankun-danuoyi");
//	map_skill("unarmed", "qishang-quan");
	map_skill("hand", "taiji-quan");
	map_skill("sword","taiji-jian");
	map_skill("blade","taiji-dao");

    create_family("明教",34, "教主");

		set("chat_chance",3000);
//        set("chat_msg",({
//            "张无忌愤然说道“大丈夫当以国为家, 捐躯沙场, 抗元大业未成, 同辈仍需努力!”\n",
//            "张无忌叹道“人生失一知己, 生亦何欢, 死亦何忧, 敏儿, 你在哪里?”\n",
//            "张无忌道“我教兄弟听了: 生于乱世, 当克己为公, 行侠仗义, 荡寇驱魔!”\n",
//        	(: random_move :)
//		}));

	set("inquiry",([
	  "明教" : "明教正在编写之中，请君稍候。\n",
//    "金毛狮王" :
//    "谢逊" :
		]));
		setup();
		carry_object("/d/mingjiao/obj/yitianjian")->wield();
//    	carry_object("/d/mingjiao/obj/jiaozhumingpao")->wear();
		add_money("gold",70);
}

void init()
{
	object ob;

	::init();

	if( interactive(ob=this_player()) && !is_fighting())
	{
		remove_call_out("greeting");
		call_out("greeting",1,ob);
	}
}

void greeting(object ob)
{
	if(!ob || environment(ob)!=environment()) return;
	if((int)ob->query("shen")<-50000)
	{
//      command("say
		command("wield yitian jian");
		command("hit"+(string)ob->query("id"));
		command("unwield uitian jian");
	}
	else if((int)ob->query("shen")<-5000)
	{
		command("say 魔从心起，于武学不利，其道必诛，劝君放下屠刀，立地成佛.");
	}
	else if((int)ob->query("shen")<-100)
	{
		command("say 这位朋友，人行江湖，言行当正，切务走进邪魔歪道.");
	}
	else if((int)ob->query("shen")>=0)
	{
		command("say 光明正道任人走，劝君多加保重.");
	}
	else if((int)ob->query("shen")>10000)
	{
		command("say 大侠在上，受无忌一礼，大侠它日必为武林翘楚.");
	}
	return;
}



void attempt_apprentice(object ob)
{
	if((int)ob->query("int")<30)
	{
		command("say 你的悟性太低了，不适合学习我的功夫。");
		return 0;
	}
	if((string)ob->query("gender")!="男性")
	{
		command("say 你阳气不足，习我功夫恐将走火如魔。");
		return 0;
	}
	if((int)ob->query("shen") <= 15000)
	{
		command("say 你应当多作些行侠仗义的事，以修身心。");
		return 0;
	}
	command("say 好，我就收下你这位好兄弟");
	command("say 再接再砺！");
	return;
}

int accept_fight(object ob)
{
    if(((int)ob->query("combat_exp")<30000)&&((int)ob->query("shen")>0))
    {
        message_vision("武林中人最忌争强斗狠，你不是我的对手，回去吧。\n",ob);
        return 0;
    }
    message_vision("张无忌一拱手说道：这位"+RANK_D->query_respect(ob)+
	"，在下领教了。\n", ob);
    return 1;
}


