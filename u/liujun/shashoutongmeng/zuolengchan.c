inherit NPC;
#include <ansi.h>
int time_period(int timep, object me);
string join_me(object me);
int give_quest();
void create()
{
	set_name("左冷禅", ({ "zuo lengchan","zuo" }) );
	set("title", "");
	set("long","\n");

	set("gender", "男性" );
	set("age", 40);

	set("str", 30);
	set("int", 23);
	set("dex", 30);
	set("con", 30);

	set("combat_exp", 2000000);
	set("attitude", "heroism");

	set("qi", 5000);
	set("max_qi", 5000);
	set("max_jing", 3000);
	set("jing", 3000);
	set("max_neili",3000);
	set("neili",3000);
	set("jiali",100);

	set("food", 100000000);
	set("water", 100000000);

//	set("inquiry", ([
//		"join": (: join_me :),
//		"天杀门": "你敢乱说, 小心老子宰了你! \n",
//	]) );

	set_skill("sword", 150);
	set_skill("unarmed", 150);
	set_skill("damo-jian", 180);
	set_skill("dodge", 150);
	set_skill("shaolin-shenfa", 100);
	map_skill("dodge", "shaolin-shenfa");
	map_skill("sword", "damo-jian");

	setup();
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/clone/misc/cloth")->wear();
}

int accept_fight(object me)
{
	command("say 小子！你不要命了！");
	return 0;
}

void init()
{
	add_action("give_quest", "quest");
}

string join_me(object me)
{
	if((me->query("quest")))
		return  "这位" + RANK_D->query_respect(me) + ", 你已经是咱们的弟兄了。";
	else
		return "哦...加入是有风险的哟...";
}

int give_quest()
{
	mapping quest ;
	object me;
	int j, combatexp, timep, factor, num;
	string tag = "1000000";
	string *levels = ({
		"1000",
//		"1500",
		"2000",
		"3000",
		"5000",
		"8000",
		"10000",
		"13000",
		"17000",
		"22000",
		"30000",
		"45000",
		"60000",
		"80000",
		"100000",
		"200000",
		"350000",
		"600000",
		"1000000"
	});
	me = this_player();
	combatexp = (int)me->query("combat_exp");

	if(combatexp < 1000)
	{
		message_vision("左冷禅对$N哼了一声道: 小子自不量力！\n", me);
		return 1;
	}
 
// Let's see if this player still carries an un-expired task
	if((quest =  me->query("quest")))
	{
		if( ((int)me->query("task_time")) >  time() )
			return 0;
		else
		{
			message_vision("左冷禅对$N哼了一声道: 真丢脸, 就再给你一次机会试试。\n", me);
			me->set("qi", (int)(me->query("qi")/2+10));
		}
	}

	for(j = sizeof(levels) - 1 ; j >= 0; j--)
	{
		if( atoi(levels[j])  <= combatexp )
		{
			num = j;
			factor = 10;
			break;
		}
	}
	if(num > 0)
	{
		if (random(50) > 45)
		{
			num = num - 1;
		}
	}
	else
	{
		if ((num < sizeof(levels) - 1) && (random(100) > 95))
		{
			num = num + 1;
			factor = 15;
		}
	}
	tag = levels[num];
	quest = QUEST_D(tag)->query_quest();
	timep = quest["time"];
/*
	while(quest["quest_type"] == "寻")
	{
		quest = QUEST_D(tag)->query_quest();
		timep = quest["time"];
	}
*/
	time_period(timep, me);
	if(quest["quest_type"] == "杀")
		tell_object(me, "杀了『" + quest["quest"] + "』为我一统江湖立功。\n" NOR);
	else if(quest["quest_type"] == "寻")
		tell_object(me, "请找回『" + quest["quest"] + "』为我一统江湖立功。\n" NOR);

	quest["exp_bonus"] = quest["exp_bonus"];
	quest["pot_bonus"] = quest["pot_bonus"];
	quest["score"] = quest["score"];

	me->set("quest", quest);
	me->set("task_time", (int)time() + (int)quest["time"]);
	me->set("quest_factor", factor);
	return 1;
}

int time_period(int timep, object me)
{
	int t, d, h, m, s;
	string time;
	t = timep;
	s = t % 60;             t /= 60;
	m = t % 60;             t /= 60;
	h = t % 24;             t /= 24;
	d = t;

	if(d)
		time = chinese_number(d) + "天";
	else
		time = "";

	if(h)
		time += chinese_number(h) + "小时";
	if(m)
		time += chinese_number(m) + "分";
	time += chinese_number(s) + "秒";

	tell_object(me, HIW "左冷禅说道：\n在" + time + "内");
		return 1;
}

int accept_object(object who, object ob)
{
	int bonus, exp, pot, score,factor;
	string test;
	mapping quest;

	if(!(quest =  who->query("quest")))
	{
		tell_object(who,"左冷禅说道：这不是我想要的。\n");
		return 1;
	}

	if( ob->name(1) != quest["quest"])
	{
		tell_object(who,"左冷禅说道：这不是我想要的。\n");
		return 1;
	}

	if ((int) who->query("task_time") < time() )
	{
		tell_object(who,"左冷禅说道：真可惜！你没有在指定的时间内回来！\n");
		destruct(ob);
		return 1;
	}

	else
	{
		tell_object(who,"左冷禅说道：很好！欢迎下次再来。\n");
		exp = quest["exp_bonus"]/2 + random(quest["exp_bonus"]/2);
		pot = quest["pot_bonus"]/2 + random(quest["pot_bonus"]/2);
		score = quest["score"]/2 + random(quest["score"]/2);
		factor=who->query("quest_factor");
		destruct(ob);

		if (factor)
		{
			exp=exp*factor/10;
			pot=pot*factor/10;
			score=score*factor/10;
		}

		bonus = (int) who->query("combat_exp");
		bonus += exp;
		who->set("combat_exp", bonus);
		bonus = (int) who->query("potential");
		bonus = bonus - (int) who->query("learned_points");
		bonus = bonus + pot;
		if( bonus > 100)
			bonus = 100;
		bonus += (int) who->query("learned_points");
		who->set("potential", bonus );
		bonus = (int) who->query("shen");
		if(bonus >= 0)
			bonus += score;
		else
			bonus -= score;
        	who->set("shen", bonus);
        	tell_object(who,HIW"你被奖励了：\n" + 
			chinese_number(exp) + "点实战经验\n" +
			chinese_number(pot) + "点潜能\n" +
			chinese_number(score)+"点神\n"
		NOR);
		who->set("quest", 0 );
		return 1;
	}
	return 1;
}