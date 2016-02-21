//chufang1.c
inherit ROOM;
void create()
{
  set("short","厨房");
  set("long",
  "这是风雷堂的厨房，一位美丽侍女满脸堆笑。\n"
  "整个房间菜香,胭脂香迷蔓。墙上贴着一张醒\n"
  "目的启事(note)。\n"
  );
  set("exits",([
  "east" : __DIR__"grass2",
  ]));
  set("item_desc",([
  "note" : "人是铁,饭是钢,一顿不吃饿得慌。\n",
  ]));

  set("objects",([
  __DIR__"npc/shinu" : 1,
  __DIR__"obj/tea" : random(6),
  __DIR__"obj/sherou"  : random(4),
  ]));
  setup();
  }
int valid_leave(object me, string dir)
{
	if (( present("tea", me)||present("she rou", me))
	&&objectp(present("shi nu", environment(me))) )
	return notify_fail
	("侍女美目一挑,你还是在这儿吃完吧\n");
	return ::valid_leave(me, dir);
}





