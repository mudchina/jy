// neilisuck.c

#include <ansi.h>

inherit F_SSERVER;
int exert(object me, object target)
{
	int sp, dp;

	if ( target == me )
		target = offensive_target(me);

	if( !objectp(target) || target->query("id") == "mu ren" )
		return notify_fail("你要吸取谁的内力？\n");

	if ( me->query_temp("sucked") )
		return notify_fail("你刚刚吸取过内力！\n");

	if( (int)me->query_skill("beiming-shengong",1) < 50 )
		return notify_fail("你的北冥神功功力不够，不能吸取对方的内力！n");

	if( (int)me->query("neili",1) < 20 )
		return notify_fail("你的内力不够，不能使用北冥神功。\n");

	if( (int)target->query("max_neili") <= 0 )
		return notify_fail( target->name() + "没有任何内力！\n");

	if( (int)target->query("neili") < 60 )
		return notify_fail( target->name() +
			"已经内力涣散，你已经无法从他体内吸取任何内力了！\n");

	message_vision(
		HIM "$N身法陡然加快，右掌直出，猛地对准$n的膻中大穴按了上去！\n\n" NOR,
		me, target );

	if ( living(target) )
	{
		if( !target->is_killing(me) )
			target->kill_ob(me);
	}

	sp = me->query_skill("force") + me->query_skill("dodge") + me->query_skill("lingboweibu",1)/2;
	dp = target->query_skill("force") + target->query_skill("dodge");

	me->set_temp("sucked", 1);		

	if (( random(sp) > random(dp) ) || !living(target) )
	{
		tell_object(target, HIR "你顿觉全身内力如水银般循孔飞泄而出！\n" NOR);
		tell_object(me, HIG "你觉得" + target->name() + "的内力自手掌源源不绝地流了进来。\n" NOR);

		target->add("neili", -1*((int)me->query_skill("beiming-shengong", 1) + target->query("jiali")) );
		if ( target->query("neili") <1 )
			target->set("neili",0);
		me->add("neili", (int)me->query_skill("beiming-shengong", 1) + target->query("jiali") );

		me->start_busy(random(5));
		target->start_busy(random(4));

		call_out("del_sucked", 2, me);
	}
	else
	{	
		message_vision(HIY "可是$p看破了$P的企图，机灵地闪了开去。\n" NOR, me, target);
		me->start_busy(4);
		call_out("del_sucked", 4, me);
	}

	return 1;
}

void del_sucked(object me)
{
	if ( me->query_temp("sucked"))
		me->delete_temp("sucked");
}

