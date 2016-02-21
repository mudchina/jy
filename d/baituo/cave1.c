//cave1.c
inherit ROOM;

void create()
{
  set("short","岩洞内");
  set("long",
        "这里是岩洞内部，洞顶上悬挂着洁白的钟乳石。\n"
      );
  set("exits",([
      "south" : __DIR__"cave",
     ]));
// set("objects",([
//      ]));
 setup();
 replace_program(ROOM);
}




