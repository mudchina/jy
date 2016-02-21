// ROOM : linjxd5.c
inherit ROOM;
void create()
{
  set("short","林间小道");
  set("long",
      "你走在一条阴暗的林间小道上，两旁是阴森森的树林。一阵阵风吹过\n"
      "树梢, 发出沙沙的响声, 令你不寒而栗. 忽然你发现树丛中有两点绿\n"
      "芒一闪即没!!\n" );
  set("exits",([
      "southup" : __DIR__"dating1",
      "north" : __DIR__"linjxd4",     
      "east"  : __DIR__"linjxd3",
      "west"  : __DIR__"linjxd5",]));
  set("objects",([
           __DIR__"npc/wolf" : 4 ,]));    

 setup();
 replace_program(ROOM);
}
