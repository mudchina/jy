// Room: /d/shaolin/zhulin3.c
// Date: YZC 96/01/19
//Update by Arnzh /97/1/21

inherit ROOM;

int do_snap(string arg);
void create()
{
	set("short", "竹林小道");
	set("long", @LONG
这是一条卵石铺成的小道，曲曲折折地通向前方。两边是密
密的竹林(bamboo)。这里人迹罕至，惟闻足底叩击路面，有僧敲木鱼声；
微风吹拂竹叶，又如簌簌禅唱。令人尘心为之一涤，真是绝佳
的禅修所在。
LONG
	);

	set("exits", ([
		"west" : __DIR__"hsyuan3",
		"south" : __DIR__"zhulin2",
	]));
        set ("item_desc", ([
		"bamboo" : 
"这是一丛绿色的竹子，说不定可以折(snap)下来当武器用。\n"
	])  ) ;

	set("outdoors", "shaolin");
	setup();
//	replace_program(ROOM);
}

void init()
{
	add_action("do_snap","snap");
}

int do_snap(string arg)
{	object zhuzhi;
	 if( !arg || arg=="" ) {
message_vision("你想折什么？\n", this_player());         
return 1;
}
        if( arg=="bamboo"||arg=="zhuzhi" ) {
		message_vision(
"$N从竹丛中折下一根竹枝。\n"
                , this_player());
		zhuzhi = new(__DIR__"obj/zhuzhi");         
	        zhuzhi->move(this_player());
 
		return 1;
		}

	return 0;
}



