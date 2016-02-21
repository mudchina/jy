// Room: /city/zuixianlou.c
// xiao chi dian in wudang
// YZC 1995/12/04 
// arnzh 97/1/24
inherit ROOM;

void create()
{
	set("short", "小吃店");
	set("long", @LONG
	这个小吃店布置简易，简直就是一个四面透风的凉棚嘛，也能叫小吃店。
顾客多是匆匆的行人，买点包子、鸡腿、米酒就赶路去了。
LONG
	);

	set("exits", ([
		"southdown":__DIR__"xuanwumen",
		"east" : __DIR__"xiaolu4",
		"northup" : __DIR__"shijie5",
	]));

	set("objects", ([
		__DIR__"npc/xiaoer3" : 1,
	]));

	setup();
	replace_program(ROOM);
}

