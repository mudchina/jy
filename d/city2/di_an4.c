inherit ROOM;

void create()
{
	set("short", "地安门西大街");
	set("long", @LONG
这是一条东西走向的大道。东边通往地安门。西边通往西四北大街。
南边是西厂了，一般人都不敢往那儿去。
LONG
	);
        set("outdoors", "city2");

	set("exits", ([
		"east" : __DIR__"di_an3",
		"west" : __DIR__"xisi2",
		"south" : __DIR__"xichangdamen",
	]));
	setup();
	replace_program(ROOM);
}


