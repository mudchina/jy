
#include <weapon.h>

#ifdef AS_FEATURE
#include <dbase.h>
#else
inherit EQUIP;
#endif

// axe.c
varargs void init_axe(int damage, int flag)
{
	
	set("weapon_prop/damage", damage);
	set("flag", (int)flag | EDGED);
	set("skill_type", "axe");
	if( !query("actions") ) {
		set("actions", (: call_other,WEAPON_D, "query_action" :) );
		set("verbs", ({ "chop", "slice", "hack" }) );
	}
}


// blade.c
varargs void init_blade(int damage, int flag)
{
	
	set("weapon_prop/damage", damage);
	set("flag", (int)flag | EDGED);
	set("skill_type", "blade");
	if( !query("actions") ) {
		set("actions", (: call_other,WEAPON_D, "query_action" :) );
		set("verbs", ({ "slash", "slice", "hack" }) );
	}
}

// club.c
varargs void init_club(int damage, int flag)
{
	
	set("weapon_prop/damage", damage);
	set("flag", (int)flag | LONG );
	set("skill_type", "club");
	if( !query("actions") ) {
		set("actions", (: call_other,WEAPON_D, "query_action" :) );
		set("verbs", ({ "bash", "crush", "slam" }) );
	}
}

// dagger.c

varargs void init_dagger(int damage, int flag)
{
	

	set("weapon_prop/damage", damage);
	set("flag", flag | EDGED | SECONDARY );
	set("skill_type", "dagger");
	if( !query("actions") ) {
		set("actions", (: call_other,WEAPON_D, "query_action" :) );
		set("verbs", ({ "slice", "pierce", "thrust" }) );
	}
}

// fork.c

varargs void init_fork(int damage, int flag)
{
	

	set("weapon_prop/damage", damage);
	set("flag", (int)flag | POINTED);
	set("skill_type", "fork");
	if( !query("actions") ) {
		set("actions", (: call_other,WEAPON_D, "query_action" :) );
		set("verbs", ({ "thrust" }) );
	}
}

// hammer.c

varargs void init_hammer(int damage, int flag)
{
	

	set("weapon_prop/damage", damage);
	set("flag", flag );
	set("skill_type", "hammer");
	if( !query("actions") ) {
		set("actions", (: call_other, WEAPON_D, "query_action" :) );
		set("verbs", ({ "bash", "crush", "slam" }) );
	}
}

// staff.c

varargs void init_staff(int damage, int flag)
{
	

	set("weapon_prop/damage", damage);
	set("flag", (int)flag | LONG );
	set("skill_type", "staff");
	if( !query("actions") ) {
		set("actions", (: call_other,WEAPON_D, "query_action" :) );
		set("verbs", ({ "bash", "crush", "slam" }) );
	}
}

// sword.c


varargs void init_sword(int damage, int flag)
{
	

	set("weapon_prop/damage", damage);
	set("flag", (int)flag | EDGED);
	set("skill_type", "sword");
	if( !query("actions") ) {
		set("actions", (: call_other,WEAPON_D, "query_action" :) );
		set("verbs", ({ "slash", "slice", "thrust" }) );
	}
}

// whip.c

varargs void init_whip(int damage, int flag)
{
	

	set("weapon_prop/damage", damage);
	set("flag", flag );
	set("skill_type", "whip");
	if( !query("actions") ) {
		set("actions", (: call_other,WEAPON_D, "query_action" :) );
		set("verbs", ({ "whip" }) );
	}
}


int set_desc(int w_lv,string w_or,string w_name)
{
	object weapon,me;
	string w_liang,player_name,make_time;
	string result1,result2,result3,result4,result;

	weapon = this_object();
	me = this_player();
	w_liang = weapon->query("unit");
	player_name=me->query("name");
	make_time=me->query("weapon/时间");

	result1="\t      这是一"+w_liang+"用"+w_or+"打造而成的"+w_name+"。\n";
	switch(w_or) {
		case "千年神木":
			result2="看起来黑中透红，似乎十分坚硬。";
			break;
		case "海底金母":
			result2="看起来紫澄澄的，似乎十分沉重。";
			break;
		case "寒丝羽竹":
			result2="看起来晶莹碧绿，透着丝丝的寒意。";
			break;
		default:
			break;
		}
	switch(w_lv) {
		case 1:
			result3="但似乎威力还没有开发出来，是习武之\n人常用的练武兵器。\n";
			break;
		case 2:
			result3="但似乎威力并不很大，象是江湖人常用\n的护身兵刃。\n";
			break;
		case 3:
			result3="隐隐的散发着一丝令人不安的气息.\n";
			break;
		case 4:
			result3="散发着一丝令人不安的气息, 显然普通\n兵器已不能和他相比了。\n";
			break;
		case 5:
			result3="向外散发着一丝迷蒙的雾气，竟有一种\n霸气散发了出来。\n";
			break;
		case 6:
			result3="一股霸气直冲霄汉，直叫神惊鬼泣.\n";
			break;
		case 7:
			result3="霸气似乎有所收敛，但更多的是有了一股\n骇人的戾气。\n";
			break;
		case 8:
			result3="冲天的戾气叫人看了不由心惊胆战，不愿\n再看第二眼。\n";
			break;
		case 9:
			result3="戾气似乎削减了不少，一股温和的王者之\n气透了出来。\n";
			break;
		case 10:
			result3="一股温和的王者之气悠悠的散发了出来.\n";
			break;
		default:
			result3="一种庄严，温和，凛然而不可侵犯的气息让\n人不敢有一丝亵渎之意, 它已经返朴归真，成为真正的上古神兵. \n";
		}

	result4="上面用小篆刻着一行小字："+player_name+"造于"+make_time+"\n";
	result=result1+result2+result3+result4;
	weapon->set("long",result);

}