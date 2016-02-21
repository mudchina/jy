
inherit ROOM;
int do_out(string arg);

void create()
{
        set("short", "小桥");
        set("long",
        "这是一座破旧的石桥，桥下是护城河缓缓的流水。水看上去很清，\n"+
	"这里是进皇宫后门的必经之路。\n");
        set("outdoors", "city2");
        set("exits", ([
                "north" : __DIR__"di_anmen",
        ]));
        setup();
	replace_program(ROOM);
}


