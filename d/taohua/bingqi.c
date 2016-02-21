inherit ROOM;

void create()
{
    set("short", "兵器室");
	set("long", @LONG
这是一间存放兵器的屋子。刀、枪、剑、戟等各种兵器都按类放在
各自的兵器架上。整个屋子落满灰尘，显然已经好久没人来过。
LONG
	);
	set("exits", ([
        "west" : __DIR__"qianyuan",
	]));
	set("objects", ([
        __DIR__"obj/taojian": 5,
	]) );

	setup();
    replace_program(ROOM) ;
}
