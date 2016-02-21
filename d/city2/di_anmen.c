// Room: /city2/di_anmen.c

#include <room.h>

inherit ROOM;


void create()
{
	set("short", "地安门");
	set("long", @LONG
这里就是地安门广场，灰色的城墙给人以庄严肃穆之感，再往
南就是皇宫后门。门前有座小桥，一条护城河绕城而过。越过小桥
向南望去，紫禁城的轮廓益发显得雄伟高大。一条笔直的大道横贯
东西，东边是地安门东街，西边是地安门西街。北边通往安定门。
LONG
	);

	set("exits", ([
		"south" : "/d/city2/hbridge",
		"north" : "/d/city2/anding",
		"west" : "/d/city2/di_an3",
		"east" : "/d/city2/di_an2",
	]));
	set("objects", ([
		"/d/city/npc/bing" : 2,
	]));
	set("outdoors", "city2");
	setup();
	replace_program(ROOM);
}

