//dongnei.c

inherit ROOM;

void create()
{
	set("short", "洞内");
	set("long",
	     "这里是山贼的老窝的所在。旁边有一侧洞，里面隐隐传来女子的哭声。\n"
	);
	set("exits", ([
		"west" : __DIR__"cedong",
		"south" : __DIR__"dongkou",
	]));
	set("objects",([
		__DIR__"npc/shanzei3" : 1,
	]));
	setup();
}
int valid_leave(object me, string dir)
{

	if (  (dir == "west")
	   && objectp(present("shanzei tou", environment(me))) )
	 return notify_fail
		("山贼头操起拳头：你想占我老婆的便宜？快滚！\n");
	return ::valid_leave(me, dir);
}
