// liangong.c
// shilling 97.2

inherit ROOM;

void create()
{
	set("short", "石屋");
	set("long", @LONG
这是树林中的一间石屋，屋内显得什么清净和简朴，房间中并没有什么
特别的摆设在这里，不会受到任何东西的骚扰，是个修炼内功的好地方。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
                "south" : __DIR__"xiaodao4",
]));
	setup();
	replace_program(ROOM);
}
