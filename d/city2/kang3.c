
inherit ROOM;


void create()
{
	set("short", "康府后院");
	set("long", @LONG
这里是康府后院，西首是一个小花园。北边有一条长廊走道直通往
内堂。东边是一间马棚。南边就是康亲王最爱去的私人练武场。
LONG
);

	set("exits", ([
		"west" : __DIR__"huayuan",
		"east" : __DIR__"mapeng",
		"north" : __DIR__"neitang",
		"south" : __DIR__"kang2",
	]));

	set("objects", ([
		"/d/city2/npc/guanjia" : 1,
		"/d/city/npc/jiading" : 2,
	]));

	setup();
	replace_program(ROOM);
}

