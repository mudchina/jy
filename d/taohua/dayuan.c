#include <ansi.h>

inherit ROOM;

void create()
{
    set("short", "大院");
    set("long", @LONG
这是一个破旧的大院。院子倒挺宽阔，可以容下百十人。
院子右首有一对白雕(diao)。原来这里是桃花岛为方便
弟子回岛而特意建起的。
LONG
    );

    set("item_desc", ([
        "diao" : "一对白雕正展翅欲飞。如果是桃花岛的弟子，\n"
                  "骑上(ride)就可以飞回桃花岛。\n",
    ]));
    set("exits", ([
		"north" : "/d/city/datiepu",
    ]));
    set("objects", ([
        __DIR__"npc/lu" : 1,
   ]) );
    set("outdoors", "shaolin");
    setup();
}


void init()
{
    add_action("do_ride", "ride");
}
int do_ride ( )
{
    mapping myfam;
    object room;
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
    if( !(room = find_object(__DIR__"lantian")) )
            room = load_object(__DIR__"lantian");
    if( room = find_object(__DIR__"lantian") ) 
    if((int)room->query_temp("tian_trigger")==1 ) 
     {
       message_vision("现在白雕正忙着,请过一会再乘坐!\n" , ob) ;
       return 1 ;
     }
    room->set_temp("tian_trigger", 1);
    message_vision("$N一跃身跨上了白雕。只见白雕仰天长唳，突然展翅高飞。\n\n"
                   "但看一雕一人身形渐渐缩小，终至不见。\n" , ob );
    ob->move(room) ;
    tell_object(ob, CYN  "\n你不断地飞呀飞，万水千山身下飘过 ......\n\n" NOR ) ;
    call_out("taohua", 3 , ob );
    room->delete_temp("tian_trigger");
    return 1 ;
}
void taohua( object ob )
{
  tell_object(ob, "你终于飞到了桃花山庄，白雕落了下来。\n\n"  ) ;
  ob -> move (__DIR__"damen") ; 
}
void reset()
{
    object room;

    ::reset();
    if( room = find_object(__DIR__"lantian") )
        room->delete("tian_trigger"); 
}