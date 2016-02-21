

inherit ROOM;

void create()
{
	set("short", "西长安街");
	set("long", @LONG
这是一条宽阔的青石板街道，向东西两头延伸。往西望去，长长的街道
看不到头。东边就是天安门。一阵阵喝采声不时从北边的戏院传来。南边就
是京城最著名的‘回春堂’药店。
LONG
	);
        set("outdoors", "city2");

	set("exits", ([
		"east" : "/d/city2/tian_anm",
		"south" : "/d/city2/huichunt",
		"west" : "/d/city2/xichang2",
		"north" : "/d/city2/xiyuan",
	]));
	set("objects", ([
		"/d/city2/npc/flowerg": 1,
	]));
	setup();
}

int valid_leave(object me, string dir)
{
me->delete_temp("warned");
me->delete_temp("hastryup");
return ::valid_leave(me, dir);
}