//ROM dating

inherit ROOM;

void create()
{
        set("short", "堂厅");
        set("long",
             "这是『日月神教』下第一大堂:风雷堂的大厅，四目望去,满朴素的,\n"
         "堂梁上有一副联子(vote).\n"
        );
	
        set("exits", ([
                "south" : __DIR__"grass2",
                "northdown" : __DIR__"linjxd5",
        ]));
 
        set("objects",([
		               __DIR__"npc/jiaotu" : 2,
        ]));
        set("item_desc", ([
        "vote": "日月神教,文成武德,泽被苍生。\n"
	]) );
        setup();

        
        replace_program(ROOM);
}
