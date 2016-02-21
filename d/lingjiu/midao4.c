
inherit ROOM;

void create()
{
	set("short", "密道");
	set("long", @LONG
台阶终于走到了头，眼前是一间小小的石室，周围墙壁上插着几盏油
灯，照得石室里一片昏黄。北边有一条通道。
LONG
	);

	set("exits", ([
		"westup" : __DIR__"midao3",
		"north": __DIR__"midao5",
	]));
	setup();
        replace_program(ROOM);
}