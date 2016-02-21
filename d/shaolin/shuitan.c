// Room: /d/shaolin/hantan3.c

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "碧水神潭");
	set("long", @LONG
只见潭水清澈碧绿尤如一块碧玉一般，一挂巨大的瀑布
如白龙出霄般横越山间直泄而下，汇入这深潭之中，在水面
上击起了一层薄薄的青雾，凝聚不散，如仙境一般。但潭水
深不见底，也不知道这深潭之下是如何一番景致。潭边有一
尊佛像，不知是何人何时所刻，但确栩栩如生颇具灵性，也
许是长年在这神潭之侧受天地之灵气的缘故吧。
LONG
	);
	set("exits", ([
		"west" : __DIR__"shijie5",
	]));

	set("outdoors", "shaolin");
	setup();
}

void init()
{
	add_action("do_ketou", "ketou");
//	this_player()->set_temp("shui", 0);
	add_action("do_daoshui", "daoshui");
}

int do_ketou(string arg)
{
	object tong;

	message_vision("$N虔诚地跪下来，给佛像磕了一个头。\n", this_player());
	
	if ((int)this_player()->query_skill("dodge", 1) >= 30 
	&& (int)this_player()->query_skill("dodge", 1) <= 100 )
	{
		tong = new("d/shaolin/obj/tong");
		tong->move("/d/shaolin/shuitan");
		this_player()->set_temp("shui", 0);
		message_vision("冥冥之中，你似乎觉得佛祖在点拨你在轻功方面的疑难。\n", this_player());
		return 1;
	}

	return notify_fail("结果什么也没发生。\n");
}

int do_daoshui(string arg)
{
	object me;
	int i, jing_cost, qi_cost;
	mapping mine;

	me = this_player();
	i = (int)me->query_skill("dodge", 0) + random(200);
	jing_cost = 600 / (int)me->query("int");
	qi_cost = 500 / (int)me->query("int");
	if(((int)me->query("jing") < jing_cost) || ((int)me->query("qi") < qi_cost))
		i = 0;

	if ( !me->query_temp("shui") || (me->query_temp("shui") == 0 ))
		return notify_fail("你桶里没有水，不知道你想要倒什么。\n");
	
	if ( me->query_temp("shui") == 1 )
	{
		me->improve_skill("dodge", 2*(int)me->query_skill("dodge", 1));
		me->receive_damage("jing", jing_cost );
		me->receive_damage("qi", qi_cost );
		me->delete_temp("shui");
		return notify_fail("你把桶里的水倒进了神潭里。\n");
	}
}
