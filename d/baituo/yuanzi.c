// yuanzi.c

inherit ROOM;

void init();
string look_gate();
int do_open(string);
int do_lock(string);

void create()
{
        set("short", "院子");
        set("long",
             "这是一个大院子，打扫得一尘不染。四周装点着青青翠竹，错落\n"
         "有致。西边是武器库。东边有一间储藏室，房门(door)关闭着。北边\n"
         "是『白驼山庄』的大厅。南边就是大门了。\n"
        );

        set("exits", ([
                "northup" : __DIR__"dating",
                "west" : __DIR__"wuqiku",
                "south" : __DIR__"damen",
        ]));

        set("outdoors", "baituo");

        set("item_desc", ([
            "door" : (: look_gate :),
        ]));

        set_temp("lock",1);

        setup();
//        replace_program(ROOM);
}

void init()
{
	add_action("do_open", "open");
	add_action("do_lock", "lock");

}

string look_gate()
{
	if (query_temp("lock") == 0)
		return "门上的铁锁被打开了。\n";
	return "这扇门被铁锁牢牢锁住。\n";
}

int do_open(string arg)
{
	object me=this_player(), room;

	if(!arg || arg!="door")
		return notify_fail("你要开什么？\n");

	if( query_temp("lock") == 1 && !present("key", me) )
		return notify_fail("钥匙都没有，怎么开门？\n");

	if(!( room = find_object(__DIR__"storeroom")) )
		room = load_object(__DIR__"storeroom");

	if(!objectp(room))
		return notify_fail("ERROR:not found 'storeroom.c' \n");

	if(query_temp("lock") == 1 && present("key", me))
	{
		set_temp("lock", 0);
		message_vision("$N把钥匙插进锁孔，只听见‘卡嗒’一声，锁开了。\n", me);
		message("vision", "外面传来一阵开锁的声音，只听见‘卡嗒’一声，锁开了。
  \n",room);
}
   message_vision("$N轻轻推开门，走了进去，随手把门掩了起来。\n",me);
   message("vision", "有人走了进来，随手把门掩上了。\n",room);
   me->move(room);
   return 1;
}

int do_lock(string arg)
{
	object me=this_player();
	object room;

	if(!arg ||  arg!="door")
		return notify_fail("你要锁什么？\n");
	if( !present("key",me))
		return notify_fail("钥匙都没有，怎么锁门？\n");
	if(!( room = find_object(__DIR__"storeroom")) )
		room = load_object(__DIR__"storeroom");
	if(!objectp(room))
		return notify_fail("ERROR:not found 'storeroom.c' \n");

	if(query_temp("lock") == 1)
		return notify_fail("门已经锁好了。\n");
	set_temp("lock",1);
	message_vision("$N把钥匙插进锁孔，只听见‘卡嗒’一声，锁被锁上。\n",me);
	message("vision", "外面传来一阵锁铁锁的声音，只听见‘卡嗒’一声，锁被锁上了。
  \n",room);

	return 1;
}
