
inherit ROOM;

void create()
{
	set("short", "小道");
	set("long", @LONG
你走在一条小道上。东边就是海港了.
LONG
	);

	set("exits", ([
		"east" : "/d/city2/haigang",
		"west" : "/d/city2/road1",
		"south" : "/d/shaolin/ruzhou",
		"north" : "/d/city2/road9",
	]));

	set("objects",([
		"/d/taishan/npc/tiao-fu" : 1,
	]));

 	set("outdoors", "city2");
	setup();
	replace_program(ROOM);
}



