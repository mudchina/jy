// zhong.c 种生死符

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        object obj;
	string msg;

	if( !target ) target = offensive_target(me);

	if( !target || !target->is_character() )
		return notify_fail("生死符只能种在对手身上。\n");

	if( (int)me->query_skill("bahuang-gong", 1) < 40 )
		return notify_fail("你的八荒六合功不够娴熟，不能种生死符。\n");

	if( (int)me->query_skill("liuyang-zhang", 1) < 40 )
		return notify_fail("你的天山六阳掌不够娴熟，不能种生死符。\n");

	if (!objectp(obj=present("jiudai", me)))
            return notify_fail("你身上没有酒袋，不能化水为冰。\n");

	msg = CYN "$N化水为冰，凝于掌中，轻飘飘地拍向$n。\n";

	me->start_busy(1);
	if( random( (int)me->query_skill("liuyang-zhang",1))
          > random(target->query_skill("dodge") ) ) {
		msg += CYN " 结果$p被$P攻了个正着！\n" NOR;
		target->receive_damage("qi",(int)me->query_skill("bahuang-gong",1));
		target->receive_wound("qi",15 + random(10));
		target->receive_wound("jing", 10);
		target->apply_condition("ss_poison", random(me->query_skill("liuyang-zhang",1)/10) + 1 +
		target->query_condition("ss_poison"));
		me->start_busy(random(4));
	} else {
		msg += "可是$p急忙闪在一旁，躲了开去。\n" NOR;
		me->start_busy(4);
	}
	message_vision(msg, me, target);
	target->start_busy(1 + random(2));
	if( !target->is_killing(me) )
		target->kill_ob(me);
	destruct(obj);

	return 1;
}
