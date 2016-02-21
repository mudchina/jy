//room: mumen.c
inherit ROOM;
void create()
{
  set("short","墓门");
  set("long",
       "这是个一座豪华墓地的墓门。大理石雕花的门梁，青石板的路面，\n"
   "修剪整齐的长青木，显得庄重肃穆。墓门边立着一块青白色石碑(bei)。\n"
      );
  set("exits",([
      "south" : __DIR__"fende",
//      "northeast" : __DIR__"gongzhu",
     ]));
  set("item_desc",([
  "bei" : "   『公主坟』  \n无「金令牌」者禁入！\n",
  ]));
  set("objects",([
    __DIR__"npc/shiwei" : 1,
    ]));
 set("outdoors", "baituo");
 setup();
 replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
       if (  (dir == "northeast")
	   && (!present("jinpai",me))
	   && objectp(present("shi wei", environment(me))) )
	 return notify_fail
		("仕卫把手一拦：你没有「金令牌」，不能进去！\n");
	return ::valid_leave(me, dir);
}






