//ROOM: wuqiku.c

inherit ROOM;

void create()
{
        set("short", "蓼风轩");
        set("long",@LONG
这是『灵鹫宫』弟子的兵器库，你环顾四周，发现墙上嵌满了各式兵
器，仔细一看，原来满墙满壁竟随依各般兵器之形抠出槽子，兵刃就悬于
槽内。你不由暗赞：“好精致的想头！”
LONG       );
        set("exits", ([
		"east" : __DIR__"changl5",
        ]));
        set("objects",([
		"/d/village/obj/zhujian" : 4,
       	]));
        setup();
        replace_program(ROOM);
}
