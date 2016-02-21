inherit ROOM;

void create()
{
	set("short", "朝阳路");
	set("long", @LONG
这是一条东西走向的大道。西边人声鼎沸，十分热闹。东边就是朝阳门。
LONG
	);
        set("outdoors", "city2");

	set("exits", ([
		"west" : __DIR__"wangfu2",
		"east" : __DIR__"chaoyang",
	]));

	setup();
	replace_program(ROOM);
}


