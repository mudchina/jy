//room: yan.c
inherit ROOM;

void create()
{
  set("short","失足岩");
  set("long",@LONG
这是通向『灵鹫宫』的必经之路，山道被一块如鹰喙突出的巨岩截断
，巨岩光可鉴人，只有中间凿出了一条窄窄的石阶通向山道的那一头。你
小心翼翼地试着踏了上去，心想：我能过去吧。
LONG
     );
  set("outdoors", "lingjiu");
  set("exits",([
      "northup" : __DIR__"jian",
      "eastdown" : __DIR__"ya",
     ]));

 setup();
 replace_program(ROOM);
}