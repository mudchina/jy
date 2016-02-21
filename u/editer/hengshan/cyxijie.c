// Room: /city/xidajie1.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "瓷窑口西街");
	set("long", @LONG
这是一条青石板街道，向东西两头延伸。街上静悄悄地很
是冷清。东边是城中心的广场。南边是一座小庙。北边是几间
破旧的民房。
LONG
	);
        set("outdoors", "city");

	set("exits", ([
		"east" : __DIR__"cygc",
		"south" : __DIR__"cyxiaomiao",
		"west" : __DIR__"cyximen",
		"north" : __DIR__"minju1",
	]));

	setup();
	replace_program(ROOM);
}

