//room: didao1.c
inherit ROOM;

void create()
{
  set("short","秘道");
  set("long",
	"这是一条异常幽静的走廊,四周漆黑一团,你好象什么都看不见似的\n"
        "走在里面,你不觉想到这似乎在每个角落都藏着无限杀机,太恐怖了,\n"
        "四周毫无声息，好象掉下一根针都可能听到。\n"
     );

  set("exits",([
      "east" : __DIR__"didao2",
      "west" : __DIR__"didao1",
      
      "south" : __DIR__"didao5",
     ]));

 setup();
 replace_program(ROOM);
}