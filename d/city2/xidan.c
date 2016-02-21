inherit ROOM;

void create()
{
	set("short", "西单");
	set("long", @LONG
这里就是西单，人来人往，十分热闹。游人虽然多，但大都只四处晃悠,
着东瞅瞅西看看，也不急着买什么。西边有家杂货铺，去那里买东西的人很多。
不断有人从北边走来，似乎那里也挺热闹。南边是西长安街。
LONG
	);
        set("outdoors", "city2");

	set("exits", ([
		"west" : __DIR__"zahuopu",
		"south" : __DIR__"xichang2",
		"north" : __DIR__"xidan1",
	]));
	set("objects", ([
	    "/d/city2/npc/xiaofan": 1,
	    "/d/huashan/npc/youke": 2,
	]));

	setup();
	replace_program(ROOM);
}


