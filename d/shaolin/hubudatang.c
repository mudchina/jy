// hubudatang.c

#include <room.h>

inherit ROOM;

string look_sign(object me);

void create()
{
        set("short", "户部大堂");
        set("long", @LONG
你现在正站在户部大堂里，这里是专门替人更改名字的地方，全国各地
的侠客们若是嫌自己的名字不够威风，都是到这里来交钱改名。
    靠近门口的地方有一块乌木雕成的招牌(sign)。
LONG
        );
        set("exits", ([
                "west" : __DIR__"marry_room",
                "east" : __DIR__"xingbudatang",
         ]) );

        set("objects", ([
		__DIR__"npc/shuji" : 1,
        ]));

        set("item_desc", ([
                "sign": (: look_sign :),
        ]) );
 
        setup();
}

string look_sign(object me)
{
        return "更改您的高姓大名。\n";
}

int valid_leave(object me, string str)
{
	if( me->query_temp("fee_paid") ) 
		me->delete_temp("fee_paid");
	return 1;
}