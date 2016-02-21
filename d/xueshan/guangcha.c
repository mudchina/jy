//      guangchang.c 广场
//      Designed by secret (秘密)
//      97/04/09

inherit ROOM;

void create()
{
        set("short","广场");
        set("long",@LONG
    这里是雪山寺内的广场。
LONG
        );

        set("outdoors","xueshan");

        set("exits",([
                "east" : __DIR__"xiaoyuan",
                "west" : __DIR__"chang",
                "north" : __DIR__"dadian",
                "south" : __DIR__"shanmen",
        ]));

        setup();
        replace_program(ROOM);
}


