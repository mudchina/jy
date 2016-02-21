//room: didao5.c
inherit ROOM;

void create()
{
  set("short","秘道");
  set("long",
	"\n"
        "走在里面,你不觉想到这似乎在每个角落都藏着无限杀机,你感到近了近\n"
        "了,越来越近了。\n"
     );

  set("exits",([
      "east" : __DIR__"didao3",
      "west" : __DIR__"didao3",
      "north" : __DIR__"didao2",
      "south" : __DIR__"didao1",
     ]));
   set("objects",([
		__DIR__"npc/snake" : 4,
       	]));
 setup();
 replace_program(ROOM);
}