#include <ansi.h>

inherit ROOM;
string* flowers = ({
	"/d/shenlong/obj/hua",
	"/d/shenlong/obj/hua",
	"/d/shenlong/obj/hua2",
	"/d/shenlong/obj/hua3",
	"/d/shenlong/obj/hua4",
	"/d/shenlong/obj/hua2",
	"/d/shenlong/obj/hua3",
	"/d/shenlong/obj/hua4",
});
string* npcs = ({
	"/d/shenlong/npc/boy",
	"/d/shenlong/npc/boy2",
	"/d/shenlong/npc/boy3",
	"/d/shenlong/npc/boy4",
	"/d/shenlong/npc/girl",
	"/d/shenlong/npc/boy",
	"/d/shenlong/npc/boy2",
	"/d/shenlong/npc/boy3",
	"/d/shenlong/npc/boy4",
	"/d/shenlong/npc/girl",
	"/d/shenlong/npc/girl",
});



void create()
{
    set("short", "草坪");
    set("long", @LONG
这里是一片青青的草坪,有几个少年在玩耍.四周开满了各色的
鲜花,一阵凉风吹过,清新的空气中传来几缕淡淡的花香.
LONG
    );

    set("exits", ([
		"east" : __DIR__"kongdi",

    ]));
    set("objects", ([
		npcs[random(sizeof(npcs))] : 1,
		npcs[random(sizeof(npcs))] : 1,
		npcs[random(sizeof(npcs))] : 1,
		npcs[random(sizeof(npcs))] : 1,
		flowers[random(sizeof(flowers))] : 1,
		flowers[random(sizeof(flowers))] : 1,
		flowers[random(sizeof(flowers))] : 1,
    ]));
    set("outdoors", "shenlong");
    setup();
}

int valid_leave(object me, string dir)
{
	if (objectp(present("duanchang", environment(me)))) 
	{
        if((int)this_player()->query_condition("flower_poison") < 10 ) {
		this_player()->apply_condition("flower_poison", 30);
        tell_object(me, HIG "你只觉一股淡香袭来,顿时脑中一阵麻木！\n" NOR );
	}
	}
	return ::valid_leave(me, dir);
}
