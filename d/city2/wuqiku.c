
inherit ROOM;

void create()
{
	set("short", "武器库");
	set("long", @LONG
这里是武器库，架上摆满了各种武器,任由武士门挑选。
LONG
	);
	set("exits", ([
		"east" : __DIR__"kang2",
	]));
	set("objects", ([
		"/d/village/obj/zhujian" : 2,
		"/d/city/obj/zhubang" : 2,
		"/d/shaolin/obj/changbian" : 1,
		"/d/city/obj/duanjian" : 1,
		"/d/city/obj/gangdao" : 1,
		"/d/city2/obj/fuchen" : 1,
	]));
	
	setup();
	replace_program(ROOM);
}
