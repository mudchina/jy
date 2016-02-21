// Room: /city/dongcha2.c
 

inherit ROOM;

void create()
{
	set("short", "东长安街");
	set("long", @LONG
你走在东长安街上，踩着坚实的青石板地面。东边是东城门，
可以听到守城官兵的吆喝声。南边是打铁铺，叮叮当当的声音老远
就能听到。北边是京城最有名的“怡红院”，达官显贵、宫廷侍卫
都爱去。西边比这里更热闹，从那儿往北可以去王府井。
LONG
	);
        set("outdoors", "city2");

	set("exits", ([
		"east" : __DIR__"dongmen",
		"south" : __DIR__"datiepu",
		"west" : __DIR__"dongcha1",
		"north" : __DIR__"yihongyu",
	]));
	set("objects", ([
	"/d/city/npc/liumangtou" : 1,
	"/d/city/npc/liumang" : 2,
	]));

	setup();
	replace_program(ROOM);
}

