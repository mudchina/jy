//      zoulang2.c 走廊
//      Designed by secret (秘密)
//      97/04/09

inherit ROOM;

void create()
{
        set("short","走廊");
        set("long",@LONG
    这里是雪山寺内的走廊。
LONG
        );

        set("exits",([
                "down" : __DIR__"cedian2",
                "east" : __DIR__"dating",
                "eastup" : __DIR__"zoulang3",
        ]));

        setup();
        replace_program(ROOM);
}

