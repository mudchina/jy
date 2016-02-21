inherit ROOM;

void create()
{
	set("short", "书房");
	set("long", @LONG
    这是一间干干净净的书房。当中一个大檀木桌，桌上放着不少书籍。
靠墙的地方还有一个书架，架上满满的全是各种封装的书。其中不少书看上去
古意盎然，显然年代已久。
LONG
	);
    set("exits", ([
    "west" : __DIR__"dating",
]));
     set("objects", ([
        __DIR__"npc/yapu" : 2,
        __DIR__"obj/xiang" : 1,
    ]) );    

	setup();
	replace_program(ROOM);
}
