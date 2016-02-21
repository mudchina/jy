// Room: /d/shaolin/matou1.c
// Date: Hop 97.06.13

inherit ROOM;

void create()
{
	set("short", "南码头");
	set("long", @LONG
这里是汉水南岸的一个大码头，俗称『小武昌』。一年四季
人来人往，端的是热闹非凡。西面不远就是华山脚下。望东南方
向您可以隐隐约约地看到扬州城的影子。齐的杨树林。
LONG
	);

	set("exits", ([
		"west" : __DIR__"hanshui1",
	]));

	set("objects", ([
		"/d/city/npc/chuanfu1" : 1,
	]));
	set("outdoors", "shaolin");
	setup();
	replace_program(ROOM);
}



