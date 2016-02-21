//      chang.c 练武场
//      Designed by secret (秘密)
//      97/04/09

inherit ROOM;

void create()
{
        set("short","练武场");
        set("long",@LONG
    这里是雪山寺练武场，僧人门在此习武。
LONG
        );

        set("outdoors","xueshan");

        set("exits",([
                "east" : __DIR__"guangchang",
                "west" : __DIR__"kufang",
                "north" : __DIR__"houyuan",
        ]));
set("objects", ([
CLASS_D("xueshan")+"/gelunbu" :1,
		__DIR__"npc/x_lama" : 1 ,
]));

        setup();
        replace_program(ROOM);
}


