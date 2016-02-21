
#include <ansi.h>

inherit NPC;
inherit F_DEALER;
inherit F_UNIQUE;
int ask_weiwang();

void create()
{
	set_name("钱老本", ({"qian laoben", "qian", "laoben"}));
	set("title", "钱庄老板");
	set("gender", "男性");
	set("age", 34);

	set("str", 22);
	set("int", 24);
	set("dex", 18);
	set("con", 18);

	set("qi", 500); 
	set("max_qi", 500);
	set("jing", 100);
	set("max_jing", 100);
	set("shen", 0);

	set("combat_exp", 50000);
	set("shen_type", 1);
	set("attitude", "friendly");
	set("env/wimpy", 50);
	set("chat_chance", 5);
	set("chat_msg", ({
	"钱老本说道：我叫钱老本，就是因为做生意连老本也赔了。\n",
	"钱老本笑着说道：在本店存钱利息至少百分之一，客官您只管存吧。\n",
	"钱老本说：只有对本派弟子我才这么客气，对别的人啊，哼哼......\n",
	"钱老本突然说道: 江湖威望很重要，威望值高大有好处啊。\n",
        "钱老本突然说：五人分开一首诗，身上洪英无人知。\n",
	}));
        set("inquiry", ([
		"利息" :  "\n想要利息先入会！\n",
		"陈近南" :  "\n想见总舵主可没那么容易。\n",
		"天地会" :  "\n只要是英雄好汉，都可以入我天地会(join tiandihui)。\n",
		"加入" :  "\n只要入了我天地会，可以向会中各位好手学武艺。\n",
		"入会" :  "\n只要入了我天地会，可以向会中各位好手学武艺。\n",
                "威望" :  (: ask_weiwang :),
                "江湖威望" : (: ask_weiwang :),
       ]) );

	set_skill("unarmed", 50);
	set_skill("dodge", 50);
	set_temp("apply/attack", 100);
	set_temp("apply/defense", 100);
	set_temp("apply/damage", 40);

	setup();
	carry_object("/clone/misc/cloth")->wear();
	add_money("gold", 5);
}

void init()
{
	add_action("do_check", "check");
	add_action("do_check", "chazhang");
	add_action("do_convert", "convert");
	add_action("do_convert", "duihuan");
	add_action("do_deposit", "deposit");
	add_action("do_deposit", "cun");
	add_action("do_withdraw", "withdraw");
	add_action("do_withdraw", "qu");
	add_action("do_join","join");
	delete_temp("busy");
}

int ask_weiwang()
{
command("tell "+this_player()->query("id")+" 你现在的江湖威望是 " +(string)(this_player()->query("weiwang")));
say("\n钱老本说：如果你威望值很高，有些人见了你不但不会杀你，还会教你武功，送你宝贝。\n"
+"而且你还可以加入帮会，率领会众去攻打目标，就连去钱庄取钱也会有利息 。。。。。\n");
say("钱老本又说：杀某些坏人或救某些好人可以提高江湖威望。\n");
return 1;
}

void enough_rest()
{
	delete_temp("busy");
}


int do_check()
{
	// here we use 3 units to display bank infos
	int total = (int)this_player()->query("balance");
	
	if (!total || total < 0) {
		this_player()->set("balance", 0);
		return notify_fail("您在敝商号没有存钱。\n");
	}
	write("钱老本悄悄告诉你：您在弊商号共存有" + 
		MONEY_D->money_str(total) + "\n");

	return 1;
}
int do_convert(string arg)
{
	string from, to;
	int amount, bv1, bv2;
	object from_ob, to_ob;
	object me;
	
	if (query_temp("busy"))
		return notify_fail("哟，抱歉啊，我这儿正忙着呢……您请稍候。\n");

	me = this_player();

	if (!arg || sscanf(arg, "%d %s to %s", amount, from, to) != 3)
	{
		return notify_fail("命令格式：convert|duihuan <数量> <货币单位> to <新货币单位>\n");
	}

	from_ob = present(from + "_money", me);
	to_ob = present(to + "_money", me);

	if (!to_ob && file_size("/clone/money/" + to + ".c") < 0)
	{
		return notify_fail("你想兑换成什么？\n");
	}
	if (!from_ob)
	{
		return notify_fail("你身上没有带这种钱。\n");
	}
	if (amount < 1)
	{
		return notify_fail("你想白赚啊？\n");
	}
	if ((int)from_ob->query_amount() < amount)
	{
		return notify_fail("你带的" + from_ob->query("name") + "不够。\n");
	}
	
	bv1 = from_ob->query("base_value");
	if (!bv1)
	{
		return notify_fail("这样东西不值钱。\n");
	}

	bv2 = to_ob ? to_ob->query("base_value") : call_other("/clone/money/" + to, "query", "base_value" );
	
	if (bv1 < bv2)
		amount -= amount % (bv2 / bv1);	

	if (amount == 0)
	{
		return notify_fail("这些" + from_ob->query("name") + "不够换。\n");
	}

	// allowed to convert now
	set_temp("busy", 1);	

	from_ob->add_amount(-amount);

	if (!to_ob) {
		to_ob = new("/clone/money/" + to);
		to_ob->set_amount(amount * bv1 * 9 / (bv2 * 10));
		to_ob->move(me);
	}
	else
		to_ob->add_amount(amount * bv1 * 9 / (bv2 * 10));
	
	message_vision(sprintf("$N从身上取出%s%s%s，换成了%s%s%s。\n",
	chinese_number(amount), from_ob->query("base_unit"), from_ob->query("name"),
	chinese_number(amount * bv1 * 9 / (bv2 * 10)), to_ob->query("base_unit"), 
	to_ob->query("name")), me);

//	from_ob->add_amount(-amount);

	remove_call_out("enough_rest");
	call_out("enough_rest", 5);

	return 1;
}


int do_deposit(string arg)
{
	string what;
	int amount;
	object what_ob, me;

	if (query_temp("busy"))
		return notify_fail("哟，抱歉啊，我这儿正忙着呢……您请稍候。\n");

	me = this_player();
	if (!arg || sscanf(arg, "%d %s", amount, what) != 2)
	{
		return notify_fail("命令格式：deposit:cun <数量> <货币单位>\n");
	}

	what_ob = present(what + "_money", me);
	if (!what_ob)
	{
		return notify_fail("你身上没有带这种钱。\n");
	}
	if (amount < 1)
	{
		return notify_fail("你想存多少" + what_ob->query("name") + "？\n");
	}
	if ((int)what_ob->query_amount() < amount)
	{
		return notify_fail("你带的" + what_ob->query("name") + "不够。\n");
	}

	// deposit it
	set_temp("busy", 1);	

	me->add("balance", what_ob->query("base_value") * amount);
	what_ob->add_amount(-amount);
	message_vision(sprintf("$N拿出%s%s%s，存进了银号。\n", 
	chinese_number(amount), what_ob->query("base_unit"), 
	what_ob->query("name")), me);

	remove_call_out("enough_rest");
	call_out("enough_rest", 5);

return 1;
}

/*
int do_withdraw(string arg)
{
	int amount, v;
	string what;
	object me;

	if (query_temp("busy"))
		return notify_fail("哟，抱歉啊，我这儿正忙着呢……您请稍候。\n");

	me = this_player();

	if (!arg || sscanf(arg, "%d %s", amount, what) != 2)
	{
		return notify_fail("命令格式：withdraw|qu <数量> <货币单位>\n");
	}
	if (amount < 1)
	{
		return notify_fail("你想取出多少钱？\n");
	}
	if (file_size("/clone/money/" + what + ".c") < 0)
	{
		return notify_fail("你想取出什么钱？\n");
	}
	what = "/clone/money/" + what;
	if ((v = amount * what->query("base_value")) > me->query("balance"))
	{
		return notify_fail("你存的钱不够取。\n");
	}
	
	if(v>30000) 
	{
	if((int)me->query("weiwang")>=50)
	return notify_fail("\n钱老本怒道：身为天地会弟子，你还敢如此挥霍！一次最多取三两黄金！\n");
	}
	set_temp("busy", 1);	

	me->add("balance",  -v);
	if((int)me->query("weiwang")>=50)
	{
	MONEY_D->pay_player(me, v = v * ((((int)me->query("weiwang")-40)/10)+100)/ 100);
	message_vision(sprintf("$N从银号里取出%s。\n", MONEY_D->money_str(v)),
		me);
	message_vision("\n$N发现果然有利息，高兴得跳了起来！", me);
        command("goodkid "+this_player()->query("id"));
	}
	else 
	{
	message_vision("\n钱老本说: 想白赚啊？对不起，你在本庄取钱没利息。\n",me); 
	MONEY_D->pay_player(me, v = v * 4/5);
	message_vision(sprintf("$N从银号里取出%s。\n", MONEY_D->money_str(v)),
		me);
	}
	remove_call_out("enough_rest");
	call_out("enough_rest", 5);
return 1;
}

*/

int do_withdraw(string arg)
{
	int amount, v;
	string what;
	object me;

	if (query_temp("busy"))
		return notify_fail("哟，抱歉啊，我这儿正忙着呢……您请稍候。\n");

	me = this_player();

//	if( (int)me->query("balance") > 200000 )
//	{
//		me->set("balance",200000);
//		return notify_fail("你以前存的多于20两黄金的钱被官府没收了.\n");
//	}
	
	if (!arg || sscanf(arg, "%d %s", amount, what) != 2)
	{
		return notify_fail("命令格式：withdraw|qu <数量> <货币单位>\n");
	}
	if (amount < 1)
	{
		return notify_fail("你想取出多少钱？\n");
	}
	if (file_size("/clone/money/" + what + ".c") < 0)
	{
		return notify_fail("你想取出什么钱？\n");
	}
	what = "/clone/money/" + what;
	if ((v = amount * what->query("base_value")) > me->query("balance"))
	{
		return notify_fail("你存的钱不够娶。\n");
	}

	set_temp("busy", 1);	

	me->add("balance",  -v);
	MONEY_D->pay_player(me, v = v * 8 / 10);
	
	message_vision(sprintf("$N从银号里取出%s。\n", MONEY_D->money_str(v)),
		me);

	remove_call_out("enough_rest");
	call_out("enough_rest", 5);
	return 1;
}

int do_join(string arg)
{
   object ob ;
   ob = this_player () ;
   if( !arg || arg!="tiandihui" )
	return notify_fail("你要加入什么组织？\n"); 
   if (ob->query("weiwang")<20)
        {
	command("tell "+this_player()->query("id")+" 你现在的江湖威望是 " +(string)(this_player()->query("weiwang")));
	message_vision(HIC "钱老本对$N摇了摇头说：你的江湖威望值太低。\n" NOR,this_player());
  	return 1;
  	}
   if (ob->query("combat_exp")<20000)
        {
	message_vision(HIC "钱老本对$N摇了摇头说：你的实战经验太低。\n" NOR,this_player());
  	return 1;
  	}
    if(ob->query("weiwang")<50)
    {
    ob->set("weiwang",50);
    message_vision(HIC "$N的江湖威望提高了！\n" NOR,this_player());
    command("tell "+this_player()->query("id")+" 你现在的江湖威望是 " +(string)(this_player()->query("weiwang")));
    return 1;	
    }
    else message_vision(HIC "钱老本对$N摇了摇头说：你已经入过天地会了。\n" NOR,this_player());
    return 1;
}
