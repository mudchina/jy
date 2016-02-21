
inherit ROOM;

void create()
{
	set("short", "屠宰场");
	set("long", @LONG
这里是屠宰场，空气中弥漫着猪的气味。偶尔一阵热风吹过，
顿时一股臭气袭来，直熏得人作呕。一个中年人手握屠刀，指挥
着伙计们杀猪去毛。这就是京城最大的屠宰场，据说宫里所有的
猪肉都是从这里送去的。
LONG
	);

	set("exits", ([
		"east" : __DIR__"nandaj2",
	]));
	set("objects", ([
		"/d/city2/npc/lilishi":1,
		"/d/city2/npc/huoji1":2,
	]));
	setup();
	replace_program(ROOM);
}
