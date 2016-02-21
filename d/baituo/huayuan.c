//room: huayuan.c
inherit ROOM;

void create()
{
  set("short","花园");
  set("long",
       "这是个美丽的大花园，园子里面种着鲜艳的红玫瑰。\n"
   "白衣少女常来这里嬉戏。沿着弯弯曲曲的花径，可以通到\n"
   "山庄的许多地方。东边是厨房。西边是白驼山少主『欧阳\n"
   "克』的内室，门虚掩着，不知主人在不在。\n"
      );
  set("exits",([
      "west" : __DIR__"neishi",
      "north" : __DIR__"zhuyuan",
      "east" : __DIR__"chufang",
      "south" : __DIR__"menlang",
     ]));
  set("outdoors", "baituo");
  set("objects",([
    __DIR__"npc/whitelady" : 2,
    ]));
 setup();
 replace_program(ROOM);
}






