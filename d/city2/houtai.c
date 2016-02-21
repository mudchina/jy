
inherit ROOM;

void create()
{
	set("short", "戏院后台");
	set("long", @LONG
这里是戏院后台，几个戏子正在化妆。从北边可以上台。
LONG
	);
        set("outdoors", "city2");


	set("exits", ([
  		"west" : "/d/city2/xiyuan",
  		"northup" : "/d/city2/stage",
	]));
        set("objects", ([
                "/d/city2/npc/xizi" : 2,
        ]));
	setup();
	replace_program(ROOM);
}
