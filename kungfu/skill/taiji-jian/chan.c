// chan.c 太极剑法「缠」字诀

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
	object weapon;
	string msg;

	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("牵制攻击只能对战斗中的对手使用。\n");

	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "sword")
			return notify_fail("你使用的武器不对。\n");

	if( target->is_busy() )
		return notify_fail(target->name() + "目前正自顾不暇，放胆攻击吧ⅵ\n");
		
	if( (int)me->query_skill("taiji-jian", 1) < 40 )
		return notify_fail("你的太剑法极不够娴熟，不会使用「缠」字诀。\n");

	msg = HIG "$N使出太极剑法「缠」字诀，连递数个虚招企图扰乱$n的攻势。\n";

	me->start_busy(1);
	if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/2 ) {
		msg += HIR " 结果$p被$P攻了个措手不及！\n" NOR;
		target->start_busy( (int)me->query_skill("taiji-jian") / 20 );
	} else {
		msg += "可是$p看破了$P的企图，并没有上当。\n" NOR;
	}
	message_vision(msg, me, target);

	return 1;
}
