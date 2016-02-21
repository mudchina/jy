// pobian.c 破鞭式
 
#include <ansi.h>
 
inherit F_SSERVER;
 
int perform(object me)
{
	string msg;
	object weapon, weapon2, target;
	int skill, ap, dp, damage;

	me->clean_up_enemy();
	target = me->select_opponent();

	skill = me->query_skill("dugu-jiujian",1);

	if( !(me->is_fighting() ))
		return notify_fail("「破鞭式」只能对战斗中的对手使用。\n");
 
	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不对。\n");

	if (!objectp(weapon2 = target->query_temp("weapon"))
	|| (string)weapon2->query("skill_type") != "hammer")
		return notify_fail("对方没有使钢鞭、铁锤，你用不了「破鞭式」。\n");

	if( skill < 50)
		return notify_fail("你的独孤九剑等级不够, 不能使用「破鞭式」！\n");

	if( me->query("neili") < 50 )
		return notify_fail("你的内力不够，无法运用「破鞭式」！\n");
 
	msg = HIC "$N巧使独孤九剑「破鞭式」逼近$n，提剑幻出重重剑影，如柔丝般向$n裹去。\n";
	message_vision(msg, me, target);
 
	damage = 10 + random(skill / 2);
	ap = me->query_skill("sword") + skill;
	dp = target->query_skill("hammer") / 2;
	if( dp < 1 )
		dp = 1;
	if( random(ap) > dp)
	{
		if(userp(me))
			me->add("neili",-50);
		msg = "$n顿时觉得压力骤增，手腕一麻，手中";
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
		msg = "可是$n看破了$N的剑路，立刻采取守势，使$N的破鞭式没有起到作用。\n"NOR;
		me->start_busy(4);
	}
	message_vision(msg, me, target);

	return 1;
}