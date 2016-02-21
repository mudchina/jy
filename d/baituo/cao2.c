//room:cao2.c

inherit ROOM;

void create()
{
  set("short","草丛");
  set("long",
      "这里是乱草丛。北边是青竹林。其余三面都是齐腰高的蒿草，\n"
  "常有蛇出没。\n"
     );
  set("exits",([
      "west" : __FILE__,
      "north" :__DIR__"zhulin",
      "east" : __DIR__"cao1",
      "south" : __DIR__"cao1",
     ]));
 set("objects",([
      __DIR__"npc/qingshe" : random(2),
      __DIR__"npc/jinshe" : random(2),
      __DIR__"npc/snake" : random(2),
      ]));
 set("outdoors","baituo");
 setup();
 replace_program(ROOM);
}




