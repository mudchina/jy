#include <ansi.h>

inherit ROOM;

void create()
{
    set("short", "大道");
    set("long", @LONG
这是一条宽敞的大道。全由乱石堆成,显然曾花了不少人力.
东面是一个宽阔的练武场,西边是一片开阔地.
LONG
    );

    set("exits", ([
		"east" : __DIR__"wuchang",
		"west" : __DIR__"kongdi",
    ]));
    set("objects", ([
		"/d/shenlong/npc/xuxuetin": 1,
    ]));
    set("outdoors", "shenlong");
    setup();
   replace_program(ROOM); 
}


