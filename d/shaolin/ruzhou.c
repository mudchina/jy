
inherit ROOM;

void create()
{
	set("short", "汝州城");
	set("long", @LONG
汝州城是本府的大城，立来是兵家必争之地。故州治在此驻
扎重兵，盘查南来北往的行人，并负责翦灭附近山上的草寇。城
内一队队官兵来来去去，一派森严气象。由于这里是北上京城的
必经之道，官兵盘查也十分严格。从这里折而向西，就是五岳之
一的嵩山了。
LONG
	);

	set("exits", ([
		"south" : __DIR__"yidao3",
		"north" : "/d/city2/road10",
		"west" : __DIR__"shijie1",
		"east" : __DIR__"marry_room",
	]));

        set("objects", ([
                "/d/city/npc/wujiang" : 1,
                "/d/city/npc/bing" : 3,
        ]));

	set("outdoors", "shaolin");
	setup();
	replace_program(ROOM);
}



