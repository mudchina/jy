// ce.c

#include <ansi.h>
#include <net/dns.h>

inherit F_CLEAN_UP;

int help(object me);

	void create() {seteuid(getuid());}

int main(object me, string arg)
{
      object obj;

      if(!me->query("couple/have_couple")) return help(me);

	obj = find_player(me->query("couple/couple_id"));

	if(!obj || (!wizardp(me) && !me->visible(obj)))
                return notify_fail("你的伴侣现在不在....\n");

	if (!wizardp(me) && obj->query_temp("pigging_seat"))
		return notify_fail("你的伴侣正在拱猪，听不到悄悄话....\n");

	if( !arg ){
//        if((string)me->query("gender") == "女性") 
        message_vision(MAG "\n$N多么思念"+me->query("couple/couple_gender")
                          +me->query("couple/couple_name")+"啊...\n"NOR, me);
//        else
//        message_vision(MAG "\n$N多么思念妻子"+me->query("couple/couple_name")+"啊...\n"NOR, me);

 tell_object(obj,sprintf(MAG"你的"+obj->query("couple/couple_gender")+"在思念你... ...\n" NOR));
                }
      else {
       if( arg == "kiss" ) {

        if( objectp(present(me->query("couple/couple_id"), environment(me))) )
        message_vision(MAG "\n$N拥抱着$n深深地一吻...\n"NOR, me,obj);
        else {
       write(MAG "你多想拥抱你的" + me->query("couple/couple_gender") + "深深地一吻...\n" NOR);
	  tell_object(obj, sprintf( MAG "你的%s多想拥抱你，给你深深的一吻... ...\n" NOR,
	 	  obj->query("couple/couple_gender"))); } }

       else {
	  write(MAG "你悄悄告诉你的" + me->query("couple/couple_gender") + "：" + arg + "\n" NOR);
	  tell_object(obj, sprintf( MAG "你的%s悄悄告诉你：%s\n" NOR,
	 	  obj->query("couple/couple_gender"), arg)); }
           }

	return 1;
}

int help(object me)
{
	write(@HELP
指令格式：ce [kiss][<讯息>]

你可以用这个指令对你的伴侣说悄悄话。

HELP
	);
	return 1;
}
