//room: /d/btshan/liangong.c
inherit ROOM;
void create()
{
  set("short","练功场");
  set("long",
      "这里是白驼山弟子的练功场。东边是一个练功房。北边是个门廊，\n"
  "西边连着一条长廊，雕梁画柱，非常气派。南面可见巍巍大厅。\n"
    );
  set("exits",([
      "east" : __DIR__"fang",
      "north" : __DIR__"menlang",
      "west" : __DIR__"changlang",
      "south" : __DIR__"dating",
     ]));

 set("objects",([
     __DIR__"npc/li" : 1,
     ]));

 set("outdoors", "baituo");
 setup();

 replace_program(ROOM);
}
