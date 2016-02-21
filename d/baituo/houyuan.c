//room: huayuan.c
inherit ROOM;

void create()
{
  set("short","后院");
  set("long",
       "这是僻静的后院，住着『欧阳克』的老奶妈『张妈』。\n"
   "由于年岁已高，她已经不干活了，在这里静养。\n"
      );
  set("exits",([
      "southeast" : __DIR__"zhuyuan",
     ]));
  set("outdoors", "baituo");
  set("objects",([
    __DIR__"npc/zhangma" : 1,
    ]));
 setup();
 replace_program(ROOM);
}






