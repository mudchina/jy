// shijie2.c 十八盘
// by Xiang
// by arnzh 97/1/23

inherit ROOM;

void create()
{
	set("short", "十八盘");
	set("long", @LONG
	你走在一条坚实的石阶上，周围是郁郁苍苍的柏林，与人来人往的遇真
宫相比这里清静了许多，偶尔有进香客走过。一边是峭壁，一边是悬崖，抬头隐
约可见笼罩在云雾中的天柱峰，听着流水淙淙，令人心旷神怡。
LONG
	);
        set("outdoors", "wudang");

	set("exits", ([
		"southdown" : __DIR__"shijie5",
		"northup" : __DIR__"zixiaogong",
	]));
       	setup();
	replace_program(ROOM);
}

