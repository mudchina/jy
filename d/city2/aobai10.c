
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "东厂暗道");
	set("long", @LONG
这是一条暗道，是专为鳌拜从鳌府直接到东厂用的。
南边是一扇木门(door)。
LONG
	);

	set("exits", ([
		"south" :  __DIR__"aobai6",
		"northeast" : __DIR__"aobai11",
	]));
	set("item_desc", ([
		"door" : "这是一扇极厚的木门。\n",
	]));

	create_door("south", "木门", "north", DOOR_CLOSED);
	setup();
	replace_program(ROOM);
}
