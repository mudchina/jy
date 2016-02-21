inherit ROOM;

void create()
{
	set("short", "西四北大街");
	set("long", @LONG
这里是西四北大街。南边通往西单。东边通向地安门,北面是一间书院。
LONG
	);
        set("outdoors", "city2");

	set("exits", ([
		"south" : __DIR__"xisi",
		"east" : __DIR__"di_an4",
		"north" : __DIR__"shuyuan",
	]));
	set("objects", ([
		"/d/taishan/npc/jian-ke": 1,
	]));
	setup();
	replace_program(ROOM);
}


