//TOHSQ3.C

inherit ROOM;

void create()
{
	set("short", "山路");
	set("long", @LONG
这里快接近谷低了，但北面瀑布挡住了去路。瀑布如一匹银练
奔流而下，倾泻在一深潭之中，水声轰鸣，帘雾直上重霄。两旁山
石高耸，陡壁断崖，象是人工劈就而成。深潭前的青石被磨得锃亮，
好象总有人在这里来往。
LONG
	);

	set("exits", ([
//		"west" : __DIR__"rjqmen",
		"southeast" :__DIR__"tohsq2",
//		"northwest" :__DIR__"tohsq3",
	]));

	set("outdoors", "mingjiao");
	setup();
//	replace_program(ROOM);
}


void init()
{
        add_action("do_jump","jump");
}


int do_jump(string arg)
{
        object me;
        me=this_player();
        if(!arg)
        {
                message_vision("$N一闭眼，向潭中跳了下去，只觉冰冷刺骨，赶紧运气相抗。",me);
                me->move("/d/mingjiao/hsqtan1");
                return notify_fail("\n");
        }
}


	

