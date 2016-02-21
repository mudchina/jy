// roar.c 佛门狮子吼

#include <ansi.h>

inherit F_CLEAN_UP;

int exert(object me, object target)
{
	object *ob;
	int i, skill, damage;

	if ( !wizardp(this_player()) && (me->query("family/family_name") != "少林派"))
		return notify_fail("你不是少林弟子不能使用九阳神功.\n
		 		    九阳神功博大精深, 非少林弟子不传, 真不知道你是怎么学会的!\n
				    善哉, 善哉, 阁下在德行方面是否需要再好好学一学.\n");

	if( ((int)me->query("neili") < 600 ) || ( (int)me->query_skill("jiuyang-shengong") < 20) )
		return notify_fail("你鼓足真气\"喵\"的吼了一声, 结果吓走了几只老鼠。\n");


	skill = me->query_skill("force");

	me->add("neili", -150);
	me->receive_damage("qi", 10);

	me->start_busy(1);
	message_vision(
		HIY "$N深深地吸一囗气，真力迸发，发出一声惊天动地的巨吼ⅵ\n" NOR, me);

	ob = all_inventory(environment(me));
	for(i=0; i<sizeof(ob); i++) {
		if( !living(ob[i]) || ob[i]==me ) continue;
		if( skill/2 + random(skill/2) < (int)ob[i]->query("con") * 2 ) continue;
		
		damage = skill * 3 - ((int)ob[i]->query("max_neili") / 10);
		if( damage > 0 ) {
			ob[i]->receive_damage("jing", damage * 2 );
			if( (int)ob[i]->query("neili") < skill * 2 )
				ob[i]->receive_wound("jing", damage);
			tell_object(ob[i], "你觉得眼前一阵金星乱冒，耳朵痛得像是要裂开一样ⅵ\n");
		}
		if( !ob[i]->is_killing(me) ) ob[i]->kill_ob(me);
		if( !me->is_killing(ob[i]) ) me->fight_ob(ob[i]);
	}

	return 1;
}

