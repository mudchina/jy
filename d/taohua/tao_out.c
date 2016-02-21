#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
        set("short", "桃花迷阵");
        set("long",@LONG
这是一片桃花的海洋。四周一望无际，全是盛开的桃花。微风拂过，
落英缤纷。周围静悄悄的。远处偶尔传来一声鸟叫。往北是一片桃
花林，往南则是一个小亭子。
LONG
        );
       set("exits", ([
     "south" : __DIR__"tingzi",
     "north" : __DIR__"tao0",
]));
    
        set("outdoors","taohua");

        setup();
}
void init()
{       object ob;
        mapping myfam;
        if( interactive( ob = this_player()))
        if(query("exits/north")) 
        if ((int)ob->query_skill("qimen-wuxing",1) >= 100 )
        {
        delete("exits/north");
        set("exits/north", __DIR__"tao_in");
	return ;
        }
        myfam = (mapping)ob->query("family");
        if(myfam && myfam["family_name"] == "桃花岛")
        {
        delete("exits/north");
        set("exits/north", __DIR__"tao_in");
	return ;
        }       
  	delete("exits/north");
        set("exits/north", __DIR__"tao0");
}