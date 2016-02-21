inherit ROOM;

void create()
{
	set("short", "地安门东大街");
	set("long", @LONG
这是一条东西走向的大道。西边通往地安门。东边通往王府井。
LONG
	);
        set("outdoors", "city2");

	set("exits", ([
		"east" : __DIR__"di_an1",
		"west" : __DIR__"di_anmen",
	]));
	set("objects", ([
		"/d/city2/npc/flowerg" :  2,
	]));

	setup();
	replace_program(ROOM);
}


