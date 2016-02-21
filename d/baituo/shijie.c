//shijie.c
inherit ROOM;

void create()
{
  set("short","石阶");
  set("long","这里是青石板铺成的石阶。\n");
  set("exits",([
      "east" : __DIR__"caoping",
	"northup" : __DIR__"damen",
      "southdown" : __DIR__"guangchang" ,
     ]));
  set("outdoors", "baituo");
  setup();
 replace_program(ROOM);
}





