// xianglong 降龙大法
// by king 97.05

#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me);

int perform(object me)
{
	int skill, count;

	if( (int)me->query_temp("xianglong") ) 
		return notify_fail("你已经在运功中了。\n");
	if( !me->is_fighting() )
		return notify_fail("降龙大法只能在战斗中使用。\n");
	if( (int)me->query("neili") < 300  ) 
		return notify_fail("你的内力不够。\n");

	count = me->query_str();
	skill = me->query_skill("xianglong-zhang",1);
	me->add("neili", -100);

	message_vision( HIR "$N深吸一口气，运起降龙大法，结果越战越勇！\n" NOR, me);

	me->set_temp("xianglong", 1);
	me->set_temp("str_count", (int)count/5);
	me->set_temp("str_no", 0);
	me->set_temp("display_no", 0);
	me->start_call_out( (: call_other,  __FILE__, "remove_effect", me :), skill/2 );

	return 1;
}

void remove_effect(object me)
{
	int dmount;
	if ( (int)me->query_temp("xianglong") ) {
	dmount = (int)me->query_temp("str_no")*(int)me->query_temp("str_count");
	me->add_temp("str", - dmount );
	me->delete_temp("xianglong");
	me->delete_temp("str_count");
	me->delete_temp("str_no");
	me->delete_temp("display_no");
	tell_object(me, CYN"你的降龙大法运行完毕，将内力收回丹田。\n"NOR);}
}
