#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{ 
        set("short", "庄内道路");
        set("long",@LONG
这是一条曲折蜿蜒的小路。四周种着各种树木，当住了
你的视线。微风轻轻拂过，周围静悄悄的。远处偶尔传来一
声鸟叫。你不禁想到："坏了，我该不是迷路了吧。"
LONG
        );
  
	set("outdoors", "taohua");
	set("exits", ([
		"east" :  __FILE__,
		"west" :  __FILE__,
		"south" : __FILE__,
		"north" : __FILE__,
	]));             
        setup();

}
void init()
{
    this_player()->receive_damage("qi", 15);
    this_player()->receive_wound("qi",  15);
    message_vision(HIG "突然一阵树叶象雨点般疾射$N！\n" NOR, this_player());
}

int valid_leave(object me, string dir)
{
       
        int  total_steps ;
        mapping myfam;
        total_steps = ( 100 - (int)this_player()->query_skill("qimen-wuxing",1) ) / 10 ;
        if ( total_steps <= 0 ) total_steps = 1 ;  
        myfam = (mapping) this_player()->query("family");
        if(myfam && myfam["family_name"] == "桃花岛") total_steps = 1 ; 
	if ( dir == "north")
            me->add_temp("taohua/steps",1);
	if ( dir == "south")
            me->add_temp("taohua/steps",-1);

	if (me->query_temp("taohua/steps") == total_steps)
         {
     	    me->move(__DIR__"tao_in");
            me->delete_temp("taohua/steps");
             return notify_fail("你走了半天，终于走出了桃花迷阵。\n");
         }  

     if (me->query_temp("taohua/steps") == - total_steps )
	    {  
	     me->move(__DIR__"tao_out");
             me->delete_temp("taohua/steps");
             return notify_fail("你走了半天，终于走出了桃花迷阵。\n");
     	}

        return ::valid_leave(me,dir);
}
