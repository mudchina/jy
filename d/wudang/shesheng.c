// Room: shiliang.c 石梁
// arnzh 97/1/24
inherit ROOM;

void create()
{
	set("short", "舍身崖");
	set("long", @LONG
	    这里是舍身崖,地势险峻,上面似乎连人都站不了,
武当弟子经常在这里练习轻功.
LONG
	);

	set("exits", ([
		"west" : __DIR__"tyroadct",
	]));

	set("objects", ([
		CLASS_D("wudang") + "/zhangcui" : 1
       ]));

	setup();
	replace_program(ROOM);
}

