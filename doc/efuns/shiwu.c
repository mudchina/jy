// Room
 
inherit ROOM;
 
void create()
{
        set("short", "小石屋");
        set("long", @LONG
你一走进来,只看到里面只有一些简单的家具,一张床。北边的墙上(wall)贴着
一幅美女梳妆图,笔墨细致,画中美女颇为性感,令人一看就想入非非.西北侧好象有
一扇暗门(men),不仔细看还发现不了。
LONG
	);
	set("item_desc", ([
		"men" : "这扇门似乎通向一间密室。\n",
                "wall": "这堵墙看起来有些异常,你想不想推(push)一下呢。\n",
	]));
        set("exits", ([
                "east"  : __DIR__"garden1",
        ]));
 

   	set("objects", ([
		__DIR__"npc/yang" : 1,
	]));

	setup();
}

void init()
{
	add_action("do_unlock", "unlock");
        add_action("do_push", "push");
	if (present("yang lianting", environment(this_player())))
		delete("exits/northwest");
        if (query("exits/north"))
          { 
           message_vision("由于有人闯了进来,墙逢又自动关上了。\n", this_player());	    
           delete("exits/north");
          }
}

int do_unlock(string arg)
{
	object ob;
	if (query("exits/northwest"))
		return notify_fail("这扇门已经是打开的。\n");
	if (!arg || (arg != "men" && arg != "east"))
		return notify_fail("你要打开什么？\n");
	if (!(ob = present("dilao key", this_player())))
		return notify_fail("你没钥匙,也不会撬锁。\n");
	set("exits/northwest", __DIR__"tiemen");
	message_vision("$N用一把钥匙打开了铁门，可是钥匙却断在门里了。\n", this_player());
	destruct(ob);
	return 1;
}

int do_push(string arg)
{	

	if (query("exits/north"))
		return notify_fail("这堵墙已经是开着一道逢了,想走就快走,别磨蹭了。\n");
	if (!arg || (arg != "wall" && arg != "north"))
		return notify_fail("你想干什么？乱推东西多不好呀。\n");
	
	set("exits/north", __DIR__"chlang2");
	message_vision("$N用力把北边墙壁推开一条缝了。\n", this_player());
        call_out(do_close,0);
	return 1;
}

int do_close(void)
{
       if (query("exits/north"))
          { 
           message_vision("时间耽搁太久,墙逢又自动关上了。\n", this_player());	    
           delete("exits/north");
          }
}

int valid_leave(object me, string dir)
{
	if (!wizardp(me) && objectp(present("yang lianting", environment(me))) && 
                     dir == "east" && living(present("yang lianting", environment(me))))
		return notify_fail("杨莲亭挡住了你。\n");
	return ::valid_leave(me, dir);
}



