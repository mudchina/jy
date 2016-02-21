// liangongfang.c 练功房
// by Xiang

inherit ROOM;

void create()
{
set("short","卧室");
	set("long", @LONG
这里是卧室，一个中年人正躺在床上，看来十分消瘦
LONG
	);
	set("exits", ([
		"west" : __DIR__"donglang2",
	]));
	set("objects", ([
 CLASS_D("wudang") + "/yudaiyan" : 1]));

	set("no_fight", 1);
	
	setup();
	replace_program(ROOM);
}
