//      hubian4.c 湖边小路
//      Designed by secret (秘密)
//      97/04/09

inherit ROOM;

void create()
{
        set("short","湖边小路");
        set("long",@LONG
    这是圣湖边的小路。
LONG
        );

        set("outdoors","xueshan");

        set("exits",([
                "north" : __DIR__"shanjiao",
                "south" : __DIR__"hubian3",
        ]));

        setup();
        replace_program(ROOM);
}
