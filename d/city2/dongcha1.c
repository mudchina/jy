
inherit ROOM;

void create()
{
	set("short", "东长安街");
	set("long", @LONG
这里是东长安街，宽阔的街道上车水马龙，人来人往。向西走就
是天安门了。由于王府井大街就在北边，许多人都往北去，那里人声
鼎沸，似乎十分热闹。相比之下，东边就显得冷清多了。
LONG
	);
        set("no_sleep_room",1);
        set("outdoors", "city2");

	set("exits", ([
		"east" : __DIR__"dongcha2",
		"west" : __DIR__"tian_anm",
		"north" : __DIR__"wangfu1",
	]));
	setup();
}

