// siguoya.c
// By Hop, 97.04.30

inherit ROOM;

void create()
{
	set("short", "思过崖");
	set("long", @LONG
这里便是华山派弟子受罚思过的地方。位于玉女峰顶，正好有一小快
平地，一面是深不可测的山谷、一面是陡峭的悬壁(bi)，零零落落的有几
快山石。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"northdown" : __DIR__"xiaojing",
	]));
	set("outdoors", "huashan" );

	set("item_desc", ([
		"bi" : "你看着看着忽然发现有一处石壁上的青苔比别处少得多。不禁想....\n",
	]) );

	setup();
}

void init()
{
	add_action("do_break", "break");
}

int do_break(string arg)
{
    int n;
	object me = this_player();

    if( !arg || arg!="bi" )
	{
        write("不要随便打碎别人的东西！\n");
        return 1;
    }

    message_vision(
    "$N走到石壁前，拔出腰间所悬长剑，运劲向石壁刺了过去。\n", this_player());

	if ((me->query("family/family_name") == "华山派") && (me->query("family/master_id") == "feng qingyang"))
	{
		me->move("/d/huashan/houshan");
		return 1;
	}

    n = (int)me->query("neili");
    if (n >= 2000)
	{
        message_vision(
        "$N只听一声轰响，石壁被捅穿了，原来里面有一个大洞。！\n", this_player());
        set("exits/south", __DIR__"md-rukou");
        this_player()->set("neili",n-2000);
        remove_call_out("close");
        call_out("close", 5, this_object());
    }
    else
	{
		message_vision(
		"结果只听一声闷哼，$N被石壁的反弹力震得眼前一黑....\n", this_player());
		this_player()->set("neili",0);
		this_player()->unconcious();
    }

    return 1;
}

void close(object room)
{
    message("vision","崖上忽然掉下来一块巨石，将洞口封了个严严实实。\n", room);
    room->delete("exits/south");
}
