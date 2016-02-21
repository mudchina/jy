inherit ROOM;
 
void create()
{
        set("short", "湖滨路");
        set("long",@LONG
这是太湖边上的一条小路。路边数十丈处有一叶扁舟停在
湖中，一个渔人坐在船头垂钓，船尾有个小童，烟波浩淼，一
竿独钓，真象一幅水墨山水一般。
LONG );
        set("exits", ([
  "east" : __DIR__"taihu",
  "southwest" : __DIR__"hubinlu1",
]));
        set("outdoors", "taohua");
 
        setup();
}
