//      kufang.c 库房
//      Designed by secret (秘密)
//      97/04/09

inherit ROOM;


void create()
{
        set("short","库房");
        set("long",@LONG
这里是练武场旁边的小库房，房中有些备用的武器。
LONG
        );

        set("exits",([
                "east" : __DIR__"chang",
        ]));

	set("objects", ([
		"/d/village/obj/zhujian" : random(4),
		"/d/xueshan/obj/mugun" : random(4),
		"/d/xueshan/obj/falun" : random(4),
	]));


        setup();
        replace_program(ROOM);
}


