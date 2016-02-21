//      dating.c 大厅
//      Designed by secret (秘密)
//      97/04/09

inherit ROOM;

void create()
{
        set("short","大厅");
        set("long",@LONG
    这里是寺内的大厅，几位有道的高僧在高声辩论。
LONG
        );

        set("exits",([
                "east" : __DIR__"zoulang1",
                "west" : __DIR__"zoulang2",
                "northeast" : __DIR__"chanshi",
                "northwest" : __DIR__"cangjingge",
        ]));
set("objects", ([
CLASS_D("xueshan")+"/fawang" :1,
]));

        setup();
        replace_program(ROOM);
}

