// Room: /d/npc/xianxianci.c

inherit ROOM;

void create()
{
	set("short", "先贤祠－巫师部");
	set("long", @LONG
这里是纪念历代巫师的地方。每位在这里被供奉的巫师都为本MUD
做出过杰出的、不可磨灭的贡献。我们永远都会爱戴、怀念他们。
抬头一张横匾，上书七个闪闪发光的金字：俯首甘为孺子牛
注：排名不分先后。按字母顺序。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "down" : __DIR__"xxci1",
]));
	set("no_fight",1);
	set("no_clean_up", 0);
	set("objects", ([ /* sizeof() == 1 */
		"/d/npc/five" : 1,
		"/d/npc/fcxy" : 1,
		"/d/npc/jungu" : 1,
		"/d/npc/doll" : 1,
		"/d/npc/wind" : 1,
	]));

	setup();
	replace_program(ROOM);
}
