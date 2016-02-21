// tianshan-zhang.c, based on dagou-bang.c
// by yucao
// Modified by Hop 97.01.05
// Added by Yzuo 97.04.08

inherit SKILL;

mapping *action = ({
([	"action": "$N使出一招「冰河开冻」，手中$w大开大阖扫向$n的$l",
	"force" : 80,
	"dodge": -3,
	"damage": 40,
	"lvl" : 1,
	"damage_type": "挫伤"
]),
([	"action": "$N手中$w阵阵风响，一招「山风凛冽」向$n的$l攻去",
	"force" : 140,
	"dodge": -5,
	"damage": 70,
	"lvl" : 13,
	"damage_type": "挫伤"
]),
([	"action": "$N举起$w，居高临下使一招「天山雪崩」砸向$n的$l",
	"force" : 200,
	"dodge": -10,
	"damage": 100,
	"lvl" : 30,
	"damage_type": "挫伤"
]),
([	"action": "$N一招「残阳照雪」，纵身飘开数尺，手中$w砸向$n的$l",
	"force" : 240,
	"dodge": -30,
	"damage": 120,
	"lvl" : 45,
	"damage_type": "挫伤"
]),
([	"action": "$N使一招「回光幻电」，手中$w幻一条疾光点向$n的$l",
	"force" : 270,
	"dodge": -20,
	"damage": 130,
	"lvl" : 60,
	"damage_type": "挫伤"
]),
([	"action": "$N使出的「风霜碎影」，$w连挥杖影霍霍劈向$n的$l",
	"force" : 300,
	"dodge": -20,
	"damage": 130,
	"lvl" : 75,
	"damage_type": "挫伤"
]),
([	"action": "$N的$w凭空一指，一招「断石狼烟」点向$n的$l",
	"force" : 320,
	"dodge": 20,
	"damage": 140,
	"lvl" : 90,
	"damage_type": "挫伤"
]),
([	"action": "$N纵身一跃，手中$w一招「长空雷隐」对准$n的$l扫去",
	"force" : 340,
	"dodge": -40,
	"damage": 150,
	"lvl" : 105,
	"damage_type": "挫伤"
]),
([	"action": "$N手中$w中宫直进，一式「冰谷初虹」对准$n的$l点去",
	"force" : 350,
	"dodge": -40,
	"damage": 160,
	"lvl" : 120,
	"damage_type": "挫伤"
]),
([	"action": "$N一招「峰回路转」，$w左右迂回向$n的$l点去",
	"force" : 380,
	"dodge": -5,
	"damage": 180,
	"lvl" :  145,
	"damage_type": "挫伤"
]),
});

mapping query_action(object me, object weapon)
{
	int i, level;
	level   = (int) me->query_skill("tianshan-zhang",1);
	for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"])
			return action[NewRandom(i, 20, level/5)];
//        return action[random(sizeof(action))];
}

int valid_enable(string usage) { return (usage == "staff") || (usage == "parry"); }

int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 80)
		return notify_fail("你的内力不够。\n");
	return 1;
}

int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "staff")
		return notify_fail("你使用的武器不对。\n");
	if ((int)me->query("qi") < 50)
		return notify_fail("你的体力不够练天山杖法。\n");
	me->receive_damage("qi", 25);
	return 1;
}
