// xiaoyuan.c 后山小院
// by Xiang

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "金殿");
	set("long", @LONG
	这是后山的一座小院，布置简简单单，除了一床、一桌、一椅、一蒲团，
再也没有别的什物。比较引人注目的是墙上挂着一把剑。这里就是武当开山祖师
张三丰的练功所在。因为这里是张三丰常住的地方，人们把这里叫做金殿。
LONG
	);

	set("exits", ([
		"south" : __DIR__"xiaolu2",
	]));
	set("objects", ([
		CLASS_D("wudang") + "/zhang" : 1 ]));
	create_door("south", "竹门", "north", DOOR_CLOSED);
	set("valid_startroom", 1);
	setup();
	replace_program(ROOM);
}

