// Room: /d/emei/jietuopo.c 峨嵋派 解脱坡


inherit ROOM;




void create()
{
	set("short", "解脱坡");
	set("long", @LONG
这里是瀑布上方一道窄窄的山梁，浑然天成。石梁上面人工
凿出一格格阶梯。边上钉了几棵木桩，绕上粗长的麻绳作为扶手。
瀑布在脚下奔腾而过，在不远的山脚下汇成一个深潭。
LONG
	);

	set("exits", ([
		"east" : __DIR__"milin2",
		"west" : __DIR__"guanyitang",
	]));

	set("outdoors", "shaolin");
	setup();
	replace_program(ROOM);
}



