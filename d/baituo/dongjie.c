//dongjie

inherit ROOM;

void create()
{
	set("short", "东街");
	set("long",
	     "这里是小镇的东街。南边有个打铁铺，里面传来丁丁当当\n"
	 "的声音。东南方是荒凉的戈壁，东北方有条小路可上山。\n"
	);
	set("outdoors", "baituo");
	set("exits", ([
		"west" : __DIR__"xijie",
		"south" : __DIR__"datiepu",
		"southeast" : __DIR__"gebi",
		"northeast" : __DIR__"xiaolu1",
	]));
	set("objects",([
		__DIR__"npc/playboy" : 1,
	]));
	setup();
	replace_program(ROOM);
}
