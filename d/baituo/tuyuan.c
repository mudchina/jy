//room: tuyuan.c
inherit ROOM;

void create()
{
  set("short","兔苑");
  set("long",
       "这是个好玩的兔苑，几只大白兔静静地蹲在绿草地上吃草。\n"
   "往北是后门，西南方是竹园。\n"
      );
  set("exits",([
      "north" : __DIR__"houmen",
      "southwest" : __DIR__"zhuyuan",
     ]));
  set("outdoors", "baituo");
  set("objects",([
    __DIR__"npc/baitu" : 2,
    ]));
 setup();
 replace_program(ROOM);
}




