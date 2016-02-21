// gate.c

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", HIW "鬼门关" NOR);
	set("long", 
		"这里就是著名的阴间入口「鬼门关」，在你面前矗立著一座高大的\n"
		"黑色城楼，许\多亡魂正哭哭啼啼地列队前进，因为一进鬼门关就无法再\n"
		"回阳间了。\n");

	set("exits", ([
		"north" : "/d/death/gateway",
	]) );

	set("valid_startroom", 1);

	set("objects", ([
		__DIR__"npc/wgargoyle":1,
		__DIR__"npc/newgargoyle":1
	]) );
	setup();
}

void init()
{
	object ob;

	ob = this_player();
	ob->set("startroom","/d/death/gate");
}