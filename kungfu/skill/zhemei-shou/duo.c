// duo.c 空手入白刃
 
#include <ansi.h>
 
inherit F_SSERVER;
 
int perform(object me)
{
	string msg;
	object weapon, weapon2, target;
	int skill, dp, damage;

	me->clean_up_enemy();
	target = me->select_opponent();

	if( (int)me->query_temp("duo") )
		return notify_fail("你已经在夺敌人的兵刃了。\n");
	skill = me->query_skill("zhemei-shou",1);

	if( !(me->is_fighting() ))
		return notify_fail("空手入白刃只能对战斗中的对手使用。\n");
 
	if (objectp(weapon = me->query_temp("weapon")))
		return notify_fail("你必须空手。\n");

	if (!objectp(weapon2 = target->query_temp("weapon")))
	   return notify_fail("对方没有兵刃，你不用担心。\n");

	if( skill < 50)
		return notify_fail("你的天山折梅手等级不够, 不能空手入白刃！\n");

	if( me->query("neili") < 50 )
		return notify_fail("你的内力不够，无法空手入白刃！\n");
 
	msg = CYN "$N凝神闭息，打算施展空手入白刃的绝技. \n";
	message_vision(msg, me);
 
	dp = target->query("combat_exp") / 2000;
	if( dp < 1 )
		dp = 1;
	if( random(skill) > dp )
	{
		if(userp(me))
			me->add("neili",-50);
		msg = "$N使出空手入白刃的绝招, $n顿时觉得眼前一花，手腕一麻，手中兵刃脱手而出！\n" NOR;
		target->start_busy(2);
		weapon2->move(me);
		me->start_busy(2);
	}
	else
	{
		msg = "可是$n的看破了$N的企图，立刻采取守势，使$N没能夺下兵刃。\n"NOR;
		me->start_busy(4);
	}
	message_vision(msg, me, target);

	return 1;
}