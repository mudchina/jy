inherit ROOM;

void create()
{
	set("short", "瓷窑口北街");
	set("long", @LONG
这是一条青石板街道，向南北两头延伸。街上静悄悄地很
是冷清，只有几个。东边是城中心的广场。南边是一座小庙。北边是几间
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

