// tyroad4.c 崎岖山路
// by Marz 

inherit ROOM;

#include "feng.h"

string* npcs = ({
        "guest",
        "tufei2",
        "guest",
        "xiao_tufei",
        "guest",
        "xiao_louluo",
});


void create()
{
	int i = random(sizeof(npcs));

	set("short", "乌鸦岭");
	set("long", @LONG
	这是武当的乌鸦岭，从前是一片乱葬岗，山路崎岖狭隘，一边是峭壁，
一边是悬崖。高高的天柱峰(feng)笼罩在云雾中，隐约可见。可是身旁的进香客
和游人都仔细地町着自己的脚下，不敢抬头望一眼，惟恐一不小心摔下去。更有
强人趁机打劫，行人无不噤声闭气，只求快点敢路。
LONG
	);
	set("outdoors", "wudang");

	set("exits", ([
		"northup" : __DIR__"sanlao",
		"southdown" : __DIR__"nanyan",
	]));

    set("item_desc", ([
        "feng" : (:look_feng:),
    ]));
    
	set("objects", ([
	__DIR__"npc/"+npcs[i] : 1]));
                                    

	setup();
}

void init()
{
        add_action("look_feng", "look");
}
