// Room: /d/shaolin/qfdian.c
// Date: YZC 96/01/19

#include <room.h>
inherit ROOM;




void create()
{
	set("short", "千佛殿");
	set("long", @LONG
这是千佛殿。大殿入口是朱红格扇，七宝玲珑。内里供奉的西
天诸佛，计有八菩萨，四金刚，五百阿罗，三千揭谛，十一大曜，
十八伽蓝，以及众优婆塞，优婆夷等。直看得你眼花缭乱。边上
有道小木门。
LONG
	);

	set("exits", ([
		"southdown" : __DIR__"guangchang5",
		"north" : __DIR__"bamboo1",		
	]));

	set("objects",([
		CLASS_D("shaolin") + "/qing-guan" : 1,
	]));

	create_door("north","木门","south",DOOR_CLOSED);

	setup();
	
}

void init()
{
	add_action("do_push", "tui");
}

void close_passage()
{
	object room;

	if( !query("exits/down") ) return;
	message("vision", "墙壁忽然发出轧轧的声音，缓缓地移回原处，"
		"将向下的洞口盖住了。\n", this_object() );
	if( room = find_object(__DIR__"qfdian") ) {
		room->delete("exits/up");
		message("vision", "头顶上的石板忽然发出轧轧的声音，"
			"墙上的石块又缓缓地收了回去，阶梯消失了。\n", room );
	}
	delete("exits/down");
}

int do_push(string arg)
{
	object me, room;
	mapping my_fam;
	
	me = this_object();
	my_fam  = me->query("family");

	if( !arg || arg =="") return 0;
	if( (arg != "stone") || ( this_player()->query("family/generation") != 2 ))
	{
		message_vision("$N要推什么？\n",this_player());
		return 1;
	}
	else 
	{
		message("vision", "墙壁忽然发出轧轧的声音，向一侧缓缓移开，"
			"向下露出一个黑洞洞的入口。\n", this_player());
		set("exits/down", __DIR__"damodong"); 
		remove_call_out("close_passage");
		call_out("close_passage", 1);
	}
	return 1;
}
