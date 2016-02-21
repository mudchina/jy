// xixueqingfu.c 吸血青蝠
 
#include <ansi.h>
 
inherit F_SSERVER;
 
int perform(object me)
{
	string msg;
	object weapon, target;
	int skill, ap, dp, neili_wound, qi_wound;

	me->clean_up_enemy();
	target = me->select_opponent();

	skill = me->query_skill("hanbing-mianzhang",1);

	if( !(me->is_fighting() ))
		return notify_fail("「吸血青蝠」只能对战斗中的对手使用。\n");
 
	if (objectp(weapon = me->query_temp("weapon")))
		return notify_fail("你使用了武器。\n");

	if( skill < 60)
		return notify_fail("你的「寒冰绵掌」等级不够, 不能使用「千里冰封」！\n");

	if( me->query_skill("dodge",1) < 150 )
		return notify_fail("你的轻功不够，无法运用「吸血青蝠」！\n");
 
	msg = HIC "$N突然如同「吸血青蝠」，欺近$n的身前，张嘴便向$n的咽喉咬去。\n"NOR;
	message_vision(msg, me, target);
 
	ap = me->query("combat_exp") + skill * 400;
	dp = target->query("combat_exp") / 2;
	if( dp < 1 )
		dp = 1;
	if( random(ap) > dp )
	{
		if(userp(me))
			me->add("neili",-100);

		msg = HIG "$n只觉得咽喉一阵剧痛，$N正在狂吸$n的鲜血！\n"NOR;
		neili_wound = 100 + random(skill);
		if(neili_wound > target->query("neili"))
			neili_wound = target->query("neili");

		qi_wound = neili_wound / 5;
		if(qi_wound > target->query("qi"))
			qi_wound = target->query("qi");

		target->add("neili", -neili_wound);
		target->add("qi", -qi_wound);
		target->start_busy(2);
		me->start_busy(random(2));
	}
	else
	{
		msg = HIG "只见$n不慌不忙，轻轻一闪，躲过了$N的利齿！\n"NOR;
		if(userp(me))
			me->add("neili",-100);
		me->start_busy(4);
	}
	message_vision(msg, me, target);

	return 1;
}
