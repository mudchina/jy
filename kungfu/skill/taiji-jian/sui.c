// sui.c 太极剑法 [随]字决

#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int a_amount, int d_amount);

inherit F_SSERVER;
int perform(object me, object target)
{
	object weapon;
	int skill;
	string msg;

	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("「随」字诀只能在战斗中使用。\n");

	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不对。\n");

	if( (int)me->query_skill("taiji-jian", 1) < 40 )
		return notify_fail("你的太剑法极不够娴熟，不会使用「随」字诀。\n");

	if( (int)me->query("neili") < 300  ) 
		return notify_fail("你的内力不够。\n");

	if( (int)me->query_temp("tjj_sui") ) 
		return notify_fail("你已经在运功\中了。\n");

	skill = me->query_skill("taiji-jian");
	msg = HIB "$N使出太极剑法「随」字诀，剑圈逐渐缩小将周身护住。\n"NOR;
	message_vision(msg, me, target);

	me->add_temp("apply/attack", -skill/4);
	me->add_temp("apply/dodge", skill/3);
	me->set_temp("tjj_sui", 1);

	me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill/4, skill/3 :), skill/4);

	me->add("neili", -100);
	if( me->is_fighting() ) me->start_busy(2);

	return 1;
}

void remove_effect(object me, int a_amount, int d_amount)
{
	me->add_temp("apply/attack", a_amount);
	me->add_temp("apply/dodge", - d_amount);
	me->delete_temp("tjj_sui");
	tell_object(me, HIY "你的随字决运行完毕，将内力收回丹田。\n");
}
