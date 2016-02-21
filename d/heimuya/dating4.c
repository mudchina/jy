//ROM dating
inherit ROOM;
void create()
{
        set("short", "天香堂");
        set("long",
             "这是『日月神教』下第四大堂:天香堂的大厅，远远望去郁郁渺渺，好似不\n"
         "食人间烟火。堂梁上有一块匾(bian).\n"
        );
	
        set("exits", ([
                "west" : __DIR__"road1",
                "southup" : __DIR__"tian1",
        ]));
 
                          
        set("item_desc", ([
        "bian": "上面写到：天香堂---日月神教圣姑住地。\n",
        	]) );
        setup();
        
        replace_program(ROOM);
}