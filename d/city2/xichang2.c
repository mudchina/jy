// Room: /city2/xichang2.c

inherit ROOM;

void create()
{
	set("short", "西长安街");
	set("long", @LONG
你走在街上，感到这里的街面要比别处的干净、整洁。再往西就是
西城门，直通往郊外。东边是空荡荡的街道。南边是一条行人稀少的小
巷，北边通往西单。
LONG
	);
        set("outdoors", "city2");

	set("exits", ([
		"east" : __DIR__"xichang1",
		"south" : __DIR__"alley1",
		"west" : __DIR__"ximen",
		"north" : __DIR__"xidan",
	]));

	setup();
	replace_program(ROOM);
}

