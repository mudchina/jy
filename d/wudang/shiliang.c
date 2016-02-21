// Room: shiliang.c 石梁
// arnzh 97/1/24
inherit ROOM;

void create()
{
	set("short", "石梁");
	set("long", @LONG
	    这是一条光秃秃的石梁,上面似乎连人都站不了,但是有好几只猴子，
在那里打闹嬉戏，时常骚扰游人。
LONG
	);

	set("exits", ([
		"west" : __DIR__"xiaolu4",
	]));

	set("objects", ([
		__DIR__"npc/monkey" : 3,
	]));

	setup();
	replace_program(ROOM);
}

