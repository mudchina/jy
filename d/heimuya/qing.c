//ROM dating
inherit ROOM;
void create()
{
        set("short", "青龙堂大厅");
        set("long",
             "这是『日月神教』下第三大堂:青龙堂的大厅.一位长者居中,\n"
         "神情恍惚.\n"
        );

        set("exits", ([
                "north" : __DIR__"chlang2",
                "east" : __DIR__"tang",
        ]));
		set("objects",([
                          __DIR__"npc/jiabu"   :1,
	]));
        setup();

        replace_program(ROOM);
}