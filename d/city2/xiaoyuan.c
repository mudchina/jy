// xiaoyuan.c 

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "小院");
	set("long", @LONG
这里是竹林深处的一座小院，环境十分幽雅。自然的啸声在林中回响，
直引枯木作龙吟。面对浩荡、神秘、不可把握的自然，你清楚地看到了自
身的渺小。在这无边的天地宇宙之中，一个人的生命是多么的短暂和轻飘，
又是多么的无足轻重和微不足道。你静静地站在这里，品味着这份久违的
孤独的静谧，竟久久不愿转身离去。北边就是“听雨轩”。
LONG
	);

	set("exits", ([
		"north" : "/d/city2/tingyu",
		"south" : __DIR__"zhulin5",
	]));
	create_door("south", "竹门", "north", DOOR_CLOSED);
	setup();
	replace_program(ROOM);
}

