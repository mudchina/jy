// Room: /d/city2/ximenwai.c

inherit ROOM;

void create()
{
	set("short", "西门外");
	set("long", @LONG
这里是北京的西北郊，也就是北邮进士们聚居的海淀区了。
往北是神州结义总部，住南就是北邮最大的网络机房了。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"Sino-CO",
  "east" : __DIR__"ximen",
  "south" : __DIR__"jifang",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
