#include <ansi.h>
inherit ROOM;

void create()
{
    set("short", "墓地");
	set("long", @LONG
    这里是桃花岛岛主夫人的墓地。墓地周围种了一些矮矮的花树。
树上的白花星星点点。白花中间是一高大的石碑(bei)，碑后是两扇坚固
的石门。整个墓地干干净净，显然天天有人打扫。
LONG
	);
	set("exits", ([
        "south" : __DIR__"road3",
	]));
	set("item_desc", ([
        "bei": "上面刻着：桃花岛女主冯氏埋香之墓。\n"
	]) );

	setup();
}

void init()
{
	add_action("do_push", "push");
}
void check_trigger()
{
	object room;

	if( (int)query("left_trigger")==3
        &&  (int)query("right_trigger")==3
	&&	!query("exits/down") ) {
        message("vision", "墓门忽然发出轧轧的声音，缓缓向两边移动著，露出一个向下的阶梯。\n",
			this_object() );
        set("exits/down", __DIR__"mudao");
        if( room = find_object(__DIR__"mudao") ) {
			room->set("exits/up", __FILE__);
            message("vision", "墓门忽然发出轧轧的声音，缓缓向两边移动著，露出一个向上的阶梯。\n",
				room );
		}
		delete("left_trigger");
		delete("right_trigger");
		call_out("close_passage", 30);
	}
}

void close_passage()
{
	object room;

	if( !query("exits/down") ) return;
    message("vision", "墓门忽然发出轧轧的声音，缓缓合拢，将向下的通道盖住了。\n",
		this_object() );
    if( room = find_object(__DIR__"mudao") ) {
		room->delete("exits/up");
        message("vision", "墓门忽然发出轧轧的声音，缓缓合拢，将向上的通道盖住了。\n"
                        HIR "你脑海中闪过一个念头：坏了！出不去了！\n" NOR ,
			room );
	}
	delete("exits/down");
}

int do_push(string arg)
{
	string dir;

	if( !arg || arg=="" ) return 0;

	if( arg=="bei" ) {
		write("你试著推动墓碑，发现它可以左右推动....\n");
		return 1;
	}
	if( sscanf(arg, "bei %s", dir)==1 ) {
		if( dir=="right" ) {
			message_vision("$N将墓碑往右推...，忽然轧轧几声墓碑又移回原位。\n", this_player());
			add("right_trigger", 1);
			check_trigger();
			return 1;
		} else if( dir=="left" ) {
			message_vision("$N将墓碑往左推...，忽然轧轧几声墓碑又移回原位。\n", this_player());
			add("left_trigger", 1);
			check_trigger();
			return 1;
		} else {
			write("你要将墓碑推向那个方向？\n");
			return 1;
		}
	}
}
void reset()
{
	::reset();
	delete("left_trigger");
	delete("right_trigger");
}
