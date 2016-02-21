
inherit ROOM;

void create()
{
	set("short", "王府井大街");
	set("long", @LONG
这里是王府井大街的尽头。北边是一座富丽堂皇的大楼，门额
上悬挂一方横匾，写着“康亲王府”四个大字，乃是康熙皇帝亲笔。
西边通往地安门。
LONG
	);
        set("outdoors", "city");

	set("exits", ([
		"west" : __DIR__"di_an1",
		"south" : __DIR__"wangfu2",
		"north" : __DIR__"kang1",
	]));

	setup();
	replace_program(ROOM);
}

