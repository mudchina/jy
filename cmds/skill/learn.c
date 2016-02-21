// learn.c

#include <skill.h>

inherit F_CLEAN_UP;

string *reject_msg = ({
	"说道：您太客气了，这怎么敢当？\n",
	"像是受宠若惊一样，说道：请教？这怎么敢当？\n",
	"笑着说道：您见笑了，我这点雕虫小技怎够资格「指点」您什么？\n",
});

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	string skill, teacher, master, skill_name;
	object ob;
	int master_skill, my_skill, gin_cost, grade, my_combat_exp;
	int betrayer;

	if (me->is_busy())
		return notify_fail("你现在正忙着呢。\n");

	if(!arg || (sscanf(arg, "%s %s", teacher, skill)!=2 ))
		return notify_fail("指令格式：learn|xue <某人> <技能>\n");

	if( me->is_fighting() )
		return notify_fail("临阵磨枪？来不及啦。\n");

	if( !(ob = present(teacher, environment(me))) || !ob->is_character())
		return notify_fail("你要向谁求教？\n");

	if( !living(ob) )
		return notify_fail("嗯....你得先把" + ob->name() + "弄醒再说。\n");

	if( !me->is_apprentice_of(ob) && !(ob->recognize_apprentice(me)) )
		return	notify_fail( ob ->name() + reject_msg[random(sizeof(reject_msg))] );

	if( !master_skill = ob->query_skill(skill, 1) )
		return notify_fail("这项技能你恐怕必须找别人学了。\n");

	my_skill = me->query_skill(skill, 1);
	if( betrayer = me->query("betrayer") )
	{
		if( my_skill >= (master_skill - betrayer * 20 ))
		{
			message_vision("$N神色间似乎对$n不是十分信任，也许是想起$p从前背叛师门的事情 ...。\n",
				ob, me );
			command("say 嗯 .... 师父能教你的都教了，其他的你自己练吧。");
			return notify_fail(ob->name() + "不愿意教你这项技能。\n");
		}
	}

	if( my_skill >= master_skill )
		return notify_fail("这项技能你的程度已经不输你师父了。\n");

	if( !SKILL_D(skill)->valid_learn(me) ) return SKILL_D(skill)->valid_learn(me);

	gin_cost = 150 / (int)me->query("int") + 1;

	if( !my_skill ) {
		gin_cost *= 2;
		me->set_skill(skill,0);
	}

	if( (int)me->query("learned_points") >= (int)me->query("potential") )
		return notify_fail("你的潜能已经发挥到极限了，没有办法再成长了。\n");
	printf("你向%s请教有关「%s」的疑问。\n", ob->name(), to_chinese(skill));

	if( ob->query("env/no_teach") )
		return notify_fail("但是" + ob->name() + "现在并不准备回答你的问题。\n");

	tell_object(ob, sprintf("%s向你请教有关「%s」的问题。\n",
		me->name(), to_chinese(skill)));

	if( (int)ob->query("jing") > gin_cost/5 + 1 )
	{
		if( userp(ob) ) ob->receive_damage("jing", gin_cost/5 + 1);
	}
	else
	{
		write("但是" + ob->name() + "显然太累了，没有办法教你什麽。\n");
		tell_object(ob, "但是你太累了，没有办法教" + me->name() + "。\n");
		return 1;
	}
		
	my_combat_exp = (int)me->query("combat_exp");
	if(my_combat_exp < 10000)
		grade = 1;
	else if(my_combat_exp < 80000)
		grade = 3;
	else if(my_combat_exp < 500000)
		grade = 7;
	else
		grade = 13;
	if ( grade < 1 )
		grade = 1;

	if((int)me->query("jing") > gin_cost )
	{
		if( (string)SKILL_D(skill)->type()=="martial"
		&&	my_skill * my_skill * my_skill / 10 > (int)me->query("combat_exp") ) {
			printf("也许是缺乏实战经验，你对%s的回答总是无法领会。\n", ob->name() );
		}
		else
		{
			if(skill_name = SKILL_D(skill)->query_skill_name(my_skill))
				printf("你听了%s的指导，对「%s」这一招似乎有些心得。\n", ob->name(),
					skill_name);
			else
				printf("你听了%s的指导，似乎有些心得。\n", ob->name());

			me->add("learned_points", 1);
			me->improve_skill(skill, grade * (10 + random((int)me->query("int") - 9)));
		}
	}
	else
	{
		gin_cost = me->query("jing");
		write("你今天太累了，结果什么也没有学到。\n");
	}

	me->receive_damage("jing", gin_cost );

	return 1;
}

int help(object me)
{
        write(@HELP
指令格式 : learn|xue <某人> <技能>
 
这个指令可以让你向别人请教有关某一种技能的疑难问题，当然，你请教的对象在这
项技能上的造诣必须比你高，而你经由这种方式学习得来的技能也不可能高於你所请
教的人，然而因为这种学习方式相当於一种「经验的传承」，因此学习可以说是熟悉
一种新技能最快的方法。

此外学习也需要消耗一些精力，而消耗的精力跟你自己、与你学习对象的悟性有关。

其他相关指令 : apprentice, practice, skills, study
HELP
        );
        return 1;
}
