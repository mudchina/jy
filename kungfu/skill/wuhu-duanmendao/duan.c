#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_SSERVER;
 
int perform(object me, object target)
{
	object weapon, ob;
	string msg, string1;
	int count;
 
	if( !me->is_fighting() )
		return notify_fail("五虎断门刀「断」字决只能在战斗中使用。\n");

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "blade")
		return notify_fail("你使用的武器不对。\n");

	if( (int)me->query("neili") < 200 )
		return notify_fail("你的真气不够！\n");

	if( (int)me->query_skill("blade") < 60 ||
	    me->query_skill_mapped("blade") != "wuhu-duanmendao")
		return notify_fail("你的「五虎断门刀」还不到家，无法使用「断」字决！\n");

	msg = HIY "$N猛然伏地，使出地堂刀断字决，顿时一片白光直向前滚去！\n" NOR;
	message_vision(msg, me);

	me->clean_up_enemy();
	ob = me->select_opponent();

	COMBAT_D->do_attack(me, ob, me->query_temp("weapon"));
	COMBAT_D->do_attack(me, ob, me->query_temp("weapon"));
	COMBAT_D->do_attack(me, ob, me->query_temp("weapon"));

	me->add("neili", -150);
	me->start_busy(random(3));

	return 1;
}