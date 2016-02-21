// zhenyue.c

inherit ROOM;

void create()
{
	set("short", "镇岳宫");
	set("long", @LONG
这里地势略为平坦，上、下山的游客多在此稍作休息再继续前行。附
近有几间简陋的旅社，欲登东峰观日出者，大都于头晚歇息于此。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
		"westup" : __DIR__"canglong",
		"southwest" : __DIR__"chaoyang",
		"eastup" : __DIR__"yunu",
		"northdown" : __DIR__"husun",
	]));

	set("objects", ([ 
		__DIR__"npc/gao" : 1,
	]));

	set("no_clean_up", 0);
	set("outdoors", "huashan" );

	setup();
}
 
int valid_leave(object me, string dir)
{
	if (dir != "northdown" )
	{
		if(me->query("family/family_name") !="华山派")
		{
			if(me->query("combat_exp") >= 100)
			{
				if(present("gao genming", environment(me)) && living(present("gao genming", environment(me))))
				{
					return notify_fail(
"高根明喝道：后面是本派重地，这位" + RANK_D->query_respect(me) + "请止步。\n");
				}
				else
					return ::valid_leave(me, dir);
			}
			else
				return ::valid_leave(me, dir);
		}
		else
			return ::valid_leave(me, dir);
	}
	else
		return ::valid_leave(me, dir);

}