
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "兵营");
	set("long", @LONG
这里是兵营，密密麻麻到处都是官兵，有的在武将的指挥下列队操练，
有的独自在练功，有的坐着、躺着正在休息。还有些太监在四处走动。
LONG
	);

	set("exits", ([
		"north" : __DIR__"xichangdamen",
	]));

	set("objects", ([
		"/d/huanggon/npc/taijian" : 1,
		"/d/city/npc/wujiang" : 1,
		"/d/city/npc/bing" : 2,
	]));
	setup();
	replace_program(ROOM);
}

