inherit ROOM;
#include <ansi.h>

void create()
{	
set("short", "风的工作室");
set("long", @LONG	
这里是风的工作室。温馨的音乐在房间里飘荡，一台奔腾不弱正在嗡嗡地工作。
屋里有一大片空地，据说是为安放音响而预留的。书架(shelf) 上全是小说，其中
一本是风儿自己的作品。墙上有一副对联(duilian).
LONG	);	
set("valid_startroom",1);
set("no_steal", "1");
	set("exits", ([
		"sh" : "/d/shenlong/wuchang",
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
		"lj" : "/d/lingjiu/damen",
		"li" : "/d/city2/tingyu",
	]));

set("item_desc", ([
		"shelf" : HIC "\n酒盈杯，书满架，名利不将心挂。\n" NOR,
		"duilian" : HIG "\n给我一个温柔的陷阱\n" NOR + HIC "还你一腔燃烧的爱情\n" NOR,
	]));
setup();
}

