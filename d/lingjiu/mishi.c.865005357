
inherit ROOM;

void create()
{
	set("short", "密室");
	set("long", @LONG
这是个阴暗的密室，墙上的油灯发出昏暗的黄光。
LONG
	);

	set("exits", ([
		"south" : __DIR__"midao13",
		"north" : __DIR__"midao14",
		"east" : __DIR__"midao14",
		"up" : __DIR__"huayuan",
		]));
//	set("objects",([
//		__DIR__"obj/zhemeitu1" : 1,
//		__DIR__"obj/zhemeitu2" : 1,
//		__DIR__"obj/liuyangzhangfa1" : 1,
//		__DIR__"obj/liuyangzhangfa2" : 1,
//		__DIR__"obj/qijianpu" : 1,
//       	]));
	setup();
}

int valid_leave(object me, string dir)
{

	if (  (dir == "up") && (present("tu", this_player())||present("pu",this_player())) ) 
	
	return notify_fail
		("你怎敢带走镇派之宝呢！\n");
	
	return ::valid_leave(me, dir);
}
