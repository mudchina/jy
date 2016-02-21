
inherit ROOM;

void create()
{
	set("short", "马棚");
	set("long", @LONG
这里是康亲王府的马棚，其中好马无数。刚一进门，
马儿就冲你“恢恢”直叫。
LONG
	);
	set("exits", ([
		"west" : __DIR__"kang3",
	]));

/* Deleted by Hop, 97.06.13
	set("objects", ([
		"/d/city2/npc/yucongma" : 1,
	]));
*/
	setup();
	replace_program(ROOM);
}
