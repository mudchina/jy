// Room: /d/xingxiu/xxh1.c
// Jay 3/18/96

inherit ROOM;

void create()
{
        set("short", "星宿海");
        set("long", @LONG
这里是星宿海边。说是海，其实是片湖泊和沼泽，地形十分险恶。
东面石壁上一道裂缝通到一个山洞。南面有一条捷径可通往白驼山。
LONG
        );
        set("exits", ([
             "north" : __DIR__"xxh2",
             "southup" : __DIR__"tianroad2",
             "south" : "/d/baituo/houmen" ,
             "westup" : __DIR__"tianroad3",
]));
        set("objects", ([
                "/kungfu/class/xingxiu/zhaixing" : 1,
                __DIR__"npc/gushou"  : 1,
                __DIR__"npc/haoshou" : 1,
                __DIR__"npc/boshou" : 1,
        ]) );

        set("no_clean_up", 0);
        set("outdoors", "xingxiuhai");

        setup();
}

int valid_leave(object me, string dir)
{
	if (dir != "north" && dir != "westup")
		{ return ::valid_leave(me, dir); }
      else  {
        if (objectp(present("zhaixing zi", environment(me)))&& living(present("zhaixing zi", environment(me))))
	{
	    if ((me->query("shen") > 100))
        	return notify_fail(
"摘星子喝道：这位" + RANK_D->query_respect(me) + "休走！\n");
	}
	return ::valid_leave(me, dir);
}

}
