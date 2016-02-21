//HSQTAN6.C

inherit ROOM;

void create()
{
	set("short", "深潭");
	set("long", @LONG
这里的水只有齐腰深，但站在水中，仍感觉寒意从
脚下漫起，经久不散。
LONG
	);

	set("exits", ([
		"up" : __DIR__"hsq1",
		"west" : __DIR__"hsqtan5",
	]));

//	set("outdoors", "mingjiao");
	setup();
	replace_program(ROOM);
}






	

