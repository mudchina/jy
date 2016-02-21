//room: 
inherit ROOM;

void create()
{
  set("short","长廊");
  set("long",
      "这里是非常气派的长廊。两边站着数十个刀斧手,警卫森严,透着腾腾杀气.\n"
 
     );

  set("exits",([
      "north" : __DIR__"dating3",
      "south" : __DIR__"chlang2",
     ]));
  set("objects",([
     __DIR__"npc/jiaotu"   :1,
	]));
 setup();
 replace_program(ROOM);
}

