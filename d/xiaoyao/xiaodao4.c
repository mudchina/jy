// xiaodao4.c
// shilling 97.2

inherit ROOM;

void create()
{
	set("short", "林间小道");
	set("long", @LONG
这是一条长长的林间小道，从东边一直通到西边，一眼望去，看不到路
的尽头。两旁百花争艳。令人留连忘返。
LONG
	);
	set("exits", ([
		"east" : __DIR__"shulin1",
		"west" : __DIR__"qingcaop",
		"north" : __DIR__"liangong",
		"south" : __DIR__"mubanlu",
]));
 	set("objects", ([
		__DIR__"npc/mengmianr": 2,
]));
	set("outdoors", "xiaoyao");
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
