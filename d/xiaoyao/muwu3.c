// muwu3.c
// by shilling 97.2

inherit ROOM;

void create()
{
        set("short", "工匠屋");
        set("long", @LONG
这里也是一间木屋，屋子中的摆设什么简单，但是却有很多工具，锯子
啦，刨子啦，锤子啦，还有满地的木屑，一看就知道是一个工匠的家。看！
我们的巧匠正忙着呢，不过不知道他又在做什么呢？
LONG
        );

       set("exits", ([
               "north" : __DIR__"mubanlu",
       ]));
 	set("objects", ([
		__DIR__"npc/fengas": 1,
]));
      setup();
	replace_program(ROOM);
}
