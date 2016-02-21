//ROOM: xiaohuayuan.c

inherit ROOM;

void create()
{
	set("short", "小花园");
        set("long",
	     "从昏暗的地道中出来, 你发现自己竟是置身于一个极精致的小花\n"
	     "园中, 红梅绿竹, 青松翠柏, 布置得颇具匠心, 往东去是一间精雅\n"
              "小舍.\n"
            );
        set("exits", ([
		"north" : __DIR__"didao6",
                "enter" :__DIR__"xiaoshe",   
           ]));
        setup();
        replace_program(ROOM);
}