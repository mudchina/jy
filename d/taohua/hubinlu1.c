inherit ROOM;
 
void create()
{
        set("short", "湖滨路");
        set("long",@LONG
这是太湖边上的一条小路。路边有一个青石砌成的码头，
前面有一座大石桥。往桥那边看，只见前面楼阁纡连，竟是
好大的一片庄园。
LONG );
        set("exits", ([
  "northeast" : __DIR__"hubinlu",
  "west" : __DIR__"shiqiao",
]));
        set("outdoors", "taohua");
 
        setup();
}
