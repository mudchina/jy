// Room: /city2/qianzhuang.c

inherit ROOM;

void create()
{
	set("short", "钱庄");
	set("long", @LONG
这是一家老字号的钱庄，已有几百年的历史，在全国各地都有分店。
它发行的银票信誉非常好，通行全国。不管你走到哪里，在任何一个本
庄分店都可以任意存取。墙上挂着一个牌子(paizi)。
LONG
	);

	set("item_desc", ([
		"paizi" : "\n本庄有利息，至少百分之一。\n",
	]));
	set("exits", ([
		"west" : __DIR__"wangfu1",
	]));

	set("objects", ([
		__DIR__"npc/qianlaob" : 1
	]));

	setup();
	replace_program(ROOM);
}

