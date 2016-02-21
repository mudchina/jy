
inherit ROOM;

void create()
{
	set("short", "长安戏院");
	set("long", @LONG
这里就是著名的长安戏院，几个戏子在台上(stage)唱戏。
台下黑压压的一片都是人。唱到妙处，观众们禁不住大声喝采。
东边是后台。
LONG
	);
	set("exits", ([
		"south" : __DIR__"xichang1",
                "up" : __DIR__"stage",
                "east" : __DIR__"houtai",
	]));
        set("item_desc", ([
		"stage" : "\n看到戏台，你突然有种想登台表演的冲动。\n" ,
	]));
        set("objects", ([
        "/d/city2/npc/guanzho":  5,
	]));
	setup();
}

int valid_leave(object me, string dir)
{
    int i;
    object man,*ob;
    if(dir=="up")
    {
 	if(!me->query_temp("hastryup"))
        {
        me->set_temp("hastryup",1);
       	if((int)me->query("meili")>=20)
		{
	message_vision(  
	"只听哗啦啦一片掌声，观众们一起鼓掌。有人大声说道：\n"
	"净一净，请看这位" + RANK_D->query_respect(me)+ "表演。\n",this_player());
        return ::valid_leave(me, dir);
	        }
        	else
		{
	message_vision(
	"\n突然观众一拥而上，对$N大叫道：凭你也敢上台闹事？老子宰了你这" +
                        RANK_D->query_rude(me) + "！\n",this_player());
        if(!present("jia", environment(this_player())))
	{
	man=new(__DIR__"npc/guanzho1");
	man->move(this_object());
	}
	if(!present("yi", environment(this_player())))
	{
	man=new(__DIR__"npc/guanzho2");
	man->move(this_object());
	}
	if(!present("bing", environment(this_player())))
	{
	man=new(__DIR__"npc/guanzho3");
	man->move(this_object());
	}
	if(!present("ding", environment(this_player())))
	{
	man=new(__DIR__"npc/guanzho4");
	man->move(this_object());
	}
	if(!present("wu", environment(this_player())))
	{
	man=new(__DIR__"npc/guanzho5");
	man->move(this_object());
	}
	ob = all_inventory(this_object());
	for(i=0; i<sizeof(ob); i++) {
		if( !userp(ob[i]) ) { 
			ob[i]->set_leader(me);
			ob[i]->kill_ob(me);
			me->fight_ob(ob[i]);
		}
		}
        return notify_fail("观众们拼死也不让你上台。\n");
        }
}
message_vision("$N拼死冲上台去。\n",this_player());
return ::valid_leave(me, dir);
} 
return ::valid_leave(me, dir);
}