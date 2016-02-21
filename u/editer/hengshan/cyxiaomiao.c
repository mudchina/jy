inherit ROOM;

void create()
{
	set("short", "小庙");
	set("long", @LONG
这是一间十分老旧的城隍庙，庙堂很小，在你面前的
神桌上供奉著一尊红脸的城隍，庙虽老旧，但是神案四周
已被香火薰成乌黑的颜色，看来这里的居民常到这里来祈
求平安。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"north" : __DIR__"cyxijie",
		"east" : __DIR__"cynanjie",
	]));
	set("no_fight", "1");

	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/keeper" : 1,
	]));

	setup();
	replace_program(ROOM);
}
