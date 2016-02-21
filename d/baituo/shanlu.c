//shanlu.c
inherit ROOM;

void create()
{
  set("short","山路");
  set("long","这里是山上的泥路。\n");
  set("exits",([
      "northwest" : __DIR__"shanlu1",
      "southeast" : __DIR__"guangchang",
     ]));
  set("outdoors", "baituo");
  setup();
 replace_program(ROOM);
}





