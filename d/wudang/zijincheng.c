// zijincheng.c紫金城
// by arnzh 97.1.24 

inherit ROOM;

void create()
{
	set("short", "紫金城");
	set("long", @LONG
	在你的面前是一座道观，上面写着“紫金城”三个朱红色的大字，红砖
碧瓦，院墙上是一人般大小的“无量寿佛”四个大字。院中房间延绵百余间，身
穿不同服色的道士确不断进进出出，诵经的声音隐隐传来。再往北是一条竹林小道。
LONG
	);
        set("outdoors", "wudang");

	set("exits", ([
		"south" : __DIR__"liantai",
 		"north" : __DIR__"xiaolu1",  
	]));
//	set("objects", ([
//		CLASS_D("wudang") + "/zhike" : 1]));
	setup();
	replace_program(ROOM);
}

