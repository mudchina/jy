//nongshe.c
inherit ROOM;

void create()
{
        set("short", "农舍");
        set("long",
             "这里是一间小农舍，家具很新。看来主人比较富裕。\n"
        );
        set("exits", ([
                "west" : __DIR__"guangchang",
        ]));
        set("objects",([
		__DIR__"npc/woman" : 1,
        ]));
        setup();
        replace_program(ROOM);
}
