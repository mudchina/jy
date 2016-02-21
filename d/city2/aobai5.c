// Room: /city2/aobai5.c


inherit ROOM;

void create()
{
	set("short", "鳌府厨房");
	set("long", @LONG
一进门，一股香气扑鼻而来，熏得你直流口水。灶台上满是油烟，
一个肥肥胖胖的家伙正在炒菜,一看就象个大厨师。
LONG
	);

	set("exits", ([
		"south" : __DIR__"aobai3",
	]));
	set("objects", ([
		__DIR__"npc/chushi" : 1,
	]));
	setup();
	replace_program(ROOM);
}

