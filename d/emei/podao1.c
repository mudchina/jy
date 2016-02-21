// Room: /d/emei/podao1.c 峨嵋派 坡道1

inherit ROOM;

void create()
{
	set("short", "坡道");
	set("long", @LONG
这里是瀑布上方一道窄窄的山梁，浑然天成。石梁上面人工
凿出一格格阶梯。边上钉了几棵木桩，绕上粗长的麻绳作为扶手。
瀑布在脚下奔腾而过，在不远的山脚下汇成一个深潭。
LONG
	);

	set("exits", ([
		"east" : __DIR__"lianhuashi",
		"westup" : __DIR__"podao2",
	]));

	set("outdoors", "shaolin");
	setup();
	replace_program(ROOM);
}



