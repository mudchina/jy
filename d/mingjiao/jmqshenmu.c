//JMQJIGUAN.C

inherit ROOM;

void create()
{
	set("short", "巨木旗神木");
	set("long", @LONG

你眼前只见一棵大树，高有百丈，十人也环抱不住。巨树倚绝壁而
生，枝叶繁茂，藤萝环绕，竟然无法一览全貌。树身有一处光滑无
比，是常有人摩挲而成。
LONG
	);

	set("exits", ([
		"east" : __DIR__"jmqshulin6",
	]));

	set("outdoors", "mingjiao");
	setup();
//	replace_program(ROOM);
}

void init()
{
