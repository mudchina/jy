
inherit ROOM;

void create()
{
	set("short", "天地会暗道");
	set("long", @LONG
终于走出了暗道，你长长的舒了一口气。北边是天地会青木堂
的大厅，明亮的灯光让人感到无比温暖。
LONG
	);

	set("exits", ([
		"north" : __DIR__"dating",
		"south" : __DIR__"andao9",
		"west" : __DIR__"andao9",
		"east" : __DIR__"andao9",
	]));

	setup();
	replace_program(ROOM);
}

