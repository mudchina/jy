
inherit ROOM;

void create()
{
	set("short", "虚空梦境");
	set("long", @LONG
这里就是五彩缤纷的虚空梦境。在这里，你可以得到你想要的一切。。。
一切。。。一切。。。。。。。。。
LONG
	);

	set("exits", ([
		"south" : __DIR__"tingyu",
		"east" : __DIR__"jifang",
	]));
//	set("objects", ([ "/u/wind/wind.c" : 1 ]));

	setup();
}

