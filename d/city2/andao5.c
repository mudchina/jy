
inherit ROOM;

void create()
{
	set("short", "天地会暗道");
	set("long", @LONG
地道里一片漆黑，呼呼的风声从四面八方传来。你什么也看不
见，只能在地道里瞎摸乱撞。西面似乎隐隐约约有人说话，但只一
会儿又没声了。你使劲地摇了摇头，很怀疑这到底是不是幻觉。好
象你已经迷路了。
LONG
	);

	set("exits", ([
		"south" : __FILE__,
		"north" : __DIR__"andao4",
		"east" : __FILE__,
		"west" : __DIR__"andao7",
	]));

	setup();
	replace_program(ROOM);
}

