//room: 
inherit ROOM;

void create()
{
  set("short","池塘");
  set("long",@LONG
这是一个小池塘,池塘里有数对鸳鸯悠游其间，池边还有四只白鹤在觅食。
LONG 
     );

  set("exits",([
      "north"      : __DIR__"baihutang",
      "west" : __DIR__"shenggu",
	   "east" :__DIR__"chufang2",
     ]));

 setup();
 replace_program(ROOM);
}




