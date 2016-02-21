// wdroad5.c
// by Xiang

inherit ROOM;

void create()
{
        set("short", "青石大道");
        set("long", @LONG
        你走在一条青石大道上，四周静悄悄的。西南方向似乎有一条黄土路。
        似乎东南方有一丝杀气,远远传来,令人不寒而栗.
LONG
        );
        set("outdoors", "wudang");

        set("exits", ([
                "southeast" : "/d/heimuya/road1", 
                "southwest" : __DIR__"wdroad6",
                "north" : __DIR__"wdroad4",
        ]));

        setup();
        replace_program(ROOM);
}
