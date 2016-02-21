// Room: /city2/duchang2.c

inherit ROOM;

void create()
{
	set("short", "赌场");
	set("long", @LONG
	这里有四条走廊通向不同的房间。
LONG
	);

	set("exits", ([
		"east" : "/d/city2/eproom",
		"west" : "/d/city2/wproom",
		"south" : "/d/city2/sproom",
		"north" : "/d/city2/nproom",
		"down" : __DIR__"duchang",
	]));

	setup();
	replace_program(ROOM);
}

