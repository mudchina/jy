//      caoyuan.c 草原
//      Designed by secret (秘密)
//      97/04/08

inherit ROOM;

void create()
{
        set("short","草原");
        set("long",@LONG
这里是雪山脚下的一片草原。北面是起伏的群山，山顶上积着
终年不化的雪。西边有一条土路。
LONG
        );

        set("outdoors","xueshan");

        set("exits",([
                "west" : __DIR__"tulu1",
                "northeast" : "/d/xingxiu/silk4" ,
        ]));

        set("objects",([
                __DIR__"npc/yetu" : 4 ,
        ]));

        setup();
        replace_program(ROOM);
}
