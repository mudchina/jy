//ROOM neishi.c

inherit ROOM;
void init();
int do_move(string);
void create()
{
        set("short", "内室");
        set("long",
             "这是『欧阳克』的内室，内部摆设很有情趣。屋角摆着一盆名贵\n"
         "兰花，正骄傲地吐露芳蕊。花盆(pen) 下撒落一些浮土，可能是被人\n"
         "搬出去晒太阳时撒下的。\n"
        );
        set("exits", ([
                "east" : __DIR__"huayuan",
        ]));
 
       set("item_desc", ([
	    "pen" : "这是个大花盆，很结实，作工很考究。\n"
	]));
	setup();
}
void init()
{
	add_action("do_move", "move");
}

int do_move(string arg)
{

	object me = this_player();
	object room;

	if ((arg != "pen") || !arg)
	  return notify_fail("你要搬什么？\n");
	if((int)me->query("str") < 20)
	  return notify_fail("你搬不动它！\n");
	if(!( room = find_object(__DIR__"midao")) )
	   room = load_object(__DIR__"midao");
	if(!objectp(room))  return notify_fail("ERROR:not found 'midao.c' \n");
	if (!query("exits/down"))
	  {
	  set("exits/down", __DIR__"midao");
	  message_vision("$N搬动了花盆，只见花盆下面露出一个黑幽幽
	      的洞口。\n",me);
	  room->set("exits/up", __FILE__);
	  message("vision", "外面传来一阵搬动花盆的声音，一束光线射了进来。
	  \n", room);
	  }
	 else
	  {
	  delete("exits/down");
	  message_vision("$N把花盆搬回了原位。洞口被封住了。\n",me);
	  room->delete("exits/up");
	  message("vision", "外面传来一阵搬动花盆的声音，洞口被封住了。\n", room);
	  }
       return 1;
}
