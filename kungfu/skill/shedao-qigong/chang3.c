
#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
	int i,neili,damage;
	string msg;

	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("唱仙法只能在战斗中使用。\n");

	if( (int)me->query_skill("shedao-qigong", 1) < 100 )
		return notify_fail("你的蛇岛奇功不够娴熟，不会使用唱仙法吼字决。\n");

	if( environment(me)->query("no_fight") )
		return notify_fail("在这里不能攻击他人。\n");

	if( (int)me->query("neili") < 500 )
		return notify_fail("你已经唱得精疲力竭,内力不够了。\n");


	neili = me->query("neili");

	me->add("neili", -(300+random(200)));
	me->receive_damage("qi", 10);

	me->start_busy(random(5));

	message_vision(
		HIY "$N深深地吸一囗气，忽然仰天长啸，高声狂叫：不死神龙，唯我不败！\n" NOR, me);

		if( neili/2 + random(neili/2) < (int)target->query("neili")/10) 
		return notify_fail("敌人的内力比你高出太多,伤不了！\n");
		
		damage = (neili - (int)target->query("max_neili")) / 10;
		if( damage > 0 ) {
			target->receive_damage("jing", damage);
			target->receive_damage("qi", damage);
			target->receive_wound("qi", damage);
			target->receive_wound("qi", damage);
		message_vision(
		HIR "$N只觉脑中一阵剧痛，金星乱冒，犹如有万条金龙在眼前舞动。\n" NOR, target);
		}
		else
		{
		message_vision(
		HIR "$N只觉脑中微痛，似乎受了一点轻伤。\n" NOR, target);
		target->receive_damage("jing", 10 );
		target->receive_damage("qi", 10 );
		target->receive_wound("qi", 10);
		}
		if( !target->is_killing(me) ) target->kill_ob(me);
		if( !me->is_killing(target) ) me->fight_ob(target);

	return 1;
}
