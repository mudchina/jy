#include <room.h>
inherit ROOM;

void create()
{
	set("short", "先贤祠－玩家部");
	set("long", @LONG
这里是纪念杰出玩家的地方。供奉在这里的无论是侠客还是魔头，
都曾经叱诧一时。抬头一张横匾，上书七个闪闪发光的金字：
天下谁人不识君
注：排名不分先后。按字母顺序。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "up" : __DIR__"xxci2",
  "down" : __DIR__"shuyuan",
  "south" : __DIR__"xxci3",
]));
	set("no_fight",1);
	set("no_clean_up", 0);

	set("objects", ([ /* sizeof() == 1 */
		"/d/npc/arnzh" : 1,
		"/d/npc/swh" : 1,
		"/d/npc/oscar" : 1,
		"/d/npc/peter" : 1,
	       "/d/npc/rew":1,
		"/d/npc/basic" : 1,
		"/d/npc/goose" : 1,
		"/d/npc/sasa" : 1,
		"/d/npc/rose" : 1,
		"/d/npc/icom" : 1,
	]));

   create_door("south","木门","north",DOOR_CLOSED); 	
	setup();
	replace_program(ROOM);
}
