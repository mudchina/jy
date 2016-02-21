// Room: /d/mingjiao/xuantianshi.c
// Date: XXL 97/05/9

inherit ROOM;

void create()
{
	set("short", "悬天石");
	set("long", @LONG
从石上远眺，只见云海苍茫处，险绝万峦生，昆仑一脉，逶迤
千里，真一派大好江山。关于悬天石，还有许多传说。相传明教第
三十代教主〖风舞柳影〗阿娜（Doll)为解明教之难，舍身于此,明
教一代绝学“”从此失传。许多后来之人于此凭吊，莫不泣泪，但
更多的是从此石跳(tiao)下，想寻找“”秘籍，却从没有人能安然
而归。
LONG
	);

	set("exits", ([
		"down" : __DIR__"shanlu3",
	]));

	set("outdoors", "mingjiao");
	setup();
	replace_program(ROOM);
}



