
#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
	int skill;
	string msg;

	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("唱仙法只能在战斗中使用。\n");

	if( (int)me->query_skill("shedao-qigong", 1) < 80 )
		return notify_fail("你的蛇岛奇功不够娴熟，不会使用唱仙法。\n");

	if((int)me->query_temp("apply/attack")<=0||(int)me->query_temp("apply/dodge") <=0||(int)me->query_temp("apply/defense") <=0 )
		return notify_fail("你目前战斗力太低,不能再恢复内力了。\n");

	if( (int)me->query_temp("chang") <=-30  )
		return notify_fail("你已经唱得太久了,不能再唱了。\n");

	message_vision(HIR "只听$N口中念念有词，顷刻之间内力大涨！\n" NOR, me);
	me->add_temp("apply/attack", -1);
	me->add_temp("apply/dodge", -1);
	me->add_temp("apply/defense", -1);
	me->add_temp("chang", -1);
	me->add("neili", 100);

	return 1;
}
