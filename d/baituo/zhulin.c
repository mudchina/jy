//zhulin.c
inherit ROOM;
void create()
{
  set("short","竹林");
  set("long",
  "这里是青竹林，常有蛇出没。南边是蒿草丛。北边有一个大岩洞。\n"
      );
  set("exits",([
      "northup" : __DIR__"cave",
      "south" : __DIR__"cao2",
     ]));
 set("objects",([
      __DIR__"npc/qingshe" : random(2),
      __DIR__"npc/snake" : random(3),
      ]));
 setup();
 replace_program(ROOM);
}




