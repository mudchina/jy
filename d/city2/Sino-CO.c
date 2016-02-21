// Room: /d/city2/Sino-CO.c

inherit ROOM;

void create()
{
	set("short", "明光村");
	set("long", @LONG
这里有一班泥虫，整天在泥潭打滚，鉴于大家都是单打独斗，某天一虫
疾呼，我们都在一起玩，何不金兰结义?共同为MUD的繁荣做点贡献。于是神
州结义就诞生了!
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"lab",
  "south" : __DIR__"ximenwai",
  "east" : __DIR__"domitory",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
