//ROM dating
inherit ROOM;
void create()
{
        set("short", "白虎堂");
        set("long",
             "这是『日月神教』下第二大堂:白虎堂的大厅，四目望去,一地鲜血,\n"
         "堂梁上有一块匾(bian).堂上北壁上有几个血字(zi).\n"
        );
	
        set("exits", ([
                "west" : __DIR__"baistep1",
                "east" : __DIR__"linjxd6",
        ]));
 
                          
        set("item_desc", ([
        "bian": "上面写到：长河落日，白虎在天；
          千秋万载，一统江湖 。\n",
        "zi" : "上面写到：华山弟子，势杀邪教。\n" 
	]) );
        setup();
        
        replace_program(ROOM);
}