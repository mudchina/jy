// Room: /city2/chaguan.c

inherit ROOM;

void create()
{
	set("short", "高升茶馆");
	set("long", @LONG
	你一走进来，就闻到一股茶香沁入心脾，精神为之一爽。
几张八仙桌一字排开，坐满了客人，或高声谈笑，或交头接耳。
你要想打听江湖掌故和谣言，这里是个好所在。
LONG
	);
	set("resource/water", 1);

	set("exits", ([
		"west" : __DIR__"nandaj2",
	]));

	set("objects", ([
		__DIR__"npc/guanfuzi" : 1,
	]));

	setup();
	replace_program(ROOM);
}

