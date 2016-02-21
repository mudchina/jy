//
// fanchang.c
// by secret
// 97-1-16
//

#include <ansi.h>

inherit F_SSERVER;
int exert(object me, object target)
{
	int sp, dp;

	if ( target == me )
		target = offensive_target(me);

//	if( environment(me)->query("no_fight") )
//		return notify_fail("^U^B^@^O^R^[^W^\^U^]^V^W! \n");

	if( !objectp(target) || target->query("id") == "mu ren" )
		return notify_fail("你要攻击谁？\n");

	if( (int)me->query_skill("longxiang",1) < 50 )
		return notify_fail("你的龙象般若功功力不够，不能凝神攻击对方！\n");

	if( (int)me->query("neili",1) < 50 )
		return notify_fail("你的内力不够，不能使用龙象般若功。\n");

	message_vision(HIW "$N面无表情，歌声如梵唱般贯入$n耳中！\n\n" NOR, me, target );

	if( living(target))
		if( !target->is_killing(me) )
			target->kill_ob(me);

	sp = me->query_skill("force") + me->query_skill("mizongxinfa") + me->query_skill("longxiang",1)/2;
	dp = target->query_skill("force");
	
	if (( random(sp) > random(dp) ) || !living(target) )
	{
		tell_object(target, HIW " 你忽然觉得脑中一片空白，不由自主地随歌声舞蹈起来！\n" NOR);
		tell_object(me, HIB "你看到" + target->name() + "随着你的歌声手舞足蹈，十分可笑。\n" NOR);

		target->receive_damage("jing", 10 + random((int)me->query_skill("longxiang", 1)) );
		
		if( target->query("combat_exp") >= me->query("combat_exp") )
			if( (int)me->query("potential") - (int)me->query("learned_points") < 100 )
				me->add("potential", 1);

		me->start_busy(2);
		target->start_busy(random(3));
		me->add("neili", -50);

	}
	else
	{	
		message_vision(HIY "可是$p不为$P歌声所动，定力果然不同凡响！\n" NOR, me, target);
		me->start_busy(4);
	}

	return 1;
}
