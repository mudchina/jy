
inherit ROOM;

void create()
{
	set("short", "天地会暗道");
	set("long", @LONG
一走进黑漆漆的地道，阵阵阴风从南边吹来，你感到有些
冷。两边都是土墙，隐约可以听到上面脚底落地的声音。
LONG
	);

	set("exits", ([
		"north" : __DIR__"andao1",
		"south" : __DIR__"andao5",
	]));

	setup();
	replace_program(ROOM);
}

