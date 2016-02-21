#include <ansi.h>
inherit ROOM;
 
int do_pick(string arg) ;

void create()
{
        set("short", "山洞");
        set("long",@LONG
你正处在一个小山洞中。这里光线很暗，只能隐隐约约看出地上有一堆干草。
干草上好象放着一个石匣(xia)。 你突然闻到一股难闻的气味，显然是有人长期住
在这里却不打扫的缘故。
LONG);   
        set("item_desc", ([
        "xia" : @TEXT
你仔细看了一下石匣，发现里面似乎放着一本书，似乎可以试着拿出来
(pick book)。
TEXT
    ]) );
        set("exits", ([
  "out"  : __DIR__"road5",
]));
        set("objects", ([
        __DIR__"npc/zhou" : 1,
    ]) );    

        setup();
}
void init()
{
            add_action("do_pick","pick");
}
void reset()
{
        ::reset();
        set("get_available" , 1);
}

int do_pick(string arg)
{
       object me,obj;

       me = this_player();
       if( !arg || arg!="book" )
              return notify_fail("你要拿什么?\n");
       if ( present("zhou botong",environment(me)))
        
       {
        message_vision(YEL"周伯通两眼一瞪，哼了一声道：别在我这里偷偷摸摸！"
                       "我周伯通还没死哪！\n" NOR,me) ;
        return 1 ;
       }
       if ( query("get_available") )  {
       obj = new (__DIR__"obj/jiuyin1");
       obj->move(me);
       add("get_available", -1);
       message_vision("$N从石匣中取出一本书。\n",me );
       }
       else
       return notify_fail("你要拿起那本书，却发现你看花了眼，其实那里什么都没有。\n");
       return 1;
}

