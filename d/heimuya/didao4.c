//room: didao4.c
inherit ROOM;

void create()
{
  set("short","秘道尽头");
  set("long",
	"\n"
        "你忽觉前方有一亮光，真是别有洞天，前方好想别有地方。\n"
        
     );

  set("exits",([
      "east"   :__DIR__"didao1",
       "west"  :__DIR__"didao3",
      "south" : __DIR__"didao4",
      "southup" : __DIR__"didao6",
     ]));
   
 setup();
 replace_program(ROOM);
}