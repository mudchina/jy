inherit ROOM;

void create()
{
	set("short", "杨柳胡同");
	set("long", @LONG
这是一条十分僻静的小胡同，东南面有一家客店，隐隐约约
传来打斗之声。你颇有些犹豫：要不要过去看一看呢，不会有什
么危险吧？东北边可以出胡同。
LONG
	);
        set("outdoors", "city2");

	set("exits", ([
		"southeast" : __DIR__"kedian1",
		"northeast" : __DIR__"alley2",
	]));

	set("objects", ([
                 "/d/village/npc/dipi" : 1,
                 "/d/city2/npc/punk" : 1,
	]));

	setup();
	replace_program(ROOM);
}

