#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{
    set("short", "桃花山庄正门");
    set("long",@LONG
这里是桃花山庄的正门。门前疏落有致地种了几株桃花树，更显得此地主人
对桃花的偏爱。门口站着两个小童看守大门。看来由于地处边远，人烟罕至，人
们对山庄的防卫不是特别谨慎。门前有一对白雕(diao)。
LONG);

	set("exits", ([
        "south" : __DIR__"qianyuan",
        "north" : __DIR__"tingzi",
	"east"  : __DIR__"road1" ,       
	]));
        set("item_desc", ([
        "diao" : "一对白雕正展翅欲飞。如果是桃花岛的弟子，\n"
                  "骑上(ride)就可以飞到中原。\n",
    ]));
        set("objects", ([
                __DIR__"npc/shitong" : 2,
        ]));
    set("outdoors", "taohua");
    setup();
    
}

void init()
{
    add_action("do_ride", "ride");
}
int do_ride ( )
{
    mapping myfam;
    object ob = this_player () ;
    myfam = (mapping)ob->query("family");
    if(!myfam || myfam["family_name"] != "桃花岛")
    {
      message_vision("$N一跃身跨上了白雕。只见白雕仰天长唳，突然猛然一颠......\n"
                     HIR "结果$N摔了个鼻青脸肿！\n" NOR
                     "看来白雕对$N并不感兴趣，它只认识桃花岛的弟子。\n" , ob ) ;
      ob -> receive_damage ("qi",50) ;
      ob -> receive_wound  ("qi",50) ;
      return 1;
    }
    if( (int)query("sb_ride") ) 
         return notify_fail("现在白雕正忙着,请过一会在乘坐!\n" ) ;
    add("sb_ride",1) ;
    message_vision("$N一跃身跨上了白雕。只见白雕仰天长唳，突然展翅高飞。\n\n"
                   "但看一雕一人身形渐渐缩小，终至不见。\n" , ob );
    ob->move("/d/taohua/lantian") ;
    tell_object(ob, CYN  "\n你不断地飞呀飞，万水千山身下飘过 ......\n\n" NOR ) ;
    call_out("taohua", 3 , ob );
    add("sb_ride",-1) ;
    return 1 ;
}
void taohua( object ob )
{
  tell_object(ob, "你终于飞到了中原，白雕落了下来。\n\n"  ) ;
  ob -> move ("/d/taohua/dayuan" ) ; 
}
