//ROM

inherit ROOM;

void create()
{
        set("short", "山谷");
        set("long",
             "这里是一处山谷，上面种植着草坪。南下是『日月神教』的\n"
             "青龙堂。东南方是一座小桥，传说是通向云南的必经之路\n"
        
        );
        set("outdoors", "heimuya");
        set("exits", ([
                "east" : __DIR__"linjxd1",
              "southup" : __DIR__"dating3",
                
        ]));
        set("objects",([
		__DIR__"npc/kid" : 2,
	]));
        setup();
        replace_program(ROOM);
}
