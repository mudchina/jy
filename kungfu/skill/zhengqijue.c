// zhengqijue.c

inherit SKILL;

#include <ansi.h>

void create() { seteuid(getuid()); }

string type() { return "knowledge"; }

// int valid_learn(object me) 
// {
//	if( (int)me->query("guilty") > 0 )
//		return notify_fail("你屡犯僧家数戒，尘俗之心太重，无法修炼禅宗心法。\n");
//	return 1;
// }

int practice_skill(object me)
{	
	return notify_fail("正气决只能靠学(learn)来提高。\n");
}
void skill_improved(object me)
{
    tell_object(me, HIR "你心里鼓荡着一股侠义之气！\n" NOR );
    me->add("shen", 200);
}