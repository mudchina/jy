// Room: /d/city2/domitory.c

inherit ROOM;

void create()
{
	set("short", "宿舍");
	set("long", @LONG
这里没有一个人影，可能都去玩MUD了。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"Sino-CO",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
