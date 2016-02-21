//RJQYUAN.C

inherit ROOM;

void create()
{
	set("short", "大院");
	set("long", @LONG
你走进了锐金旗的大院，却发现这里人影稀疏，虽听见叮
叮咚咚的打铁声，却见不到打铁铺，那声音似乎是从深远的地
下传来的。向西走，就要进入门楼了。院子左首可能是练武场，
隐约传来打斗声；右首是一座大厅，象是锐金旗的议会场所。
LONG
	);

	set("exits", ([
		"west" : __DIR__"rjqmenlou1",
		"north" : __DIR__"rjqdating",
		"south" : __DIR__"rjqlwch",
		"east": __DIR__"rjqmen",
	]));
/*
        set("objects",(["/kungfu/class/mingjiao/lengqian":1,
        		"/kungfu/class/mingjiao/shuobude":1,
		        "/kungfu/class/mingjiao/zhangzhong":1,
		        "/kungfu/class/mingjiao/pengyingyu":1,
		        "/kungfu/class/mingjiao/zhoudian":1,
		        "/kungfu/class/mingjiao/yinyewang":1,
			]));
*/
	set("outdoors", "mingjiao");
	setup();
	replace_program(ROOM);
}