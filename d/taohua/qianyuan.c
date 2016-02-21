#include <room.h>

inherit ROOM;

void create()
{
    set("short", "桃花山庄前院");
    set("long", @LONG
你现在正站在一个宽敞的院子中。院子原来是作为练武场用的。但自从
桃花岛弟子被黄药师逐出岛外，就已经没人在此练武。东面是兵器室，西面
是厨房，往南就是桃花山庄正厅了。
LONG
);
    set("exits", ([
    "north" : __DIR__"damen",
    "south" : __DIR__"dating",
    "east"  : __DIR__"bingqi",
    "west"  : __DIR__"chufang",
]));
    set("outdoors", "taohua");

    setup();
    replace_program(ROOM);
}
