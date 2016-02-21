// shanlu.c

inherit ROOM;

void create()
{
	set("short", "玉女蜂山路");
	set("long", @LONG
这里是玉女蜂后山的一条山路。路边长满了翠竹，每当微风拂过，竹
叶便沙沙作响，显得分外的幽静。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
		"north" : __DIR__"yunu",
		"southup" : __DIR__"xiaojing",
	]));
	set("no_clean_up", 0);
	set("outdoors", "huashan" );

	setup();
	replace_program(ROOM);
}