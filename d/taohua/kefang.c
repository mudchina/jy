inherit ROOM;

void create()
{
    set("short", "客房");
    set("long", @LONG
这是专供客人们休息的客房。屋里陈设华美，窗上挂着刺
绣精美的窗帘，房内的一侧放着五六张雕花木床，却不显得拥
挤，房间的中央放着一张桌子，上面摆一茶壶、几个瓷杯和一
些糕点。屋脚有几筒清水。
LONG );
    set("exits", ([
    "east"  : __DIR__"qianyuan1",
    ]));
    
    set("objects", ([
        __DIR__"obj/cha" : random(2),
        __DIR__"obj/gao"  : random(3),
    ]) );    

    set("sleep_room","1") ;
    set("resource/water", 1);
    
    setup();
    replace_program(ROOM);
}
