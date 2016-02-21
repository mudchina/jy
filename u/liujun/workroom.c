// Room: workroom.c
// CLEANSWORD

inherit ROOM;

void create()
{
	set("short", "柳生工作室");
	set("long", @LONG
	这里是柳生的工作室。房间里黑乎乎的，有一只打碎了半边的灯泡挂在
空中荡来荡去。地板年久失修，踩上去吱呀吱呀地响。一把断了一条腿的凳子斜
靠在墙角边。地上堆满了各种各样破破烂烂的大鱼大肉。有些已经放了好久，并
开始发霉腐烂了。
LONG
	);

	set("objects", ([
//		__DIR__"gun" :    1,
//		__DIR__"mianju" : 1
	]));

	set("valid_startroom",1);

	set("exits", ([
		"ts" : "/d/taishan/fengchan",
		"sl" : "/d/shaolin/dxbdian",
		"td" : "/d/city2/dating",
		"bt" : "/d/baituo/dating",
		"wg" : "/d/wudang/sanqingdian",
		"xx" : "/d/xingxiu/xxh2",
		"th" : "/d/taohua/dating",
		"hg" : "/d/city2/tian_anm",
		"gb" : "/d/city/gbxiaowu",
		"wz" : "/d/wizard/wizard_room",
		"ct" : "/d/city/guangchang",
		"qz" : "/d/quanzhou/zhongxin",
"hs" : "/d/huashan/buwei1",
	]));

	setup();
	replace_program(ROOM);
}

