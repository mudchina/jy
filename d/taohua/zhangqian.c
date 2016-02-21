#include <room.h>

inherit ROOM;

void create()
{
    set("short", "归云庄正门");
    set("long",@LONG
这里是归云山庄的正门。庄门显得宏伟高大，装饰华丽，两
边的院墙蜿蜒而去，竟然望不到尽头。庄门前种着几株桃树，树
上桃花正绚烂地绽放着。
LONG);

	set("exits", ([
        "south" : __DIR__"qianyuan1",
        "north" : __DIR__"tingzi",
	"east"  : __DIR__"shiqiao" ,       
	]));
        
            set("objects", ([
                __DIR__"npc/puren1" : 1,
                __DIR__"npc/puren3" : 1,
        ]));
    set("outdoors", "taohua");
    setup();
    
}

