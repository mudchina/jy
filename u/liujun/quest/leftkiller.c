// /u/tiansha/npc/left_killer.c

inherit NPC;
#include <ansi.h>
int time_period(int timep, object me);
string join_me(object me);

void create()
{
	set_name("左三", ({ "leftkiller" }) );
	set("title", "天杀门左接引使");
	set("long",
		"天杀门左接引使负责向门下众杀手分派任务。\n");

	set("gender", "男性" );
	set("age", 28);

	set("str", 30);
	set("int", 23);
	set("cps", 3000);
	set("cor", 30);

	set("combat_exp", 200000000);
	set("attitude", "heroism");

	set("force", 1000);
	set("max_force", 1000);
	set("max_kee", 10000);
	set("force_factor", 10);

	set("food", 100000000);
	set("water", 100000000);

	set("inquiry", ([
		"join": (: join_me :),
		"天杀门": "你敢乱说, 小心老子宰了你! \n",
	]) );

	set_skill("sword", 120);
	set_skill("unarmed", 100);
	set_skill("six-chaos-sword", 100);
	set_skill("dodge", 150);
	set_skill("pyrobat-steps", 100);
	map_skill("dodge", "pyrobat-steps");
	map_skill("sword", "six-chaos-sword");

	setup();
	carry_object("/obj/weapon/longsword")->wield();
	carry_object("/obj/cloth")->wear();
}

int accept_fight(object me)
{
	command("say 小子！你赶惹天杀门, 不要命了！");
	return 0;
}

void init()
{
	add_action("give_quest", "quest");
}

string join_me(object me)
{
	if((me->query("quest")))
		return  "这位" + RANK_D->query_respect(me) + ", 你已经是天杀门的弟兄了。";
	else
		return "哦...加入天杀门是有风险的哟...";
}

int give_quest()
{
	mapping quest ;
	object me;
	int j, combatexp, timep, factor, num;
	string tag = "1000000";
	string *levels = ({
		"1000",
		"1500",
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
//		"350000",
//		"600000",
//		"1000000"
	});
	me = this_player();
	combatexp = (int)(me->query("combat_exp"));

	if(combatexp < 1000)
	{
		message_vision("左三对$N哼了一声道: 这种小角色还想进天杀门, 你也真好意思开口....\n", me);
		return 1;
	}
 
// Let's see if this player still carries an un-expired task
	if((quest =  me->query("quest")))
	{
		if( ((int)me->query("task_time")) >  time() )
			return 0;
		else
		{
			message_vision("左三对$N哼了一声道: 真给天杀门丢脸, 就再给你一次机会试试。\n", me);
			me->set("kee", (int)(me->query("kee")/2+10));
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

	while(quest["quest_type"] == "寻")
	{
		quest = QUEST_D(tag)->query_quest();
		timep = quest["time"];
	}

	time_period(timep, me);
	tell_object(me, "杀了『" + quest["quest"] + "』为天杀门立功。\n" NOR);
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

	tell_object(me, HIW "左三说道：\n在" + time + "内");
		return 1;
}