inherit ROOM;
string* npcs = ({
	"/d/shenlong/npc/jinshe",
	"/d/shenlong/npc/qingshe",
	"/d/shenlong/npc/jinshe",
	"/d/shenlong/npc/qingshe",
	"/d/shenlong/npc/fushe",
});
 
void create()
{
        set("short", "灌木林");
        set("long",@LONG
这是一片灌木林。你对这样一个孤岛上竟有这样大一片灌木林(bush)
感到非常吃惊.前面根本没有路,四周的密林中长满了杂草。
LONG);
    set("exits", ([
        "south" : "/d/shenlong/haitan",
    ]));
    set("item_desc", ([
        "bush" : "这片灌木林太深了,要想过去恐怕只有砍出一条路了(kan)。\n",
    ]));
        set("objects", ([
	"/d/shenlong/npc/dushe" : 1+random(2),
	npcs[random(sizeof(npcs))] : 1,
	npcs[random(sizeof(npcs))] : 1,
	npcs[random(sizeof(npcs))] : 1,
	]) );
        set("outdoors", "shenlong");
        setup();
}

void init()
{
    add_action("do_kan", "kan");
}

int do_kan ( string arg )
{
    object ob, weapon;
    string dir;
    if( !arg || arg !="bush" ) 
         return notify_fail("你要砍什么？\n" ) ;
	if (!objectp(weapon = this_player()->query_temp("weapon")))
		return notify_fail("不用武器恐怕不行吧！\n");

	    message_vision(
        "$N抽出兵刃,对着灌木丛一阵乱砍。\n", this_player());

        if(this_player()->query("neili")>100)
	{
        set("exits/north", __DIR__"lin2");
        message_vision(
        "$N累得气喘吁吁,终于砍出一条小路。\n", this_player());
        this_player()->add("neili",-50);
        remove_call_out("close");
        call_out("close", 20, this_object());
	}
        else	
	{
        message_vision(
        "$N累得气喘吁吁,也没砍开一条路来。\n", this_player());
	this_player()->set("neili",0);
	}
return 1;
}

void close(object room)
{
    message("vision","灌木丛渐渐合拢起来,终于又恢复了原状。\n", room);
    room->delete("exits/north");
}
