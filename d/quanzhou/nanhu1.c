// Room: /d/quanzhou/nanhu1.c
// Date: May 21, 96   Jay

inherit ROOM;

void init();
int do_out();

void create()
{
	set("short", "嘉兴南湖");
	set("long", @LONG
这里是烟波浩淼的南湖。湖上几只画舫在游荡，船上的游客和
青楼女子在嘻笑。湖水很深，没有船是渡不过去的。但不知是谁在
湖底钉了一些木桩。桩顶潜在水面之下一两寸的地方。即使是不懂
轻功的人走上去也像是水上漂的样子。似乎水下有了些什么. 近来
有人潜(out)下湖去搜寻什么, 总也不知道结果如何. 只是有人传
闻在湖底找到了什么宝贝.
LONG
	);

	set("exits", ([
		"south" : __DIR__"yanyu",
                "northwest" : __DIR__ "nanhu",
	]));

	set("outdoors", "quanzhou");
	setup();
}

void init()
{
	add_action("do_out","out");
}

int do_out()
{
	object me = this_player();
	message_vision("$N纵身跃起，空中一个浪里翻花，头下脚上，咚的一声潜入湖中不见了.\n", me);
	me->move("/d/npc/m_weapon/tan/tan1");
	return 1;
}

