#include <room.h>
inherit ROOM;

void create()
{
	set("short", "先贤祠－女玩家部");
	set("long", @LONG
这里是一间黑黝黝的小屋，使你想起了那个不知关过多少江湖女杰的破仓库。
抬头一张横匾(bian)，上面有几个黑乎乎的大字：巾帼不让须眉。
注：排名不分先后。按字母顺序。
LONG
	);


set("exits", ([ 
  "north" : __DIR__"xxci1",
]));
set("item_desc", ([ 
  "bian" : "匾上有几个大字，再一看，旁边另注了一行小字：\n女人的名字是弱者。\n",
]));
	set("no_fight",1);
	set("no_clean_up", 0);

	set("objects", ([ 
		"/d/npc/wwl" : 1,
	]));

   create_door("north","木门","south",DOOR_CLOSED); 	
	setup();
	replace_program(ROOM);
}
