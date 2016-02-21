// rankd.c
// 1996-02-15 dts ranking related to "shen"

#include <ansi.h>

string query_rank(object ob)
{
	mapping fam;

	int shen;
	int budd;

	if( ob->is_ghost() ) 
		return HIB "【 鬼  魂 】" NOR;

	shen = ob->query("shen");
	if ( (fam = ob->query("family")) && fam["family_name"] == "少林派" ) 
		budd = ob->query_skill("buddhism",1);

	switch(ob->query("gender")) {
	case "女性":
		switch(wizhood(ob)) {
		case "(admin)":		
			return HIR "【 女  神 】" NOR;
		case "(arch)":		
			return HIY "【 大巫女 】" NOR;
		case "(wizard)":	
			return HIG "【 巫  女 】" NOR;
		case "(apprentice)":	
			return HIC "【 小巫女 】" NOR;
		case "(immortal)":	
			return HIC "【 仙  女 】" NOR;
		default:
			if( ((int)ob->query("PKS") > 30) )
				return "【女杀人魔】";
			else if (shen >= 500000)
				return HIC "【旷世女侠】" NOR;
			else if (shen >= 50000)
				return HIC "【 女大侠 】" NOR;
			else if (shen >= 5000)
				return HIC "【 女  侠 】" NOR;
			else if (shen >= 500)
				return HIC "【 女少侠 】" NOR;
			else if (shen <= -500000)
				return HIC "【 女魔王 】" NOR;
			else if (shen <= -50000)
				return HIC "【 女大魔 】" NOR;
			else if (shen <= -5000)
				return HIC "【 女  魔 】" NOR;
			else if (shen <= -500)
				return HIC "【 女少魔 】" NOR;
			else if( (int)ob->query("thief") > 10 ) 
				return "【女 惯 窃】";
			else
			switch(ob->query("class")) {
			case "bonze":	
				return "【 尼  姑 】";
			case "taoist":	
				return "【 女  冠 】";
			case "bandit":	
				return "【 女飞贼 】";
			case "dancer":	
				return "【 舞  妓 】";
			case "scholar":	
				return "【 才  女 】";
			case "officer":	
				return "【 女  官 】";
			case "fighter":	
				return "【 女武者 】";
			case "swordsman":	
				return "【 女剑士 】";
			case "alchemist":	
				return "【 女方士 】";
			case "shaman":		
				return "【 女巫医 】";
			case "beggar":		
				return "【女叫化子】";
			default:			
				return "【 平  民 】";
			}
		}
	default:
		switch(wizhood(ob)) {
		case "(admin)":			
			return HIR "【 天  神 】" NOR;
		case "(arch)":			
			return HIY "【 大巫师 】" NOR;
		case "(wizard)":		
			return HIG "【 巫  师 】" NOR;
		case "(apprentice)":		
			return HIC "【巫师学徒】" NOR;
		case "(immortal)":		
			return HIC "【 仙  人 】" NOR;
		default:
			if( ((int)ob->query("PKS") > 30) )
				return "【 杀人魔 】";
			else if (shen >= 500000)
				return HIC "【旷世大侠】" NOR;
			else if (shen >= 50000)
				return HIC "【 大  侠 】" NOR;
			else if (shen >= 5000)
				return HIC "【 侠  客 】" NOR;
			else if (shen >= 500)
				return HIC "【 少  侠 】" NOR;
			else if (shen <= -500000)
				return HIC "【 魔  王 】" NOR;
			else if (shen <= -50000)
				return HIC "【 大  魔 】" NOR;
			else if (shen <= -5000)
				return HIC "【 魔  头 】" NOR;
			else if (shen <= -500)
				return HIC "【 少  魔 】" NOR;
			else if( (int)ob->query("thief") > 10 ) 
				return "【 惯  窃 】";
			else
				switch(ob->query("class")) {
				case "bonze":		
					if (budd >= 150)
						return HIY "【 长  老 】" NOR;
					else if (budd >= 120)
						return HIY "【 圣  僧 】" NOR;
					else if (budd >= 90)
						return HIY "【 罗  汉 】" NOR;
					else if (budd >= 60)
						return HIY "【 尊  者 】" NOR;
					else if (budd >= 40)
						return HIY "【 禅  师 】" NOR;
					else if (budd >= 30)
						return HIY "【 比  丘 】" NOR;
					else
						return "【 僧  人 】";
				case "taoist":		
					return "【 道  士 】";
				case "bandit":		
					return "【 盗  贼 】";
				case "scholar":		
					return "【 书  生 】";
				case "officer":		
					return "【 官  差 】";
				case "fighter":		
					return "【 武  者 】";
				case "swordsman":	
					return "【 剑  士 】";
				case "alchemist":	
					return "【 方  士 】";
				case "shaman":		
					return "【 巫  医 】";
				case "beggar":		
					return "【 叫化子 】";
				default:		
					return "【 平  民 】";
				}
		}
	}
}

string query_respect(object ob)
{
	int age;
	string str;

	if( stringp(str = ob->query("rank_info/respect")) )
		return str;

	age = ob->query("age");
	switch(ob->query("gender")) {
		case "女性":
			switch(ob->query("class")) {
			case "bonze":
				if( age < 18 ) return "小师太";
				else return "师太";
				break;
			case "taoist":
				if( age < 18 ) return "小仙姑";
				else return "仙姑";
				break;
			default:
				if( age < 18 ) return "小姑娘";
				else if( age < 50 ) return "姑娘";
				else return "婆婆";
				break;
			}
		case "男性":
		default:
			switch(ob->query("class")) {
			case "bonze":
				if( age < 18 ) return "小师父";
				else return "大师";
				break;
			case "taoist":
				if( age < 18 ) return "道兄";
				else return "道长";
				break;
			case "fighter":
			case "swordsman":
				if( age < 18 ) return "小老弟";
				else if( age < 50 ) return "壮士";
				else return "老前辈";
				break;
			default:
				if( age < 20 ) return "小兄弟";
				else if( age < 50 ) return "壮士";
				else return "老爷子";
				break;
			}
	}
}

string query_rude(object ob)
{
	int age;
	string str;

	if( stringp(str = ob->query("rank_info/rude")) )
		return str;

	age = ob->query("age");
	switch(ob->query("gender")) {
		case "女性":
			switch(ob->query("class")) {
			case "bonze":
				return "贼尼";
				break;
			case "taoist":
				return "妖女";
				break;
			default:
				if( age < 30 ) return "小贱人";
				else return "死老太婆";
				break;
			}
		case "男性":
		default:
			switch(ob->query("class")) {
			case "bonze":
				if( age < 50 ) return "死秃驴";
				else return "老秃驴";
				break;
			case "taoist":
				return "死牛鼻子";
				break;
			default:
				if( age < 20 ) return "小王八蛋";
				if( age < 50 ) return "臭贼";
				else return "老匹夫";
				break;
			}
	}
}

string query_self(object ob)
{
	int age;
	string str;

	if( stringp(str = ob->query("rank_info/self")) )
		return str;

	age = ob->query("age");
	switch(ob->query("gender")) {
		case "女性":
			switch(ob->query("class")) {
			case "bonze":
				if( age < 50 ) return "贫尼";
				else return "老尼";
				break;
			default:
				if( age < 30 ) return "小女子";
				else return "妾身";
				break;
			}
		case "男性":
		default:
			switch(ob->query("class")) {
			case "bonze":
				if( age < 50 ) return "贫僧";
				else return "老纳";
				break;
			case "taoist":
				return "贫道";
				break;
			default:
				if( age < 50 ) return "在下";
				else return "老头子";
				break;
			}
	}
}

string query_self_rude(object ob)
{
	int age;
	string str;

	if( stringp(str = ob->query("rank_info/self_rude")) )
		return str;

	age = ob->query("age");
	switch(ob->query("gender")) {
		case "女性":
			switch(ob->query("class")) {
			case "bonze":
				if( age < 50 ) return "贫尼";
				else return "老尼";
				break;
			default:
				if( age < 30 ) return "本姑娘";
				else return "老娘";
				break;
			}
		case "男性":
		default:
			switch(ob->query("class")) {
			case "bonze":
				if( age < 50 ) return "大和尚我";
				else return "老和尚我";
				break;
			case "taoist":
				return "本山人";
				break;
			default:
				if( age < 50 ) return "大爷我";
				else return "老子";
				break;
			}
	}
}
string query_close(object ob)
{
        int a1, a2;

	if (objectp(ob))
	{
        	if (a2 = (int)ob->query("mud_age"))
        	{
        		a1 = this_player()->query("mud_age");
       		} else 
       		{ 	
	       	 	a1 = this_player()->query("age");
			a2 = ob->query("age");
		}
	} else 
	{	
	 	a1 = this_player()->query("age");
	 	a2 = 0;
	}
							
        switch (ob->query("gender")) {
        case "女性" :
                if (a1 >= a2)
                        return "妹妹";
                else
                        return "姐姐";
                break;
        default :
                if (a1 >= a2)
                        return "弟弟";
                else
                        return "哥哥";
        }
}

string query_self_close(object ob)
{
        int a1, a2;

	if (objectp(ob))
	{
        	if (a2 = (int)ob->query("mud_age"))
        	{
        		a1 = this_player()->query("mud_age");
       		} else 
       		{ 	
	       	 	a1 = this_player()->query("age");
			a2 = ob->query("age");
		}
	} else 
	{	
       	 	a1 = this_player()->query("age");
       	 	a2 = 0;
	}
		
        switch (this_player()->query("gender")) {
        case "女性" :
                if (a1 >= a2)
                        return "姐姐我";
                else
                        return "小妹我";
                break;
        default :
                if (a1 >= a2)
                        return "愚兄我";
                else
                        return "小弟我";
	}
}
