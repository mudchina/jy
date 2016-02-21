// Room: /city2/aobai1.c


inherit ROOM;

void create()
{
	set("short","街道");
	set("long", @LONG
再往西就是鳌拜府了，谁也不敢往那儿去。东面是王府井大街。
LONG
	);

	set("exits", ([
		"west" : __DIR__"aobai2",
		"east" : __DIR__"wangfu1",
	]));

	set("objects", ([
		"/d/city/npc/bing" : 2,
	]));

	setup();
}

