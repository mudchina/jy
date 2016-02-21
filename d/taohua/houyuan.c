#include <room.h>
inherit ROOM;

void create()
{
    set("short", "后院");
	set("long", @LONG
这是山庄的后院。院中摆着几个机关人，是给桃花岛弟子练功用的。
院后是桃花岛的唯一一座山峰：弹指峰。整个桃花山庄倚山而立，险势天
成。
LONG
	);
    set("exits", ([
     "north" :__DIR__"dating",
     "west" :__DIR__"xiaowu",
     "east" :__DIR__"siguoshi" ,
]));

    set("objects", ([
        __DIR__"npc/jiguan" : 2,
    ]) );
	setup();
	replace_program(ROOM);
}
