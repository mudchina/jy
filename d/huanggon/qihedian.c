inherit ROOM;

void create()
{
	set("short", "清和殿");
	set("long", @LONG
这里是清和殿。西边是一条长长的走廊，通往后院。走廊上有几间卧房，
那里是宫中太监的住所。
LONG
	);

        set("outdoors", "huanggon");
	set("exits", ([
		"south" : "/d/city2/zhengmen",
		"west" : "/d/huanggon/zoulang1",
	]));
	set("objects", ([
		"/d/huanggon/npc/shiwei" :1,
		"/d/huanggon/npc/taijian" :1,
	]));

	setup();
}

int valid_leave(object me, string dir)
{
me->delete("huanggong\\canenter");
return ::valid_leave(me, dir);
}