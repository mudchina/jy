// Room: /city2/zhengmen.c

#include <room.h>

inherit ROOM;

string look_gaoshi();

void create()
{
	set("short", "皇宫正门");
	set("long", @LONG
	这便是皇宫正门。巍峨雄伟的城墙上，'紫禁城'三个大字十分显眼，
气势辉煌。一张发黄的告示(gaoshi)贴在墙上，许多官兵立在两旁。
LONG
	);

	set("item_desc", ([
		"gaoshi" : (:look_gaoshi:),
	]));

	set("exits", ([
		"south" : __DIR__"bridge",
	]));
        set("objects", ([
                __DIR__"/d/city/npc/wujiang" : 1,
                __DIR__"/d/city/npc/bing" : 2,
        ]));
	set("outdoors", "city2");
	setup();
}

string look_gaoshi()
{
	return "辑拿天地会一众反贼! \n举报一人，赏金十两;\n"
          "捉拿一人，赏金百两。\n知情不报者，立斩!\n鳌拜发\n";
}

int valid_leave(object me, string dir)
{
    int i;
    object *inv;
    if(dir=="north")
    {
     if( this_player()->query_temp("canenter") )
        {
        inv = all_inventory(me);
        for(i=sizeof(inv)-1; i>=0; i--)
            if(inv[i]->query("weapon_prop") && (inv[i]->query("equipped")))
                if(objectp(present("wujiang", environment(me))))
                    return notify_fail("武将拦住你说道：这位" +
                        RANK_D->query_respect(me) + "请放下兵刃。"
                        "不得持兵刃入宫。\n");
                else if(objectp(present("bing", environment(me))))
                    return notify_fail("官兵拦住你说道：这位" +
                        RANK_D->query_respect(me) + "请放下兵刃。"
                        "不得持兵刃入宫。\n");
     }               				
     else
     {
     if (me->query("gender") == "女性") {
        if(objectp(present("wujiang", environment(me))))
            return notify_fail("武将伸手拦住你朗声说道：皇宫重地，岂" 
            "容寻常烟花女子自由出入," + RANK_D->query_respect(me) +"\n请回，免得"
                "自取其辱。\n");
        else if(objectp(present("bing", environment(me))))
            return notify_fail("官兵伸手拦住你朗声说道：皇宫重地，岂" 
            "容寻常烟花女子自由出入," + RANK_D->query_respect(me) +"\n请回，免得"
            "自取其辱。\n");
    }
     if (me->query("gender") == "无性") {
        if(objectp(present("wujiang", environment(me))))
            say("武将笑吟吟地说道：这位公公您辛苦了，快请进吧。\n");
        else if(objectp(present("bing", environment(me))))
            say("官兵笑吟吟地说道：这位公公您辛苦了，快请进吧。\n");
    }
   return ::valid_leave(me, dir);
}