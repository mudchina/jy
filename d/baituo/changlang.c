//room: /d/btshan/changlang.c
inherit ROOM;

void create()
{
  set("short","长廊");
  set("long",
      "这里是非常气派的长廊。北边是间休息室。南边有间药房，里面传来\n"
  "一阵器皿碰击的声音。西边是扇拱月形小敞门。东边是练功场。\n"
     );

  set("exits",([
      "west" : __DIR__"ximen",
      "north" : __DIR__"restroom",
      "east" : __DIR__"liangong",
      "south" : __DIR__"yaofang",
     ]));

 setup();
 replace_program(ROOM);
}




