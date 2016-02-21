// shulin1.c
// by shilling 97.2

inherit ROOM;

void create()
{
        set("short", "树林");
        set("long", @LONG
这是一片茂密的树林。很多棵几十丈高的大树聚在一块，象一把把琼天
大伞，连日月都被遮蔽得暗然无光。树林中还不时可以听到大自然发出的声响。
LONG
        );

       set("exits", ([
               "north" : __DIR__"shulin1",
               "south" : __DIR__"shulin1",
               "east" : __DIR__"shulin2",
               "west" : __DIR__"xiaodao4",
       ]));
	set("outdoors", "xiaoyao");
	set("objects", ([
//		__DIR__"npc/shuxingh": 1,
//		__DIR__"npc/xue": 1,
]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
