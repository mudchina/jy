// marry_room.c

#include <room.h>

inherit ROOM;

string look_sign(object me);

void create()
{
        set("short", "红娘庄");
        set("long", @LONG
你现在正站在红娘庄里，这里是专门替人缔结婚约和解除婚约的地方，
镇里所有的夫妇都是在这里喜结良缘的，就连附近镇子也有许多慕名而来的。
东面是侠客们改名的地方。
    靠近门口的地方有一块乌木雕成的招牌(sign)。
LONG
        );
        set("exits", ([
		"west" : __DIR__"ruzhou",
		"east" : __DIR__"hubudatang",
         ]) );

        set("item_desc", ([
                "sign": (: look_sign :),
        ]) );

        set("objects", ([
                __DIR__"npc/mei_po" : 1,
        ]) );
 
        setup();

}

string look_sign(object me)
{
        return "缔结或解除婚约。\n";
}

int valid_leave(object me, string dir)
{
 	if ( me->query_temp("pending/pro") )
           me->delete_temp("pending/pro");
       return ::valid_leave(me, dir);
}