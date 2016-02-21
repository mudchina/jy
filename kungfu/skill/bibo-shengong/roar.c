// roar.c 碧海生潮曲

#include <ansi.h>

inherit F_CLEAN_UP;

int exert(object me, object target)
{
	object *ob;
	int i, skill, damage;

	if( (int)me->query("neili") < 100 )
		return notify_fail("你的内力不够。\n");


	skill = me->query_skill("force");

	me->add("neili", -100);
	me->receive_damage("qi", 10);

	me->start_busy(5);
	message_vision(
        HIY "$N气凝丹田，运集全身内力吟出一曲「碧海生潮」！\n" NOR, me);

	ob = all_inventory(environment(me));
	for(i=0; i<sizeof(ob); i++) {
		if( !living(ob[i]) || ob[i]==me )
			continue;

		if( skill/2 + random(skill/2) < (int)ob[i]->query("con") * 2 )
			continue;

		if( !ob[i]->is_killing(me) )
			ob[i]->kill_ob(me);
		if( !me->is_killing(ob[i]) )
			me->fight_ob(ob[i]);
		
		damage = skill - ((int)ob[i]->query("max_neili") / 10);
		if( damage > 0 ) {
			ob[i]->receive_damage("jing", damage * 2 );
			if( (int)ob[i]->query("neili") < skill * 2 )
				ob[i]->receive_wound("jing", damage);
		tell_object(ob[i], "你只觉得眼前一片模糊，朦胧中似乎无数排山巨浪向你打来......\n");
		}
	}

	return 1;
}