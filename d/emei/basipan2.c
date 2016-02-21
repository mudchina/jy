// Room: /d/emei/basipan2.c 峨嵋派 八十四盘2

inherit ROOM;

void create()
{
	set("short", "八十四盘");
	set("long", @LONG
这里是瀑布上方一道窄窄的山梁，浑然天成。石梁上面人工
凿出一格格阶梯。边上钉了几棵木桩，绕上粗长的麻绳作为扶手。
瀑布在脚下奔腾而过，在不远的山脚下汇成一个深潭。
LONG
	);

	set("exits", ([
		"northeast" : __DIR__"basipan1",
		"southeast" : __DIR__"lengshanlin1",
		"southup" : __DIR__"basipan3",
	]));

//	set("outdoors", "shaolin");
	setup();
	replace_program(ROOM);
}