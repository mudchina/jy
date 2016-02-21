#include <ansi.h>

inherit ROOM;

void create()
{
    set("short", "大院");
    set("long", @LONG
这是一个破旧的大院。院内十分宽阔，可容百人。正中
一口天井,再往里是座大厅.
LONG
    );

    set("exits", ([
		"north" : "/d/city2/zhuang5",
		"south" : "/d/city2/zhuang3",
    ]));
    set("objects", ([
		"/d/shenlong/npc/zhang3": 1,
    ]));
    set("outdoors", "city2");
    setup();
   replace_program(ROOM); 
}


