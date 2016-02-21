//      mishi.c 密室
//      Designed by secret (秘密)
//      97/04/09

inherit ROOM;

void create()
{
        set("short","密室");
        set("long",@LONG
    这是一条小房间。
LONG
        );

        set("exits",([
                "south" : __DIR__"midao",
                "down" : "/d/city/guangchang" ,
        ]));

        setup();
        replace_program(ROOM);
}
