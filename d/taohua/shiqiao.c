inherit ROOM;
 
void create()
{
        set("short", "大石桥");
        set("long",@LONG
这是太湖边上一条港汊上的石桥，站在桥上，千顷湖面尽
在眼前，不由得心旷神怡，忘却了烦恼。桥的西面是很大的一
片庄园。
LONG );
        set("exits", ([
  "east" : __DIR__"hubinlu1",
  "west" : __DIR__"zhangqian",
]));
        set("outdoors", "taohua");
 
        setup();
}
