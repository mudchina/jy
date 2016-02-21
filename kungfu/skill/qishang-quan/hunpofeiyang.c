// hunpofeiyang.c 魂魄飞扬
 
#include <ansi.h>
 
inherit F_SSERVER;
 
int perform(object me)
{
	string msg;
	object weapon, target;
	int skill, ap, dp, neili_wound, qi_wound;

	me->clean_up_enemy();
	target = me->select_opponent();

//	skill = me->query_skill("hunyuan-zhang",1);

	if( !me->is_fighting() )
	    	return notify_fail("「魂魄飞扬」只能在战斗中使用。\n");

	if( (int)me->query("neili") < 500 )
		return notify_fail("你的内力还不够高！\n");

	if( (int)me->query_skill("cuff") < 150 )
		return notify_fail("你的拳法还不到家，无法使用魂魄飞扬！\n");

	if( (int)me->query_skill("qishang-quan", 1) < 60)
		return notify_fail("你七伤拳的修为不够，不能使用魂魄飞扬! \n");

	if( me->query_skill_mapped("cuff") != "qishang-quan") 
		return notify_fail("你没有激发七伤拳，无法使用魂魄飞扬！\n");
 
	msg = HIY "$N大喝一声，使出七伤拳的绝技「魂魄飞扬」，双拳势如雷霆，向$n击去。\n"NOR;
	message_vision(msg, me, target);
 
	ap = me->query("combat_exp") + skill * 400;
	dp = target->query("combat_exp") / 2;
	if( dp < 1 )
		dp = 1;
	if( random(ap) > dp )
	{
		if(userp(me))
			me->add("neili",-100);

		msg = HIG "$n只觉得胸前一阵剧痛，“哇”的一声喷出一口鲜血！\n"NOR;
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
		msg = HIG "只见$n不慌不忙，轻轻一闪，躲过了$N的必杀一击！\n"NOR;
		if(userp(me))
			me->add("neili",-100);
		me->start_busy(4);
	}
	message_vision(msg, me, target);

	return 1;
}
