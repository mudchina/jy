
inherit ROOM;

void create()
{
	set("short", "康府花园");
	set("long", @LONG
这是一个小花园，虽然花儿不太多，却十分幽雅清洁，显是平日
有人修整打扫。花园北边是一间佛堂。
LONG
	);
        set("outdoors", "city2");

	set("exits", ([
  		"east" : "/d/city2/kang3",
  		"north" : "/d/city2/fotang",
	]));
	setup();
	replace_program(ROOM);
}
