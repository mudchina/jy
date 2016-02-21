// damen.c
// by shilling 97.2

inherit ROOM;

void create()
{
        set("short", "石室大门");
        set("long", @LONG
穿多岩洞，突然之间，手碰到一个冷冰冰的圆物，原来是个门环，门环
的后面象是一扇铜铁铸成的大门，十分沉重。即使是臂力很好的人，推它也
觉得甚为吃力。
LONG
        );

       set("exits", ([
               "north" : __DIR__"shidong",
               "south" : __DIR__"yandong",
       ]));
       setup();
	replace_program(ROOM);
}
