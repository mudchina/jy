// shijie2.c 柏林
// by Xiang
// by arnzh 97/1/23

inherit ROOM;

void create()
{
	set("short", "柏林");
	set("long", @LONG
	你走在一条坚实的石阶上，周围是郁郁苍苍的柏林，与人来人往的遇真
宫相比这里清静了许多，偶尔有进香客走过。一边是峭壁，一边是悬崖，抬头隐
约可见笼罩在云雾中的天柱峰，听着流水淙淙，令人心旷神怡。
LONG
	);
        set("outdoors", "wudang");

	set("exits", ([
		"southdown" : __DIR__"shijie22",
		"northup" : __DIR__"shijie31",
	]));
        set("objects", ([
                CLASS_D("wudang") + "/famu" : 1,
                __DIR__"npc/monkey" : 1]));

       	setup();
	replace_program(ROOM);
}

