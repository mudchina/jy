//cave.c
inherit ROOM;

void create()
{
  set("short","岩洞");
  set("long",
        "这里是大岩洞，它是在『白驼山』特殊的地质条件下经\n"
    "过漫长的年代形成的。南边是青竹林。再往北走就进洞了。\n"
      );
  set("exits",([
      "north" : __DIR__"cave1",
      "southdown" : __DIR__"zhulin",
     ]));
 set("objects",([
      __DIR__"npc/mangshe" : 1,
      ]));
 set("outdoors","baituo");
 setup();
}

int valid_leave(object me, string dir)
{
   if (dir =="north" ) {
	if (objectp(present("mang she", environment(me))))
		return notify_fail("蟒蛇挡住你的去路！\n");
		       }
   return ::valid_leave(me, dir);
}




