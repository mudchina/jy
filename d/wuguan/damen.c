// damen.c
//written by dewey 

inherit ROOM; 

void create() 
{
	set("short", "武馆大门"); 
	set("long",@LONG
这是一间气势宏大的武馆，大门洞开着，门口蹲踞着两个
威猛的石狮子，武馆里传来一阵阵练武的声音。据说这个武馆
已经有上百年的历史了。任何人只要付钱，就能在这儿学到一
些粗浅的工夫。
LONG);
       
        set("exits",([
        "east" : "/home/editor/workroom",
        ])); 
	
        setup(); 
	
} 
