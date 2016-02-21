// gudi.c
// by shilling 97.2

inherit ROOM;

void create()
{
        set("short", "谷底");
        set("long", @LONG
但听得耳边轰聋聋的响声越来越大，山崖也逐渐变得倾斜，而不再象上
面那么陡峭笔立了，终于到达谷底了。只见上面的上崖一条大瀑布如玉龙悬
空，滚滚而下，倾入了一座清澈异常的大湖之中。甚为壮观。
LONG
        );

        set("exits", ([
//               "out" : __DIR__"damen",
//               "north" : __DIR__"shishi1",
               "up" : __DIR__"yanfeng",
               "west" : __DIR__"hubian",
	
        ]));
        set("outdoors", "xiaoyao" );
	setup();
	replace_program(ROOM);
}
