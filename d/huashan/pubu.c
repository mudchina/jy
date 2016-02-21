// pubu.c

inherit ROOM;

void create()
{
	set("short", "山洪瀑布");
	set("long", @LONG
这里是一处峡谷，每年雨季山洪爆发时就形成了一处蔚为壮观的瀑布。
传说当年神雕侠杨过就是在这里练成绝世的玄铁剑法的。现在人去谷空，
只剩下空寥的山谷和奔腾的洪水(hongshui)。
LONG
);
	set("exits", ([ /* sizeof() == 1 */
		"northwest" : __DIR__"shaluo",
	]));

	set("resource/water", 1);
	set("no_clean_up", 0);

	set("item_desc", ([
		"hongshui" : "这是一股奔腾不息的洪水，水中隐隐有个东西在发光，但你定\n
睛仔细一看，发现那只不过是水面反射的日光罢了\n",
	]));

	setup();
	replace_program(ROOM);
}