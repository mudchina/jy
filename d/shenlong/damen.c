#include <ansi.h>

inherit ROOM;
string* npcs = ({
	"/d/shenlong/npc/boy",
	"/d/shenlong/npc/boy2",
	"/d/shenlong/npc/boy3",
	"/d/shenlong/npc/boy4",
	"/d/shenlong/npc/girl",
	"/d/shenlong/npc/boy",
	"/d/shenlong/npc/boy2",
	"/d/shenlong/npc/boy3",
	"/d/shenlong/npc/boy4",
	"/d/shenlong/npc/girl",
	"/d/shenlong/npc/girl",
});

void create()
{
    set("short", "大门");
    set("long", @LONG
这是间很大的竹屋。门外站着几个年轻弟子.再住北就是神龙教
大厅,隔得虽远,却也可以听得到厅上众人齐声念颂之声.
LONG
    );

    set("exits", ([
		"south" : __DIR__"road2",
		"north" : __DIR__"dating",
    ]));
    set("objects", ([
		npcs[random(sizeof(npcs))] : 1,
		npcs[random(sizeof(npcs))] : 1,
		npcs[random(sizeof(npcs))] : 1,
		npcs[random(sizeof(npcs))] : 1,
                "/d/shenlong/npc/old": 2,
		npcs[random(sizeof(npcs))] : 1,
    ]));
    set("outdoors", "shenlong");
    setup();
   replace_program(ROOM); 
}


