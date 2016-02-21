// shijie3.c 好汉坡
// by Xiang
// by arnzh 97/1/23

inherit ROOM;

void create()
{
	set("short", "好汉坡");
	set("long", @LONG
	你走在一条坚实的石阶上，不时地有进香客从你的身边走过。一边是峭
壁，一边是悬崖，抬头隐约可见笼罩在云雾中的天柱峰，听着流水淙淙，令人心
旷神怡。北边是一座牌坊，西边是一口井，过往的路人有些坐在井边休息有些在
向酒袋里装水。
LONG
	);
        set("outdoors", "wudang");

	set("exits", ([
	        "west": __DIR__"shuijing",       
		"southdown" : __DIR__"shijie32",
		"northup" : __DIR__"shijie42",
	]));
	setup();
	replace_program(ROOM);
}

