//room: /d/btshan/zhailou.c
inherit ROOM;

void create()
{
  set("short","小宅落");
  set("long",
      "这里是一个树影婆娑的静谧的小宅落，当中放着一口乌黑发亮的大\n"
  "水缸。白驼山上常年积雪，这里的主人架起一条长长的竹渠，把清凉的\n"
  "雪水引到家中的水缸里来。\n"
     );

  set("exits",([
      "west" : __DIR__"liangong",
     ]));

  set("outdoors", "baituo");
  set("resource/water", 1);

 setup();

 replace_program(ROOM);
}





