inherit ROOM;
 
void create()
{
        set("short", "空地");
        set("long",@LONG
这是一片空地,四周都是乱石,杂草丛生。北边是一间小屋.南面是
深深的灌木林.东面有一条工整的大道,西面是一片草坪.
LONG);
        set("exits", ([
        "west" : __DIR__"caoping",
        "east" : __DIR__"road",
        "north" : __DIR__"xiaowu",
        "south" : __DIR__"lin2",
	]) );
        set("objects", ([
        "/d/city2/npc/dizi": random(3),
	]) );
        set("outdoors", "shenlong");
        setup();
	replace_program(ROOM);
}


