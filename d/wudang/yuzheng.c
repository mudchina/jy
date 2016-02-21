// yuzhenggong.c 遇真宫
// by Xiang

inherit ROOM;

void create()
{
	set("short", "遇真宫");
	set("long", @LONG
	这里是武当的遇真宫，不时地有进香客从你的身边走过。两边是几个菩
萨，一条宽阔的石阶穿堂而过，直通笼罩在云雾中的天柱峰，望着堂中烟云缭绕
的香炉，和周围虔诚的许愿人，令人肃然起敬。
LONG
	);
        set("outdoors", "wudang");

	set("exits", ([
		"southdown" : __DIR__"shijie12",
		"northup" : __DIR__"shijie21",
	]));
        set("objects", ([
                __DIR__"npc/guest" : 1]));

	setup();
	replace_program(ROOM);
}

