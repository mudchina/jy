// score.c

#include <ansi.h>
#include <combat.h>

inherit F_CLEAN_UP;

//string *gift_ranking = ({"下下之选","下等", "中下", "中等", "中上", "上等",
//	"上上之选"});

string bar_string = "■■■■■■■■■■■■■■■■■■■■■■■■■";
string blank_string = "□□□□□□□□□□□□□□□□□□□□□□□□□";
//string bar_string = "●〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓";
//string blank_string= "●————————————————————————";

string display_attr(int gift, int value);
string status_color(int current, int max);
string date_string(int date);
string tribar_graph(int val, int eff, int max, string color);

void create() { seteuid(ROOT_UID); }

int main(object me, string arg)
{
	object ob;
	mapping my;
	string line, str, skill_type;
	object weapon;
	int attack_points, dodge_points, parry_points;

	seteuid(getuid(me));

	if(!arg)
		ob = me;
	else if (wizardp(me)) {
		ob = present(arg, environment(me));
		if (!ob) ob = find_player(arg);
		if (!ob) ob = find_living(arg);
		if (!ob) return notify_fail("你要察看谁的状态？\n");
	} else
		return notify_fail("只有巫师能察看别人的状态。\n");

	my = ob->query_entire_dbase();

	line = sprintf( BOLD "%s" NOR "%s\n\n", RANK_D->query_rank(ob), ob->short(1) );
	line += sprintf(" 你是一%s%s岁的%s%s，%s生。\n\n",
		ob->query("unit"),
		chinese_number(ob->query("age")), 
		ob->query("gender"),
		ob->query("race"),
		CHINESE_D->chinese_date(((int)ob->query("birthday") - 14*365*24*60) * 60) );

	if( 1 || wizardp(me) || (int)ob->query("age") >= 18 ) {
		line += sprintf(
			" 膂力：[%s]  悟性：[%s]  根骨：[%s]  身法：[%s]\n\n", 
                        display_attr(my["str"], ob->query("str")),
                        display_attr(my["int"], ob->query("int")),
                        display_attr(my["con"], ob->query("con")),
                        display_attr(my["dex"], ob->query("dex")));
	}

	if( mapp(my["family"]) ) {
		if( my["family"]["master_name"] )
			line = sprintf("%s 你的师父是%s。\n\n",
				line, my["family"]["master_name"] );
	}

	line += " <精>  " + tribar_graph(my["jing"], my["eff_jing"], my["max_jing"], GRN) + "\n";
	line += " <气>  " + tribar_graph(my["qi"], my["eff_qi"], my["max_qi"], HIR) + "\n";
//	line += " <神>  " + tribar_graph(my["sen"], my["eff_sen"], my["max_sen"], HIB) + "\n";

	if( objectp(weapon = ob->query_temp("weapon")) )
		skill_type = weapon->query("skill_type");
	else
		skill_type = "unarmed";

	attack_points = COMBAT_D->skill_power(ob, skill_type, SKILL_USAGE_ATTACK);
	parry_points = COMBAT_D->skill_power(ob, skill_type, SKILL_USAGE_DEFENSE);
	dodge_points = COMBAT_D->skill_power(ob, "dodge", SKILL_USAGE_DEFENSE);

	if (wizardp(me))
	line += sprintf("\n 战斗攻击力 " HIW "%d (+%d)" NOR "\t\t战斗防御力 " HIW "%d (+%d)\n\n" NOR,
		attack_points/100 + 1, ob->query_temp("apply/damage"),
		(dodge_points + (weapon? parry_points: (parry_points/10)))/100 + 1, ob->query_temp("apply/armor"));
	else line += "\n";

	line += " 食物：" + tribar_graph(my["food"], ob->max_food_capacity(), ob->max_food_capacity(), YEL) + "\n";
	line += " 饮水：" + tribar_graph(my["water"], ob->max_water_capacity(), ob->max_water_capacity(), CYN) + "\n";

	line += sprintf("\n 你到目前为止总共杀了 %d 个人，其中有 %d 个是其他玩家。\n\n",
		my["MKS"] + my["PKS"], my["PKS"]);

	line += sprintf("     　神： " RED "%d\n" NOR, ob->query("shen") );
	line += sprintf(" 潜    能： " HIY "%d (%d%%)\n" NOR,
		(int)ob->query("potential") - (int)ob->query("learned_points"),
		(1 + (int)ob->query("learned_points")) * 100 / (1 + (int)ob->query("potential")) );
	line += sprintf(" 实战经验： " HIM "%d\n\n" NOR, ob->query("combat_exp") );
//	line += sprintf(" 综合评价： " HIC "%d\n\n" NOR, ob->query("score") );

	write(line);
	return 1;
}

string display_attr(int gift, int value)
{
	if( value > gift ) return sprintf( HIY "%3d" NOR, value );
	else if( value < gift ) return sprintf( CYN "%3d" NOR, value );
	else return sprintf("%3d", value);
}

string status_color(int current, int max)
{
	int percent;

	if( max ) percent = current * 100 / max;
	else percent = 100;

	if( percent > 100 ) return HIC;
	if( percent >= 90 ) return HIG;
	if( percent >= 60 ) return HIY;
	if( percent >= 30 ) return YEL;
	if( percent >= 10 ) return HIR;
	return RED;
}

string tribar_graph(int val, int eff, int max, string color)
{
	return color + bar_string[0..(val*25/max)*2-1]
		+ ((eff > val) ? blank_string[(val*25/max)*2..(eff*25/max)*2-1] : "") + NOR;
}

int help(object me)
{
	write(@HELP
指令格式 : score
           score <对象名称>                   (巫师专用)

这个指令可以显示你(你)或指定对象(含怪物)的基本资料。
基本资料的设定请参阅 'help setup'。

see also : hp
HELP
    );
    return 1;
}
