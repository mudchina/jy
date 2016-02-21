// shishi5.c
// by shilling 97.2

inherit ROOM;

void create()
{
        set("short", "地下石室");
        set("long", @LONG
这里是地下石室的最下面一层了，四周是黑乎乎，说不出的阴深恐怖，
你可以闻到强烈的腐烂的东西所发出的气味。看来还是快点离开比较好。
LONG
        );

       set("exits", ([
               "up" : __DIR__"shishi4",
       ]));
	set("objects",([
		__DIR__"npc/xiaoyaozi" : 1,
	]));
	setup();
	replace_program(ROOM);
}
