// Room: /d/huashan/midong.c

#include <room.h>
inherit ROOM;

void create()
{
       set("short","秘洞");
       set("long", @LONG
洞里漆黑一团，透过从洞口远远透过来的一丝亮光你发现四周的洞壁
上似乎刻着一些小人，但怎么也看不清楚。
LONG
     );

	set("exits", ([
		"northeast" : __FILE__,
		"southeast" : __FILE__,
		"southwest" : __FILE__,
		"northwest" : __FILE__,
	]));
	setup();
}

void init()
{
	object ob;
	int jing, jing_cost;

	ob = this_player();
	jing = ob->query("jing");
	jing_cost = ob->query("kar");

	if(jing < jing_cost)
		ob->unconcious();
	ob->add("jing", -jing_cost);
}

int valid_leave(object me, string dir)
{
	if (random((int)me->query("kar")) > 15)
		me->add_temp("mark/steps",1);
	if (random((int)me->query("kar")) < 10)
		me->add_temp("mark/steps",-1); 
        
	if (me->query_temp("mark/steps") == 10)
	{
		me->move("/d/huashan/houshan");
		me->delete_temp("mark/steps");
		return notify_fail("你瞎打瞎撞，忽然发现眼前一亮，已经来到了人迹罕至的后山。\n");
	}  

	if (me->query_temp("mark/steps") == -10)
	{
		me->move("/d/huashan/siguoya");
		me->delete_temp("mark/steps");
		return notify_fail("你累得半死，终於走出了山洞。\n");
	}
           
	return ::valid_leave(me, dir);
}
