// bgargoyle.c

#include <ansi.h>
#include <command.h>
#include <login.h>

inherit NPC;

int ask_me();
int ask_bing();
object creat_weapon();

string *death_msg = ({
	HIB "黑无常说道：喂！新来的，你叫什么名字？\n\n" NOR,
	HIB "黑无常用奇异的眼光盯著你，好像要看穿你的一切似的。\n\n" NOR,
	HIB "黑无常「哼」的一声，从袖中掏出一本像帐册的东西翻看著。\n\n" NOR,
	HIB "黑无常合上册子，说道：咦？阳寿未尽？怎么可能？\n\n" NOR,
	HIB "黑无常搔了搔头，叹道：罢了罢了，你走吧。\n\n"
		"一股阴冷的浓雾突然出现，很快地包围了你。\n\n" NOR,
});

void create()
{
	set_name("黑无常", ({ "black gargoyle", "gargoyle" }) );
	set("long",
		"黑无常伸著长长的舌头瞪著你，黝黑的脸上看不出任何喜怒哀乐。\n");
	set("attitude", "peaceful");
	set("chat_chance", 15);
	set("chat_msg", ({
		"黑无常发出一阵像呻吟的声音，当他发现你正注视著他的时候，瞪了你一眼。\n",
		"黑无常把长长的舌头伸出来，缓缓地舔了舔自己又黑又长的手指。\n"
	}) );
	set("age", 217);
	set("combat_exp", 20000);
	set("max_jing", 900);
	set("max_qi", 900);
	set_skill("dodge", 40);
	set_skill("unarmed", 40);
	set_temp("apply/armor", 60);
	set_temp("apply/damage", 20);

	set("inquiry", ([
		"地刹炼魂"       : (: ask_me :),
		"兵器"		 : (: ask_bing :),
	]));

	setup();
}

void init()
{
	::init();
	if( !previous_object()
	||	!userp(previous_object()) )
		return;
	call_out( "death_stage", 5, previous_object(), 0 );
}

void death_stage(object ob, int stage)
{
	int i;
	object *inv;

	if( !ob || !present(ob) ) return;

	if( !ob->is_ghost() ) {
		command("say 喂！阳人来阴间做什么？");
		kill_ob(ob);
		ob->fight_ob(this_object());
		return;
	}

	tell_object(ob, death_msg[stage]);
	if( ++stage < sizeof(death_msg) ) {
		call_out( "death_stage", 5, ob, stage );
		return;
	} else
		ob->reincarnate();

	inv = all_inventory(ob);
	for (i = 0; i < sizeof(inv); i++)
		DROP_CMD->do_drop(ob, inv[i]);
	
	ob->move(REVIVE_ROOM);
	message("vision",
		"你忽然发现前面多了一个人影，不过那人影又好像已经在那里\n"
		"很久了，只是你一直没发觉。\n", environment(ob), ob);
}

int ask_me()
{
        mapping my_fam;
 
        object  me;
	int my_age, already_age, i;

	me = this_player();
        my_fam = (mapping)me->query("family");
	my_age = me->query("age");
	already_age = (int)me->query("already_age");

        if (my_fam["family_name"] != "星宿派")
		return notify_fail("你不是星宿派的弟子，不能地刹炼魂。\n");

	if( already_age >= my_age)
		return notify_fail("你今年的地刹炼魂次数已经用完了！\n");

	if( (int)me->query("max_neili") < 50)
		return notify_fail("你的内力不够完成地刹炼魂大法！\n");

	if(random(5) >= 2)
	{
		me->add("con",1);
		me->add("con_improve_time", 1);
		me->add("max_neili", -50);
		me->set("already_age", my_age);
	        message("vision", HIY"只见黑无常举起手中的哭丧棒，喃喃地念了几局咒语，漆黑的天空中突然出\n" +
			"现一道闪电，击中你的头顶。你只觉得浑身象是被浸泡在一股暖流中。你的\n" +
			"体质提升了！\n"NOR, me);
	}
	else
		message("vision", HIY"只见黑无常举起手中的哭丧棒，喃喃地念了几局咒语，结果什么也没发生！\n"NOR, me);
	return 1;
	
}

int ask_bing()
{
	object me,weapon,obj;
	string w_id;
	me = this_player();
	w_id = me->query("weapon/代号");
	if( (me->query("weapon/制造")) ) {
		if( objectp(obj = present(w_id, me)) ) {
			say("黑无常脸色一沉：你的武器不就在你手边么？还来干什么！\n");
		}
		else {
		weapon=creat_weapon();
		weapon->move(me);
		message_vision(HIY "只见黑无常举起手中的哭丧棒，喃喃地念了几句咒语，忽然一道金光从漆黑的天上\n"+
				"冲了下来，隐入$N的身体不见了！\n" NOR, me);
		}
		return 1;
		}
	else	{
		message_vision(HIY "白无常怒喝一声，想来搞诈骗？哼!!\n" NOR, me);
		message_vision(HIR "看起来白无常想惩罚$N\n" NOR, me);
		return 0;
	}
}


object creat_weapon()
{
	object me,weapon;
	string mask;	//the verible that record the type of weapon
	me = this_player();
	mask = me->query("weapon/类型");
	switch(mask)	{
		case "剑":
			weapon = new("/d/npc/m_weapon/weapon/m_sword",1);
			return weapon;
		case "刀":
			weapon = new("/d/npc/m_weapon/weapon/m_blade",1);
			return weapon;
		case "棍":
			weapon = new("/d/npc/m_weapon/weapon/m_club",1);
			return weapon;
		case "杖":
			weapon = new("/d/npc/m_weapon/weapon/m_staff",1);
			return weapon;
		case "鞭":
			weapon = new("/d/npc/m_weapon/weapon/m_whip",1);
			return weapon;
	}
}