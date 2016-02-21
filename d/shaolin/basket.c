// Room: /d/heimuya/basket.c

inherit ROOM;




void create()
{
	set("short", "掉蓝");
	set("long", @LONG
这是一个掉蓝,是用来上下黑木崖的工具.蓝上看来只能乘作一人.
LONG
	);


	set("outdoors", "heimuya");
	setup();
	replace_program(ROOM);
}



