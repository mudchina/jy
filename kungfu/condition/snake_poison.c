// snake_poison.c

#include <ansi.h>

int update_condition(object me, int duration)
{
	if(me->query_temp("nopoison")) return 0;
	me->receive_wound("qi", 10);
	me->receive_damage("jing", 10);
	me->apply_condition("snake_poison", duration - 1);
	tell_object(me, HIG "你中的蛇毒发作了！\n" NOR );
	if( duration < 1 ) return 0;
	return 1;
}
