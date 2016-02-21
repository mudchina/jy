// nuoyi.c 乾坤大挪移大法
// by King 97.05

#include <ansi.h>

inherit F_SSERVER;
int main(object me, string arg)
{
	string who1, who2;
	object target, victim;
        int damage, lvl, r_lvl, count, form, skill, i;
        string msg;

        if( !me->query_skill("qiankundanuoyi", 1) )
                return notify_fail("你不会乾坤大挪移大法。\n");

	if( !arg )
	{	target = offensive_target(me);
	        if( !target || !target->is_character() || !me->is_fighting(target) )
        	        return notify_fail("乾坤大挪移大法只能对自己或战斗中的对手使用。\n");
		form = 2;
	}
	else if( sscanf(arg, "%s to %s", who1, who2) == 2)
	{	target = present(who1, environment(me));
		victim = present(who2, environment(me));
	        if( !target || !target->is_character() || !me->is_fighting(target) )
       	        	return notify_fail("乾坤大挪移大法只能对战斗中的对手使用。\n");
	        if( !victim || !victim->is_character() || victim==me) 
			return notify_fail("你想挪移攻击的对象不在这里。\n");
		form = 3;
	}
	else 
	{	sscanf(arg, "%s", who1);
		target = present(who1, environment(me));
		if( target == me) form = 1;
	        else if( !target || !target->is_character() || !me->is_fighting(target) )
                	return notify_fail("乾坤大挪移大法只能对自己或战斗中的对手使用。\n");
		else form = 2;
	}

	if( me->is_busy() )
		return notify_fail("你的动作还没有完成，不能发功。\n");

        if( (int)me->query_skill("qiankundanuoyi", 1) < 50 )
                return notify_fail("你的乾坤大挪移不够高，小心走火入魔！\n");

        if( (int)me->query("neili", 1) < 1500 )
                return notify_fail("你现在内力太弱，不能使用乾坤大挪移大法。\n");

	skill = (int)me->query_skill("qiankundanuoyi", 1);
	lvl = skill/20;
	r_lvl = random(lvl);
	if( r_lvl < 1) r_lvl = 1;
	count = me->query_str();

	if( form == 1)
	{
		if( (int)me->query_temp("nuoyi") ) 
			return notify_fail("你已经在运功\中了。\n");
		if( !me->is_fighting() )
			return notify_fail("乾坤大挪移只能在战斗中使用。\n");
		message_vision( HIR"$N默运乾坤大挪移大法，脸色忽青忽红，连变"CYN + lvl + HIR"次，将全身内力尽数提起！\n"NOR, me);
		me->add_temp("str", count * r_lvl);
		me->set_temp("nuoyi", 1);
		me->start_call_out( (: call_other, __FILE__, "remove_effect", me, count * r_lvl :), skill);
		me->add("neili", -300);
		me->start_busy(3);
		return 1;
	}

	if( form == 2 )
	{
        msg = CYN "$N默运神功，使出乾坤大挪移大法。\n"NOR;
	me->start_busy(3);

        if (random(me->query("neili",1)) > 2*target->query("neili",1)/3 )
        {
                target->start_busy(random(3));
                
                damage = skill/2 + r_lvl*target->query("jiali",1);
                
                target->receive_damage("qi", damage);
                target->receive_wound("qi", damage/3);
                me->add("neili", -damage);
		msg += CYN "将$n的内力全数反击回去！\n" NOR;
                
                if( damage < 20 )
                        msg += HIY"结果$n受到$N的内力反震，闷哼一声。\n"NOR;
        	else if( damage < 40 )
                        msg += HIY"结果$n被$N以内力反震，「嘿」地一声退了两步。\n"NOR;
        	else if( damage < 80 )
                        msg += RED"结果$n被$N以内力一震，胸口有如受到一记重锤，连退了五六步！\n"NOR;
                else
                        msg += HIR"结果$n被$N的内力一震，眼前一黑，象一捆稻草一样飞出去好几丈远！\n"NOR;
                
        }
        else 
        {
                msg += CYN"可是$n内力深厚，丝毫不为所动。\n"NOR;
		me->add("neili", -100);
        }
        message_vision(msg, me, target);

	return 1;
	}

	if( form == 3 )
	{
	write( CYN "你默运神功，使出乾坤大挪移大法，试图将" + target->name() + "的攻击挪移到" + victim->name() + "身上。\n"NOR);
	tell_object(target, CYN"忽然，你发现有一股奇怪的力量向你袭来！\n"NOR);
	me->start_busy(3);

        if ( (random(me->query("neili",1)) > 2*target->query("neili",1)/3 ) && ( r_lvl > random(5) ) )
        {
                write( CYN"哈哈，成功了！\n"NOR);

		if( target == victim)
		{
		tell_object(target, CYN"你身不由己，一招击向自己！\n"NOR);
		message("vision", CYN"\n" + target->name() + "忽然如中魔一般，招招击向自己！\n\n"NOR, environment(me), target);
		for(i = 0; i < r_lvl; i++)
			COMBAT_D->do_attack(target, victim, target->query_temp("weapon") );
		}

		else
		{
		tell_object(target, CYN"你身不由几，向" + victim->name() + "扑去！\n"NOR);
		message("vision", CYN"\n" + target->name() + "忽然向" + victim->name() +"扑去！\n\n"NOR, environment(me), ({target, victim}) );
		tell_object(victim, CYN"\n" + target->name() + "忽然向你扑来！\n\n"NOR);

		COMBAT_D->do_attack(target, victim, target->query_temp("weapon") );

		if( random(me->query("combat_exp")) > (int)victim->query("combat_exp")/2 )		
		{
			if( !victim->is_killing(target) ) victim->kill_ob(target);
		}
		else
		{
		tell_object(victim, CYN"你一定神，原来是" + me->name() + "在捣鬼！\n"NOR);
		tell_object(target, CYN"还好，幸亏" + victim->name() + "经验老到，没有上当。\n"NOR);
		write( CYN "不好，被" + victim->name() + "发觉了！\n"NOR);
		if( !victim->is_killing(me) ) victim->kill_ob(me);
		}

                target->start_busy(random(3));
		me->add("neili", -300);
		}
	}
	else
	{
		write( CYN"可惜没成功。"NOR);
		tell_object(target, CYN"你强用心神，终于控制住自己。\n"NOR);
		me->add("neili", -100);
	}

        return 1;
	}

	return 1;
}

void remove_effect(object me, int amount)
{
   if ( (int)me->query_temp("nuoyi") ) {
	me->add_temp("str", - amount);
	me->delete_temp("nuoyi");
	tell_object(me, "你的乾坤大挪移大法运行完毕，将内力收回丹田。\n");}
}

int help(object me)
{
write(@HELP
指令格式 : 
1. nuoyi <自己> : 用来提升自己的战斗力。
2. nuoyi 或 nuoyi <人物> : 用来反击。
3. nuoyi <人物1> to <人物2> : 用来将人物1的攻击挪移到人物2身上。
4. 如果<3>中<人物1>=<人物2>，哈哈，则会有非常有趣的现象。

HELP
    );
    return 1;
}