// jianzhang.c  剑掌五连环

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
		return notify_fail("「剑掌五连环」只能在战斗中使用。\n");
 
	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("「剑掌五连环」开始时必须拿着一把剑！\n");

	if( (int)me->query("neili") < 100 )
		return notify_fail("你的真气不够！\n");

	if( (int)me->query_skill("sword") < 50 ||
	    me->query_skill_mapped("sword") != "huashan-jianfa")
		return notify_fail("你的华山剑法还不到家，无法使用剑掌五连环！\n");

	msg = HIY "$N使出华山派绝技「剑掌五连环」，身法陡然加快！\n" NOR;
	message_vision(msg, me);

	me->clean_up_enemy();
	ob = me->select_opponent();

	COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
	COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
	COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
	COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
	COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);

	me->add("neili", -100);
	me->start_busy(random(5));

	return 1;
}