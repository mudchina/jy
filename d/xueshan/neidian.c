//      neidian.c 内殿
//      Designed by secret (秘密)
//      97/04/09

inherit ROOM;

void create()
{
        set("short","内殿");
        set("long",@LONG
    这里是雪山寺的内殿，也是掌门人见客的地方。
LONG
        );

        set("exits",([
                "east" : __DIR__"tiantai",
                "west" : __DIR__"midao",
                "south" : __DIR__"zoulang3",
        ]));
      set("objects",([
        CLASS_D("xueshan")+"/jiumozhi" :1
      ]));

        setup();
        replace_program(ROOM);
}

