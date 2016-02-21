//datiepu.c

inherit ROOM;

void create()
{
        set("short", "打铁铺");
        set("long",
             "这里是一家打铁铺，铁匠忙着打制铁制兵器，卖给江湖侠客。\n"
        );
        set("exits", ([
                "north" : __DIR__"dongjie",
        ]));
	set("objects",([
		__DIR__"npc/smith" : 1,
	]));
        setup();
        replace_program(ROOM);
}





