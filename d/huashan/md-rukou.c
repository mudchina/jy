// /d/huashan/md-rukou.c
// Hop 05/15/97

#include <room.h>

inherit ROOM;

void create()
{ 
	set("short","山洞");
	set("long", @LONG
这里是山洞的入口。山洞里面漆黑一团，你根本分不清东南西北，只
好胡乱瞎闯了。
LONG
	);
	set("exits", ([
		"north" : __DIR__"siguoya",
		"south" : __DIR__"midong",
	]));             
	setup();
	replace_program(ROOM);
}
