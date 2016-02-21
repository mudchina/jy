// hui.c 挥斥方遒
 
#include <ansi.h>
 
inherit F_SSERVER;
 
int perform(object me)
{
	string msg;
	object weapon, target;
	int skill, dp, wound;

	me->clean_up_enemy();
	target = me->select_opponent();

	skill = me->query_skill("tanzhi-shentong",1);

	if( !(me->is_fighting() ))
		return notify_fail("「挥斥方遒」只能在战斗中使用。\n");

	if ( objectp(weapon = me->query_temp("weapon")))
		return notify_fail("你使用了武器。\n");

	if( skill < 50)
		return notify_fail("你的弹指神通等级不够, 不能使用「挥斥方遒」！\n");

	if( me->query("neili") < 150 )
		return notify_fail("你的内力不够，无法运用「挥斥方遒」！\n");
 
	msg = HIC "$N使出弹指神通之「挥斥方遒」, 顿时眼内精光暴射，\n";
	message_vision(msg, me, target);
 
	dp = target->query("combat_exp") / 1000;
	if( dp < 1 )
		dp = 1;
	if( random(skill) > dp )
	{
		if(userp(me))
			me->add("neili",-150);
		msg = "$n只觉得眼前一花，气海穴上微微一痛，全身真气狂泄而出！\n" NOR;

		wound = -300 - random(200);
		if((int)target->query("neili") < wound)
			wound = target->query("neili");
		target->add("neili", wound);
		target->add("jing", wound / 5);
		target->start_busy(2);
		me->start_busy(2);
	}
	else
	{
		msg = "可是$n的看破了$N的企图，立刻采取守势，使$P的「挥斥方遒」没有起到作用。\n"NOR;
		me->start_busy(4);
	}
	message_vision(msg, me, target);

	return 1;
}
