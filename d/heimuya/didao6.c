//room: didao6.c
inherit ROOM;

void create()
{
  set("short","秘道尽头");
  set("long",
	"\n"
        "你忽觉前方一亮，身前真是别有洞天，前方好想有作花园。\n"
        "不知是什么地方。\n"
     );

  set("exits",([
      
      "south" : __DIR__"xiaohuayuan",
      "northdown" : __DIR__"didao4",
     ]));
   
 setup();
 replace_program(ROOM);
}