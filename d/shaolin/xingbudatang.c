// xingbudatang.c  刑部大堂

#include <room.h>

inherit ROOM;

string look_sign(object me);

void create()
{
        set("short", "刑部大堂");
        set("long", @LONG
你现在正站在刑部大堂里，这里是掌管各种刑罚的地方。
    靠近门口的地方有一块乌木雕成的招牌(sign)。
LONG
        );
        set("exits", ([
                "west" : __DIR__"hubudatang",
         ]) );

        set("objects", ([
		__DIR__"npc/kuli" : 1,
        ]));

        set("item_desc", ([
                "sign": (: look_sign :),
        ]) );
 
        setup();
}

string look_sign(object me)
{
        return "清除判师记录。\n清除PK记录。(Not ready yet)\n清除偷窃记录。(Not ready yet)\n";
}

int valid_leave(object me, string str)
{
	if( me->query_temp("fee_paid") ) 
		me->delete_temp("fee_paid");
	return 1;
}