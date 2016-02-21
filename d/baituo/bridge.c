//bridge.c

inherit ROOM;

void create()
{
        set("short", "小桥");
        set("long",
             "这是一座小竹桥，『白驼山』上的冰雪融化形成一条清澈的小溪\n"
         "，从桥下缓缓流过。不时有顽皮的小鱼跃出水面，在阳光下划出一条\n"
         "银白色的弧线。\n"
        );
        set("outdoors", "baituo");
        set("exits", ([
                "northwest" : __DIR__"guangchang",
                "east" : __DIR__"xijie",
        ]));
        set("objects",([
                __DIR__"npc/cungu" : 1,
        ]));
        setup();
        replace_program(ROOM);
}
