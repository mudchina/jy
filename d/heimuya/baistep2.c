//room: 
inherit ROOM;
void create()
{
  set("short","长廊");
  set("long",
      "这里是白虎堂的长廊。两边一片狼籍,看样子刚被洗劫一场,遍地横尸，残不忍赌。\n"
 
     );
  set("exits",([
     "north" : __DIR__"baistep1",
      "south" : __DIR__"baihutang",
     ]));
  setup();
 replace_program(ROOM);
}
