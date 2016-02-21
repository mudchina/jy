// set.c
//    add color availability by ReyGod  in Dec. 1996
 
#define MAX_ENV_VARS	20

#include <ansi.h>

inherit F_CLEAN_UP;
 
int help();
 
int main(object me, string arg)
{
    int i;
    string term, *terms, *wiz_only;
	mixed data;
	string data0;
	mapping env;
 
    wiz_only = ({"invisibility", "immortal"});
 
	if( me != this_player(1) ) return 0;
 
	env = me->query("env");
 
	if( !arg || arg=="" ) {
		write("你目前设定的环境变数有：\n");
		if( !mapp(env) || !sizeof(env) )
			write("\t没有设定任何环境变数。\n");
		else {
			terms = keys(env);
			for(i=0; i<sizeof(terms); i++)
				printf("%-20s  %O\n", terms[i], env[terms[i]]);
		}
		return 1;
	}
 

	arg = replace_string(arg, "$BLK$", BLK);
	arg = replace_string(arg, "$RED$", RED);
	arg = replace_string(arg, "$GRN$", GRN);
	arg = replace_string(arg, "$YEL$", YEL);
	arg = replace_string(arg, "$BLU$", BLU);
	arg = replace_string(arg, "$MAG$", MAG);
	arg = replace_string(arg, "$CYN$", CYN);
	arg = replace_string(arg, "$WHT$", WHT);
	arg = replace_string(arg, "$HIR$", HIR);
	arg = replace_string(arg, "$HIG$", HIG);
	arg = replace_string(arg, "$HIY$", HIY);
	arg = replace_string(arg, "$HIB$", HIB);
	arg = replace_string(arg, "$HIM$", HIM);
	arg = replace_string(arg, "$HIC$", HIC);
	arg = replace_string(arg, "$HIW$", HIW);
	arg = replace_string(arg, "$NOR$", NOR);

	if( sscanf(arg, "%s %s", term, data)!=2 ) {
		term = arg;
		data = "YES";
	}
 	
	if( term && term!="" ) {
		if( mapp(env) && undefinedp(env[term]) && sizeof(env) >= MAX_ENV_VARS )
			return notify_fail("你设的环境变数太多了，请先用 unset 删掉几个吧。\n");
	   data0 = data;	/* save string* data */
	   sscanf(data, "%d", data);
           if((wiz_level(me) == 0) && (member_array(term, wiz_only) != -1))
              return notify_fail("只有巫师能用这个设定。\n");
	   if(data == data0) 		/* if data is 字符串 */
	         me->set("env/" + term, data + NOR);
	   else  me->set("env/" + term, data);		/* is 数字 */
 	 
	  printf("设定环境变数：%s = %O%s\n", term, data,NOR);
	   return 1;
	}
	return help();
}
 
int help()
{
	write(@TEXT
指令格式：set <变数名> [<变数值>]
 
这个指令让你设定一些环境变数，不加参数时会显示你目前设定的环境变数，不指定
变数值，则内定值为 "YES"。变数值若为字符串，可参照 nick 变化颜色.
for example : set msg_min, msg_mout, msg_home , etc.
 
取消变数设定请用 unset 指令。
 
至於有哪些环境变数可以设定，请见 help settings。
TEXT
	);
	return 1;
}
