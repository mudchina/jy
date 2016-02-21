
inherit ROOM;

void create()
{
	set("short", "客店");
	set("long", @LONG
这是一家价钱低廉的客栈，生意非常兴隆。据说全国各地
都有这样的分店，而且所有的客栈都归一个人所有。不过他从
来不露面，谁也不知道他究竟是怎样一个人。
LONG
	);

	set("no_fight", 1);
	set("valid_startroom", 1);

	set("objects", ([
		"/d/city/npc/xiaoer" : 1,
	]));

	set("exits", ([
		"west" : __DIR__"nandaj1",
	]));
	setup();
	"/clone/board/kedian2_b"->foo();
}

