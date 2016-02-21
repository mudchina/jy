// posuo.c 「破索式」
 
#include <ansi.h>
 
inherit F_SSERVER;
 
int perform(object me)
{
	string msg;
	object weapon, weapon2, target;
	int skill, ap, dp, wound, damage;

	me->clean_up_enemy();
	target = me->select_opponent();

	skill = me->query_skill("dugu-jiujian",1);

	if( !(me->is_fighting() ))
		return notify_fail("「破索式」只能对战斗中的对手使用。\n");
 
	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不对。\n");

	if (!objectp(weapon2 = target->query_temp("weapon"))
	|| (string)weapon2->query("skill_type") != "whip")
		return notify_fail("对方没有使索，你用不了「破索式」。\n");

	if( skill < 60)
		return notify_fail("你的独孤九剑等级不够, 不能使用「破索式」！\n");

	if( me->query("neili") < 50 )
		return notify_fail("你的内力不够，无法运用「破索式」！\n");
 
	msg = HIC "$N使出独孤九剑之「破索式」，剑化流星，迅急无比地点向$n的手腕。\n";
	message_vision(msg, me, target);
 
	damage = 10 + random(skill / 2);
	ap = me->query_skill("sword") + skill;
	dp = target->query_skill("whip") / 2;
	if( dp < 1 )
		dp = 1;
	if( random(ap) > dp )
	{
		if(userp(me))
			me->add("neili",-50);
		msg = "结果$n被$p攻了个措手不及，手腕一麻，手中";
		msg += weapon2->name();
		msg += "脱手而出！\n" NOR;

		target->receive_damage("qi", damage);
		target->start_busy(2);
		weapon2->move(environment(me));
        }
	else
	{
		if(userp(me))
			me->add("neili",-30);
		msg = "可是$n看破了$N的企图，迅即退开，使$N的「破索式」没有起到作用。\n"NOR;
		me->start_busy(4);
	}
	message_vision(msg, me, target);

	return 1;
}