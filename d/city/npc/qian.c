// banker.c
// originally coded by xiang
// 96-02-16 YZC fixed some math problem

inherit NPC;
inherit F_DEALER;

void create()
{
	set_name("Ç®ÑÛ¿ª", ({"qian yankai", "qian", "yankai"}));
	set("title", "Ç®×¯ÀÏ°å");
	set("nickname", "Ìú¹«¼¦");
	set("gender", "ÄĞĞÔ");
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
	set("chat_chance", 2);
	set("chat_msg", ({
	"Ç®ÑÛ¿ª½¾°ÁµÄËµµÀ£º±¾ÒøºÅÒÑ¾­ÓĞÉÏ°ÙÄêµÄÀúÊ·£¬ÔÚ½­ÄÏ¿ÉÒÔËµÊÇµÚÒ»¼Ò¡£\n",
	"Ç®ÑÛ¿ªĞ¦×ÅËµµÀ£ºÔÚ±¾µê´æÇ®ÎŞÀûÏ¢£¬È¡Ç®ÊÕÊ®·ÖÖ®¶şµÄÊÖĞø·Ñ£¬¿Í¹ÙÄú¿´×Å°ì°É¡£\n"
	"Ç®ÑÛ¿ªÎ¢Î¢Ò»Ğ¦£¬ËµµÀ£º±¾µê»¹°ìÀí²»Í¬Ãæ¶î»õ±ÒµÄ¶Ò»»ÒµÎñ£¬µ«Ã¿´ÎÒªÊÕÊ®·ÖÖ®Ò»µÄÊÖĞø·Ñ¡£\n"
	}));

	set_skill("unarmed", 50);
	set_skill("dodge", 50);
	set_temp("apply/attack", 100);
	set_temp("apply/defense", 100);
	set_temp("apply/damage", 40);

	setup();
	add_money("silver", 10);
	carry_object("/clone/misc/cloth")->wear();
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
	delete_temp("busy");
}

void enough_rest()
{
	delete_temp("busy");
}

int do_check()
{
	// here we use 3 units to display bank infos
	int total = (int)this_player()->query("balance");
//	if (total>200000) {
//		this_player()->set("balance", 200000);
//		return notify_fail("ÄúÔÚ±ÖÉÌºÅ´æÇ® 20Á½»Æ½ğ¡£\n");
//	}
	if (!total || total < 0) {
		this_player()->set("balance", 0);
		return notify_fail("ÄúÔÚ±ÖÉÌºÅÃ»ÓĞ´æÇ®¡£\n");
	}
	write("Ç®ÑÛ¿ªÇÄÇÄ¸æËßÄã£ºÄúÔÚ±×ÉÌºÅ¹²´æÓĞ" + 
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
		return notify_fail("Ó´£¬±§Ç¸°¡£¬ÎÒÕâ¶ùÕıÃ¦×ÅÄØ¡­¡­ÄúÇëÉÔºò¡£\n");

	me = this_player();

	if (!arg || sscanf(arg, "%d %s to %s", amount, from, to) != 3)
	{
		return notify_fail("ÃüÁî¸ñÊ½£ºconvert|duihuan <ÊıÁ¿> <»õ±Òµ¥Î»> to <ĞÂ»õ±Òµ¥Î»>\n");
	}

	from_ob = present(from + "_money", me);
	to_ob = present(to + "_money", me);

	if (!to_ob && file_size("/clone/money/" + to + ".c") < 0)
	{
		return notify_fail("ÄãÏë¶Ò»»³ÉÊ²Ã´£¿\n");
	}
	if (!from_ob)
	{
		return notify_fail("ÄãÉíÉÏÃ»ÓĞ´øÕâÖÖÇ®¡£\n");
	}
	if (amount < 1)
	{
		return notify_fail("ÄãÏë°××¬°¡£¿\n");
	}
	if ((int)from_ob->query_amount() < amount)
	{
		return notify_fail("Äã´øµÄ" + from_ob->query("name") + "²»¹»¡£\n");
	}
	
	bv1 = from_ob->query("base_value");
	if (!bv1)
	{
		return notify_fail("ÕâÑù¶«Î÷²»ÖµÇ®¡£\n");
	}

	bv2 = to_ob ? to_ob->query("base_value") : call_other("/clone/money/" + to, "query", "base_value" );
	
	if (bv1 < bv2)
		amount -= amount % (bv2 / bv1);	

	if (amount == 0)
	{
		return notify_fail("ÕâĞ©" + from_ob->query("name") + "²»¹»»»¡£\n");
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
	
	message_vision(sprintf("$N´ÓÉíÉÏÈ¡³ö%s%s%s£¬»»³ÉÁË%s%s%s¡£\n",
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
		return notify_fail("Ó´£¬±§Ç¸°¡£¬ÎÒÕâ¶ùÕıÃ¦×ÅÄØ¡­¡­ÄúÇëÉÔºò¡£\n");

	me = this_player();

	if (!arg || sscanf(arg, "%d %s", amount, what) != 2)
	{
		return notify_fail("ÃüÁî¸ñÊ½£ºdeposit:cun <ÊıÁ¿> <»õ±Òµ¥Î»>\n");
	}

	what_ob = present(what + "_money", me);
	if (!what_ob)
	{
		return notify_fail("ÄãÉíÉÏÃ»ÓĞ´øÕâÖÖÇ®¡£\n");
	}
	if (amount < 1)
	{
		return notify_fail("ÄãÏë´æ¶àÉÙ" + what_ob->query("name") + "£¿\n");
	}
	if ((int)what_ob->query_amount() < amount)
	{
		return notify_fail("Äã´øµÄ" + what_ob->query("name") + "²»¹»¡£\n");
	}
	if( (int)me->query("balance") > 200000 )
	{
		me->set("balance",200000);
		return notify_fail("ÄãÒÔÇ°´æµÄ¶àÓÚ20Á½»Æ½ğµÄÇ®±»¹Ù¸®Ã»ÊÕÁË.\n");
	}
	if( ( (int)me->query("balance") + (int)what_ob->query("base_value")*amount ) >200000  )
	{	
		return notify_fail("Äã×Ü¹²Ö»ÄÜ´æ20Á½»Æ½ğ! ÓÃcheck¿´¿´ÄãÒÑ¾­´æÁË¶àÉÙÁË°É¡£ \n");
	}
	// deposit it
	set_temp("busy", 1);	

	me->add("balance", what_ob->query("base_value") * amount);
	what_ob->add_amount(-amount);
	message_vision(sprintf("$NÄÃ³ö%s%s%s£¬´æ½øÁËÒøºÅ¡£\n", 
	chinese_number(amount), what_ob->query("base_unit"), 
	what_ob->query("name")), me);

	remove_call_out("enough_rest");
	call_out("enough_rest", 5);
	return 1;
}

int do_withdraw(string arg)
{
	int amount, v;
	string what;
	object me;

	if (query_temp("busy"))
		return notify_fail("Ó´£¬±§Ç¸°¡£¬ÎÒÕâ¶ùÕıÃ¦×ÅÄØ¡­¡­ÄúÇëÉÔºò¡£\n");

	me = this_player();

//	if( (int)me->query("balance") > 200000 )
//	{
//		me->set("balance",200000);
//		return notify_fail("ÄãÒÔÇ°´æµÄ¶àÓÚ20Á½»Æ½ğµÄÇ®±»¹Ù¸®Ã»ÊÕÁË.\n");
//	}
	
	if (!arg || sscanf(arg, "%d %s", amount, what) != 2)
	{
		return notify_fail("ÃüÁî¸ñÊ½£ºwithdraw|qu <ÊıÁ¿> <»õ±Òµ¥Î»>\n");
	}
	if (amount < 1)
	{
		return notify_fail("ÄãÏëÈ¡³ö¶àÉÙÇ®£¿\n");
	}
	if (file_size("/clone/money/" + what + ".c") < 0)
	{
		return notify_fail("ÄãÏëÈ¡³öÊ²Ã´Ç®£¿\n");
	}
	what = "/clone/money/" + what;
	if ((v = amount * what->query("base_value")) > me->query("balance"))
	{
		return notify_fail("Äã´æµÄÇ®²»¹»È¢¡£\n");
	}

	set_temp("busy", 1);	

	me->add("balance",  -v);
	MONEY_D->pay_player(me, v = v * 8 / 10);
	
	message_vision(sprintf("$N´ÓÒøºÅÀïÈ¡³ö%s¡£\n", MONEY_D->money_str(v)),
		me);

	remove_call_out("enough_rest");
	call_out("enough_rest", 5);
	return 1;
}
ÿ