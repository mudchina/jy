// semote.c
//modified by ytan Dec 18 1996
 
#include "/doc/help.h"
 
inherit F_CLEAN_UP;
 
int main(object me, string arg)
{
        string *e;
        int i;
        string str1,str;
 
        str="";
        e = sort_array(EMOTE_D->query_all_emote(), 1);
 
        for(i=0; i<sizeof(e); i++) {
                str1=sprintf("%-15s%s", e[i], (i%5==4)?"\n": "");
                str+=str1;
        }
        me->start_more(str);
        write("\n");
        return 1;
}
 
int help(object me)
{
  write(@HELP
指令格式 : semote
 
这个指令可以列出目前所能使用的emote.
HELP
    );
    return 1;
}