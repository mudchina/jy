//      cedian2.c 侧殿
//      Designed by secret (秘密)
//      97/04/09

inherit ROOM;

void create()
{
        set("short","侧殿");
        set("long",@LONG
这里是雪山寺的西侧殿。墙壁上描绘着佛祖传道的故事。
LONG
        );

        set("exits",([
                "up" : __DIR__"zoulang2",
                "east" : __DIR__"dadian",
        ]));
        set("objects", ([
                CLASS_D("xueshan")+"/samu" : 1,
                __DIR__"npc/xiang-ke" : 1,
        ]));

        setup();
}

int valid_leave(object me, string dir)
{
        mapping myfam;
        myfam=(mapping)me->query("family");
        if( (!myfam || myfam["family_name"] !="雪山寺") && dir=="up"
        && objectp(present ("samu huofo" ,environment(me) ))) 
                return notify_fail("萨木活佛说道 : 你非雪山寺弟子 ,不得入内!! \n");
        return ::valid_leave(me,dir);
}
