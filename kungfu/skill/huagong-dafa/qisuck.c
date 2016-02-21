// qisuck.c

#include <ansi.h>

inherit F_SSERVER;
int exert(object me, object target)
{
	int sp, dp;

       if ( target == me ) target = offensive_target(me);
	if( !objectp(target) || target->query("id") == "mu ren" )
		return notify_fail("你要吸取谁的真气？\n");


	if ( me->query_temp("sucked") )
		return notify_fail("你刚刚吸取过真气！\n");

	if( objectp(me->query_temp("weapon")) )
		return notify_fail("你必须空手才能施用化功大法吸人真气！\n");

//        if( !me->is_fighting() || !target->is_fighting())

	if( (int)me->query_skill("huagong-dafa",1) < 30 )
		return notify_fail("你的化功大法功力不够，不能吸取对方的真气。\n");

	if( (int)me->query("neili",1) < 10 )
		return notify_fail("你的内力不够，不能使用化功大法。\n");

        if( (int)target->query("qi") < 30 )
		return notify_fail( target->name() +
			"已经真气涣散，你已经无法从他体内吸取真气了！\n");

	message_vision(
		HIR "$N突然诡异的一笑，双手一扬，拇指对准$n的掌心按了过来！\n\n" NOR,
		me, target );

        if ( living(target) )
           { if( !target->is_killing(me) ) target->kill_ob(me); }

        sp = me->query_skill("force") + me->query_skill("dodge") + me->query_skill("zhaixinggong",1)/2;
        dp = target->query_skill("force") + target->query_skill("dodge");

	me->set_temp("sucked", 1);		

        if (( random(sp) > random(dp) ) || !living(target) )
	{
		tell_object(target, HIR "你突然觉得全身真气自手掌奔涌而出，四肢无力，再也使不出劲来！\n" NOR);
		tell_object(me, HIG "你觉得" + target->name() + "的真气自手掌源源不绝地流了进来。\n" NOR);

		target->receive_damage("qi", (int)me->query_skill("huagong-dafa", 1) );
		me->add("qi", (int)me->query_skill("huagong-dafa", 1) );
		me->add("eff_qi", (int)(me->query_skill("huagong-dafa", 1)*2/3) );
            if ( me->query("eff_qi") > me->query("max_qi") )
                 me->set("eff_qi", me->query("max_qi"));

		if( target->query("combat_exp") >= me->query("combat_exp") )
			me->add("combat_exp",1);

                me->start_busy(2);
                target->start_busy(random(2));
		me->add("neili", -5);

		call_out("del_sucked", 2, me);
	}
	else
	{	
		message_vision(HIY "可是$p看破了$P的企图，机灵地闪了开去。\n" NOR, me, target);
                me->start_busy(2);
		call_out("del_sucked", 4, me);
	}

	return 1;
}

void del_sucked(object me)
{
	if ( me->query_temp("sucked") )
	me->delete_temp("sucked");
}
