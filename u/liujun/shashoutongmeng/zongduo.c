inherit ROOM;

void create()
{
        set("short", "杀手同盟总舵");
        set("long",@LONG
这是杀手同盟总舵。
LONG
        );
        set("outdoors", "shaolin");
        set("exits", ([
//                "northwest" : __DIR__"guangchang",
                "west" : "/d/village/hsroad1",
        ]));
//        set("objects",([
//                __DIR__"npc/zuolengchan" : 1,
//        ]));
        setup();
        replace_program(ROOM);
}
