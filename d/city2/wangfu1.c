// Room: /city2/wangfu1.c

inherit ROOM;

void create()
{
	set("short", "王府井大街");
	set("long", @LONG
你走在一条繁忙的街道上，车水马龙，人来人往。许多人都从南边走
来，那里是东长安街。西边是一条宽阔的街道，不知为何却十分冷清。东
边是一家钱庄，可以听到叮叮当当的金银声音。
LONG
	);
        set("outdoors", "city2");


	set("exits", ([
		"east" : __DIR__"qianzhua",
		"south" : __DIR__"dongcha1",
		"west" : __DIR__"aobai1",
		"north" : __DIR__"wangfu2",
	]));
	set("objects", ([
		"/d/huashan/npc/youke" : 2,
	]));

	setup();
	replace_program(ROOM);
}

