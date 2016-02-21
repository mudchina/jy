//jiudian.c

inherit ROOM;

void create()
{
        set("short", "酒店");
        set("long",
             "这里是一家独具特色的酒店，由于地处『白驼山』下，\n"
         "酒店可以供应风味食品－－蛇肉。许多中原来客都爱来尝尝\n"
         "鲜，所以酒店生意兴隆。酒店还经营打散装酒的业务。\n"
        );
        set("exits", ([
                "south" : __DIR__"xijie",
        ]));
	set("objects",([
		__DIR__"npc/xiaoer" : 1,
	]));
        set("resource/water", 1);
        setup();
        replace_program(ROOM);
}





