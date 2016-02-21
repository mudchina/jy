// hubo.c
#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me)
{
	string msg;
	int count;

    if( me->is_busy() )
	return notify_fail("你的动作还没有完成，不能使用「双手互博之术」。\n");
    if (!me->query_skill("hubo",1))
       return notify_fail("你不会「双手互博之术」。\n");
    if( !me->is_fighting() )
        return notify_fail("「双手互博之术」只能在战斗中使用。\n");

    if( (int)me->query("jing") < 70 ) return notify_fail("你的精不够！\n");
    if( (int)me->query("neili") < 70 )
        return notify_fail("你的内力不够！\n");

    msg = HIY "$N平心静气，灵台空明，使出「双手互博之术」，双手同时出招！\n" NOR;

    message_vision(msg, me);
    count = (40 - (int)me->query("int")) / 5 + (int)me->query_skill("hubo") / 20 ;
    if( count < 1 ) count = 1 ;
    if ( count > 7 ) count = 7 ;
	while( count-- ) {
		object ob;

	me->clean_up_enemy();
	ob = me->select_opponent();
        if(!ob || (environment(ob) != environment(me))) 
        {
            message_vision(CYN "$N突然心中一乱，已不能继续双手互博！\n" NOR, me);
			break;
        }
	COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
//        COMBAT_D->fight(me, ob) ;
        me->receive_damage("jing", 10);
        me->add("neili", -10);
	}
//    me->start_busy(3);
    return 1;
}

int help(object me)
{
        write(@HELP
指令格式 : hubo
 
这个指令可以让你在对敌时使用双手互博之术,快速出招。
 
HELP
    );
    return 1;
}