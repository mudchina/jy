
#include <ansi.h>
#include <command.h>
#include <login.h>

inherit NPC;
int ask_bing();
object creat_weapon();

void create()
{
	set_name("风云", ({ "wind" }) );
	set("long",
		"这就是天下第一大笨人风云。\n");
	set("attitude", "peaceful");
	set("chat_chance", 5);
	set("chat_msg", ({
		"风云叹了口气道：“你当我是谁呀，我也是苦出身！” \n",
		"风云一脸苦相看着你，说：又要我帮忙啊？\n",
		"风云很气愤地看着你，说：哼，这回帮了你，下回我们就不是朋友！\n"
	}) );
	set("age", 22);
	set("combat_exp", 2000000);
	set("max_neili", 5000000);
	set("max_jing", 3000);
	set("max_qi", 3000);

	set("inquiry", ([
		"兵器"           : (: ask_bing :),
	]));

	setup();
}

int ask_bing()
{
	object me,weapon,obj;
	string w_id;
	me = this_player();
	w_id = me->query("weapon/代号");
		weapon = creat_weapon();
		weapon->move(me);
		message_vision(HIY "\n只见风云仰天长啸，把手一扬，忽然一道金光从漆黑的天上冲了下来，隐入$N的身体不见了！\n" NOR, me);
		return 1;
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