// pubu.c 
// shilling 97.2

inherit ROOM;

#include <ansi.h>
void create()
{
	set("short", "瀑布");
	set("long", @LONG
你猛听得水声响亮，轰轰隆隆，便如潮水大至一般，抬头一看，只见一
条大瀑布，犹如银河倒悬，从高崖上直泻下来。下面是万丈深渊，云雾弥漫，
望不到尽头。。。。
LONG	);

	set("exits", ([ /* sizeof() == 2 */
		"west" : "/d/huashan/sheshen",
	]));
	set("outdoors", "xiaoyao" );
	set("no_clean_up", 0);
	setup();
}
 
void init()
{
	add_action("do_jump","jump");
}

int do_jump(string arg)
{
	object ob;
	int new_gin;
	ob = this_player();
	new_gin = random( ob->query("max_gin")*3 );
	if ( new_gin > ob->query("gin") ) new_gin = ob->query("gin") + 1;
        if( !arg || arg=="" ) return 0;
        if( arg != "down" )
		return notify_fail("你想要跳崖自杀？这么想不开啊？\n");
	tell_object(ob, HIR"你不加思索，纵身一跃，跳下了悬崖。。。。\n"NOR);
	message("vision", NOR"只见" + ob->query("name") + "万念俱灰，纵身跳入了悬崖之中。。。。\n"NOR, environment(ob), ob);
	if((random((int)ob->query("kar")) < 5 ) && ((int)ob->query_skill("dodge")<30) )
	{
		ob->die();
		return 1;
	}
	ob->add("gin", 0 - new_gin);
	ob->move(__DIR__"yanfeng");
	return 1;
}

