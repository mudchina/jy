//      hubian1.c 湖边小路
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
                "east" : __DIR__"hubian2",
                "west" : __DIR__"shenghu",
        ]));

        setup();
        replace_program(ROOM);
}
