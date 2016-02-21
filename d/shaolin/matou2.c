// Room: /d/shaolin/matou2.c
// Date: Hop 97.06.13

inherit ROOM;

void create()
{
	set("short", "北码头");
	set("long", @LONG
这里是汉水北岸的一个码头，和『小武昌』隔河相望。虽然
没有南码头那么热闹，但也是三天一小集、五天一大集的。往北
走不多远就是闻名天下的「少林寺」。偏向东北方向则是去往京
城的官道。
LONG
	);

	set("exits", ([
		"west" : __DIR__"hanshui2",
	]));

	set("objects", ([
		"/d/city/npc/chuanfu2" : 1,
	]));

	set("outdoors", "shaolin");
	setup();
	replace_program(ROOM);
}



