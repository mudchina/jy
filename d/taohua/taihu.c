inherit ROOM;
 
void create()
{
        set("short", "太湖");
        set("long",@LONG
太湖襟带三州，东南之水皆归于此，周行五百里，古称
五湖。你站在湖边，只见长天远波，放眼皆碧，七十二峰苍
翠，挺立于三万六千顷波涛之中。
LONG );
        set("exits", ([
  "east" : "/d/quanzhou/qzroad2",
  "west" : __DIR__"hubinlu",
]));
        set("outdoors", "taohua");
 
        setup();
}
