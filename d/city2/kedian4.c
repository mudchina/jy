
inherit ROOM;

void create()
{
	set("short", "西客房");
	set("long", @LONG
这里是西客房，一个掌柜和两个伙计躲在角落里瑟瑟发抖。
LONG
	);

	set("exits", ([
		"east" : __DIR__"kedian2",
	]));
	set("objects", ([
		"/d/city2/npc/zhanggui":1,
		"/d/city2/npc/huoji":2,
	]));

	setup();
	replace_program(ROOM);
}



