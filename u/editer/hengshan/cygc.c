// /u/editer/hengshan/cygc.c
// 

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "瓷窑口广场");
	set("long", @LONG
这里是瓷窑口的正中心，地面是黄土夯成的，虽然是城市
的中心，但也冷冷清清的没有什么人，偶尔有人路过，也是急
匆匆地走过去了。广场的北角有个牌坊（pai fang），北面好
象是一条稍微繁华一点的街道，南面是通向中原的大路。西面
有一处规模宏大的官衙。
LONG
	);
        set("no_sleep_room",1);
        set("outdoors", "city");

	set("item_desc", ([
		"pai fang" : "上面写着："+HIR"北疆锁匙"NOR+"四个大字。\n",
	]));

	set("exits", ([
		"east" : __DIR__"cydongjie",
		"south" : __DIR__"cynanjie",
		"west" : __DIR__"cyxijie",
		"north" : __DIR__"cybeijie",
	]));

	set("objects", ([
		
	]));

	setup();
}

