#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
        set("short", "庄内道路");
        set("long",@LONG
这是一条曲折蜿蜒的小路。四周种着各种树木，当住了
你的视线。微风轻轻拂过，周围静悄悄的。远处偶尔传来一
声鸟叫。你不禁想到："坏了，我该不是迷路了吧。"
LONG
        );
       set("exits", ([
     "south" : __DIR__"gui0",
     "north" : __DIR__"qianyuan1",
]));
	
    
        set("outdoors","taohua");

        setup();
}
void init()
{       object ob;
        mapping myfam;
	ob = this_player() ;
        if(query("exits/south")) 
        if ((int)ob->query_skill("qimen-wuxing",1) >= 70 )
        {
        delete("exits/south");
        set("exits/south", __DIR__"gui-out");
	return ;
        }
        myfam = (mapping)ob->query("family");
        if(myfam && myfam["family_name"] == "桃花岛")
        {
        delete("exits/south");
        set("exits/south", __DIR__"gui-out");
	return ;
        }         
	delete("exits/south");
        set("exits/south", __DIR__"gui0");
}