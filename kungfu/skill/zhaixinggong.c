// zhaixinggong.c based on xiaoyaoyou.c
// by yucao
//Modified by Yzuo

inherit SKILL;

string *dodge_msg = ({
	"$n一个「天外摘星」，跃起数尺，躲过了$N这一招。\n",
	"$n身形向后一纵，使出一招「飘然出尘」，避过了$N的攻击。\n",
	"$n使出「天狼涉水」，恰好躲过了$N的攻势。\n",
       "$n身随意转，一招「斗转星移」，倏地往一旁挪开了三尺，避过了这一招。\n",
       "$n足不点地，使出「流星赶月」，往旁窜开数尺，躲了开去。\n",
       "$n一招「织女穿梭」，姿态美妙地躲了开去。\n"
});

int valid_enable(string usage) 
{ 
	return (usage == "dodge") || (usage == "move"); 
}

int valid_learn(object me) { return 1; }

string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
        if( (int)me->query("qi") < 40 )
                return notify_fail("你的体力太差了，不能练摘星功。\n");
	if (me->query_skill("zhaixinggong", 1) < 30)
	        me->receive_damage("qi", 10);
	else if (me->query_skill("zhaixinggong", 1) < 60)
		me->receive_damage("qi", 20);
	else 
		me->receive_damage("qi", 30);
        return 1;
}

