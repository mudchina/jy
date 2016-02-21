// fuzhen1.c 复真观一层
// by arnzh 97/1/24

inherit ROOM;

void create()
{
	set("short", "复真观一层");
	set("long", @LONG
	这是一座刚建好的道观，门前一块新漆的匾额，上书"复真观"，这是武
当出售香烛和书经的地方，武当弟子也常到这里来读、抄经书，这是武当多年维
持旺盛香火的支柱之一，常有人在这里讨得一纸道德经，回去家中诵读。
LONG
	);
        set("outdoors", "wudang");

	set("exits", ([
		"east" : __DIR__"xuanwumen",
		"eastup" : __DIR__"fuzhen2",
	]));
        set("objects", ([
                CLASS_D("wudang") + "/zhixiang" : 1,
                       ]));

       	setup();
	replace_program(ROOM);
}

