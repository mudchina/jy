//      houyuan.c 后院
//      Designed by secret (秘密)
//      97/04/09

inherit ROOM;

void create()
{
        set("short","后院");
        set("long",@LONG
    这里是雪山寺的后院，南边是练武场，北边是后门。
LONG
        );

        set("outdoors","xueshan");

        set("exits",([
                "eastdown" : __DIR__"dilao",
                "north" : __DIR__"houmen",
                "south" : __DIR__"chang",
        ]));

        setup();
        replace_program(ROOM);
}


