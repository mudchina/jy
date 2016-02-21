// Room: /d/village/temple2.c

inherit ROOM;

void create()
{
        set("short", "小棚子");
	set("long", @LONG
这是一个临时搭起来的小棚子。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"temple1",
]));
        set("objects", ([
                __DIR__"npc/wang": 1
        ]) );
        set("no_clean_up", 0);

        setup();
}
int valid_leave(object me, string dir)
{
	if( me->query_temp("marks/王") ) {
		me->delete_temp("marks/王");
	}
	return 1;
} 
