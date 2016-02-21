//      shanjiao.c 山脚
//      Designed by secret (秘密)
//      97/04/09

inherit ROOM;

void create()
{
        set("short","山脚");
        set("long",@LONG
    这里是山脚下的一片平地，山上不远处就是远近闻名的雪山寺。
LONG
        );

        set("outdoors","xueshan");

        set("exits",([
                "northup" : __DIR__"shanlu1",
                "south" : __DIR__"hubian4",
        ]));

        setup();
        replace_program(ROOM);
}

