// buwei1.c

inherit ROOM;

int valid_leave();

void create()
{
        set("short", "客厅");
	set("long", @LONG
这是华山掌门岳不群的居所「有所不为轩」，此处是前厅，厅上挂着
「正气堂」三字匾额。厅中很宽敞，却没什么摆设，靠墙放着两把交椅，
这里是岳不群议事、授徒的地方，后面是寝室。
LONG
        );

	set("valid_startroom", 1);

        set("exits", ([ /* sizeof() == 2 */
		"south" : __DIR__"square",
		"north" : __DIR__"buwei2",
	]));

        set("objects", ([ 
		CLASS_D("huashan") + "/linghu" : 1,
        ]));

        set("no_clean_up", 0);

        setup();
	"/clone/board/huashan_b"->foo();
}

int valid_leave(object me, string dir)
{
	if (dir != "north")
		return ::valid_leave(me, dir);

        if (dir == "north" && objectp(present("ling huchong", environment(me))))
	{
		if ((me->query("family/family_name") == "华山派"))
        	{
			if ((me->query("gender") == "男性"))
				write("令狐冲侧身让开，说道：师弟辛苦了，师傅正等着你了。\n");
			else if ((me->query("gender") == "女性"))
				write("令狐冲侧身让开，说道：师妹辛苦了，师傅正等着你了。\n");
			return 1;
        	}
		if( present("yingxiong ling", me) && ((int)me->query("shen") > 5000))
		{
			write("令狐冲躬身说道：原来是贵客驾到，请进请进！\n");
			return 1;
		}
                else 
			return notify_fail(
"令狐冲喝道：后面是家师寝室，这位" + RANK_D->query_respect(me) + "请止步。\n");
	}
	return ::valid_leave(me, dir);
}