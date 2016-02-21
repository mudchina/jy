// powerup.c 九阳神功加力

#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

int exert(object me, object target)
{
	int skill;

	if ( !wizardp(this_player()) && (me->query("family/family_name") != "少林派"))
		return notify_fail("你不是少林弟子不能使用九阳神功.\n
		 		    九阳神功博大精深, 非少林弟子不传, 真不知道你是怎么学会的!\n
				    善哉, 善哉, 阁下在德行方面是否需要再好好学一学.\n");
	if( target != me ) 
		return notify_fail("你只能用九阳神功来提升自己的战斗力。\n");

	if( (int)me->query("neili") < 100  ) 
		return notify_fail("你的内力不够。\n");
	if( (int)me->query_temp("powerup") ) 
		return notify_fail("你已经在运功\中了。\n");

	skill = me->query_skill("force");
	me->add("neili", -100);
	me->receive_damage("qi", 0);

	message_vision(
	HIR "$N微一凝神，运起九阳神功，全身骨节发出一阵爆豆般的声响, 将全身潜能尽数提起。ⅵ\n" NOR, me);

	me->add_temp("apply/attack", skill/3);
	me->add_temp("apply/dodge", skill/3);
	me->set_temp("powerup", 1);

	me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill/3 :), skill);

	if( me->is_fighting() ) me->start_busy(3);

	return 1;
}

void remove_effect(object me, int amount)
{
   if ( (int)me->query_temp("powerup") ) {
	me->add_temp("apply/attack", - amount);
	me->add_temp("apply/dodge", - amount);
	me->delete_temp("powerup");
	tell_object(me, "你的九阳神功运行完毕，将内力收回丹田。\n");}
}
