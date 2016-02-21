// flower_poison.c

#include <ansi.h>

int update_condition(object me, int duration)
{
	if(me->query_temp("nopoison")) return 0;
	me->receive_wound("jing", 20);
	me->receive_damage("qi", 10);
	me->apply_condition("flower_poison", duration - random(5));
	tell_object(me, HIG "你中的" HIR "断肠花毒" HIG "发作了！\n" NOR );
	if( duration < 1 ) return 0;
	return 1;
}
