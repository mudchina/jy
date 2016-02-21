
inherit ROOM;
int do_out(string arg);

void create()
{
        set("short", "小桥");
        set("long",
        "这是一座破旧的石桥，桥下是护城河缓缓的流水。水看上去很清，\n"+
	"据说曾有人在这里跳河(out)。这里是进皇宫正门的必经之路。\n");
        set("outdoors", "city2");
        set("exits", ([
                "north" : __DIR__"zhengmen",
                "south" : __DIR__"tian_anm",
                "west" : __DIR__"bridge2",
                "east" : __DIR__"bridge3",
        ]));
        setup();
}

void init()
{
	add_action("do_out", "out");
}

int do_out(string arg)
{
	object me;
	int i, ging_cost, qi_cost;

	me = this_player();
	i = (int)me->query_skill("dodge", 1) + random(50);
	ging_cost = 300 / (int)me->query("int");
	qi_cost = 300 / (int)me->query("int");
	if(((int)me->query("jing") < ging_cost) || ((int)me->query("qi") < qi_cost))
		i = 0;

	message_vision("$N翻过石栏，一个纵身，跳了下去。\n", me);
	if ( i < 75)
		{
	        message_vision("一股潜流立刻把$N吞没了。\n", me);
		me->die();
	        }
	else if( i < 100)
		{
	        message_vision("一股潜流立刻把$N吞没了。\n", me);
		me->unconcious();
		switch( random(2) ) {
		case 0:
		me->move(__DIR__"bridge2");
			break;
		case 1:
		me->move(__DIR__"bridge3");
			break;
		message_vision("一股潜流把$N冲回岸边。\n", me);
		}
	        }
	else {
		switch( random(5) ) {
		case 0:
		message_vision("一股潜流把$N冲回岸边。\n", me);
		me->move(__DIR__"bridge2");
			break;
		case 1:
		message_vision("一股潜流把$N冲回岸边。\n", me);
		me->move(__DIR__"bridge3");
			break;
		case 2:
		case 3:
		case 4:
		message_vision("$N在水中昏昏沉沉地胡乱挣扎，突然之间触到了一面硬壁。\n", me);
		message_vision("$N恍若抓住了救命稻草，贴着滑溜溜的硬壁就浮出了水面。\n", me);
		message_vision("$N吐了一口水，抬头一看，原来身在一口井中。\n", me);
         	me->move("/d/huanggon/inwell");
		break;
		}
		if( i > 125) me->improve_skill("dodge", 2*(int)me->query_skill("dodge", 1));
		me->receive_damage("jing", ging_cost );
		me->receive_damage("qi", qi_cost );
	     }
	return 1;
}
