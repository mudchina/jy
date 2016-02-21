// guangchang.c 广场
// by Arnzh

inherit ROOM;

void create()
{
	set("short", "太子岩");
	set("long", @LONG
这是一块广场般大小的大石，上面又平又光，显然不是人力搬来，
也不是人力制成。
LONG
	);
        set("outdoors", "wudang");

	set("exits", ([
		"southdown" : __DIR__"shijie7",
		"north" : __DIR__"tyroadct",
		]));
	set("objects", ([
		CLASS_D("wudang") + "/yu" : 1]));

	setup();
	
}
int valid_leave(object me, string dir)
{
	mapping myfam;
	myfam = (mapping)me->query("family");

	if ((!myfam || myfam["family_name"] != "武当派") && dir == "north" &&
		objectp(present("yu lianzhou", environment(me))))
	   return notify_fail("俞莲舟拦住你说道：后面是本派重地，你不是武当弟子，\n此去多有不便，请留步。\n");
		
        return ::valid_leave(me, dir);
}

