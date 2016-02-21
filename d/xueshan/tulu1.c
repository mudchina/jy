//      tulu1.c 土路
//      Designed by secret (秘密)
//      97/04/08

inherit ROOM;

void create()
{
        set("short","土路");
        set("long",@LONG
    这是一条不起眼的土路，却是连接雪山寺与中原的必经之路。
LONG
        );

        set("outdoors","xueshan");

        set("exits",([
                "east" : __DIR__"caoyuan",
                "west" : __DIR__"tulu2",
        ]));

        setup();
        replace_program(ROOM);
}

