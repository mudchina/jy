// Room: /city/chaguan.c
// YZC 1995/12/04 
//arnzh 97/1/23

inherit ROOM;

void create()
{
	set("short", "磨针井");
	set("long", @LONG
	你一走进来，就感到一阵凉意沁入心脾，精神为之一爽。地上坐了几个客人，或
高声谈笑，或交头接耳。中间有一口井，来往的人，都在这里休息一下，装一些水。
LONG
	);
	set("resource/water", 1);

	set("exits", ([
		"east" : __DIR__"haohan",
	]));

	setup();
	replace_program(ROOM);
}

