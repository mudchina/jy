// jiuyang-shengong.c 九阳神功
// cleansword

inherit FORCE;

int valid_enable(string usage)
{
	return usage == "force";
}

int valid_learn(object me)
{
	int lvl = (int)me->query_skill("jiuyang-shengong", 1);

	if ( (me->query("family/family_name") != "少林派"))
		return notify_fail("九阳神功博大精深, 非少林弟子不传!\n");
				    
	if ( me->query("gender") == "无性" && lvl > 49)
		return notify_fail("你无根无性，阴阳不调，难以领会高深的九阳神功。\n");

	if ((int)me->query_skill("force", 1) < 30)
		return notify_fail("你的基本内功火候还不够，无法领会九阳神功。\n");

	if ( me->query_skill("bibo-shengong",1)
	|| me->query_skill("beimin-shengong",1)
	|| me->query_skill("bahuang-gong",1)
	|| me->query_skill("hamagong",1)
	|| me->query_skill("huagong-dafa",1)
	|| me->query_skill("huntian-qigong",1)
//	|| me->query_skill("hunyuan-yiqi",1)
	|| me->query_skill("longxiang",1)
//	|| me->query_skill("jiuyang-shengong",1)
//	|| me->query_skill("taiji-shengong",1)
	|| me->query_skill("xiaowuxiang",1)
	|| me->query_skill("yunlong-shengong",1)
	|| me->query_skill("zixia-shengong",1) )
		return notify_fail("你不先散了别派内功，怎能学九阳神功？！\n");

	return 1;
}

string exert_function_file(string func)
{
	return __DIR__"jiuyang-shengong/" + func;
}
