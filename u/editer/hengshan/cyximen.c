// /hengshan/cyximen.c
// written by Dewey 

inherit ROOM;

string look_gaoshi();

void create()
{
	set("short", "瓷窑口西门");
	set("long", @LONG
这是北疆重镇瓷窑口的西城门，是通往北方大漠的通道之
一，也是北方胡骑南下常选的入口。由于连年征战，已经显得
有些破败。城门正上方勉勉强强可以认出“西门”两个大字，
城墙上贴着几张通缉告示(gaoshi)。官兵们戒备森严，动不动
就截住行人盘问。一条笔直的青石板大道向东西两边延伸。再
向西行，便是雁门关了。由于已接近边关，行人很少。东边是
城里。
LONG
	);
        set("outdoors", "hengshan");

	set("item_desc", ([
		"gaoshi" : (: look_gaoshi :),
	]));

	set("exits", ([
		"east" : __DIR__"cyxijie",
  		"west" : "/d/xingxiu/xxroad1",
	]));
        set("objects", ([
                __DIR__"npc/wujiang" : 1,
                __DIR__"npc/bing" : 3,
        ]));
	setup();
}

string look_gaoshi()
{
	return FINGER_D->get_killer() + "\n北疆镇守使\n";
}

