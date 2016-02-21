
inherit ROOM;

void create()
{
	set("short", "海港");
	set("long", @LONG
这里是从京城出海的必经之地，从这里可以出海到神龙岛。
LONG
	);

	set("exits", ([
                "west" : __DIR__"road10",
	]));

	set("objects", ([
                __DIR__"npc/flowerg":2,
		"/d/shenlong/npc/chuanfu" :1,
	]));

	set("outdoors", "city2");
	setup();
	replace_program(ROOM);
}

