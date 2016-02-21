// xiaolu4.c 小径
// by arnzh

inherit ROOM;

void create()
{
	set("short", "小径");
	set("long", @LONG
	你走在一条小径上，两旁是光秃秃的山壁，静悄悄听不到一丝动静。
LONG
	);

	set("exits", ([
		"west" : __DIR__"xiaochidian",
		"east" : __DIR__"shiliang",
	]));
	setup();
	replace_program(ROOM);
}

