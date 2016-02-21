//      cangjingge.c 藏经阁
//      Designed by secret (秘密)
//      97/04/09

inherit ROOM;

void create()
{
        set("short","藏经阁");
        set("long",@LONG
    这里是雪山寺的藏经之处。
LONG
        );

        set("exits",([
                "southeast" : __DIR__"dating",
        ]));

        setup();
        replace_program(ROOM);
}

