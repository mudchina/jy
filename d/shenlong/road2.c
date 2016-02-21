
inherit ROOM;

void create()
{
	set("short", "山道");
	set("long", @LONG
这是一条狭窄的山道,向着北方一座山峰行去.转过了几个山坡,抬头
遥见峰顶建着几座大竹屋.
LONG
	);
	set("exits", ([
		"north" : __DIR__"damen",
		"south" : __DIR__"wuchang",
	]));
        set("objects", ([
        "/d/city2/npc/dizi": random(4),
        "/d/shenlong/npc/old": random(3),
	]) );
        setup();
	replace_program(ROOM);
}

