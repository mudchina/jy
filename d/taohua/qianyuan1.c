
inherit ROOM;

void create()
{
    set("short", "归云庄前院");
    set("long", @LONG
这里是归云庄的前厅，陈设华美，雕梁画栋，穷极巧思，
比诸北方质朴雄大的庄园另是一番景象。由此往南是布置走向
十分怪异的庄内道路，好象一不留神就会迷失在这奇怪的道路
中。西面是一间客房，是好客的主人为来访的客人准备的。
LONG
);
    set("exits", ([
    "north" : __DIR__"zhangqian",
    "south" : __DIR__"gui-in",
    "west" : __DIR__"kefang",
]));

    set("objects", ([
                "/kungfu/class/taohua/luguanying" : 1,
                __DIR__"npc/puren3" : 2,
        ]));

    set("outdoors", "taohua");

    setup();
   
}

int valid_leave(object me, string dir)
{
	mapping myfam;
	myfam = (mapping)me->query("family");

	if ((!myfam || myfam["family_name"] != "桃花岛") && dir == "south" &&
		objectp(present("lu guanying", environment(me))))
	   return notify_fail("陆冠英拦住你说道：后面是本派重地，且歧路甚多，你不是桃花岛弟子，\n此去多有不便，请留步。\n");
		
        return ::valid_leave(me, dir);
}
