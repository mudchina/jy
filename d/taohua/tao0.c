#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{ 
        set("short", "桃花迷阵");
        set("long",@LONG
这是一片桃花的海洋。四周一望无际，全是盛开的桃花。微风拂过，
落英缤纷。周围静悄悄的。远处偶尔传来一声鸟叫。你心中不禁慌乱
起来：还是早点出去的好。
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
    message_vision(HIR"突然一阵桃花瓣象雨点般疾射$N！\n"NOR, this_player());
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
