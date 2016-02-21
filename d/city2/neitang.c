
inherit ROOM;

void create()
{
	set("short", "康府内堂");
	set("long", @LONG
这里是康府内堂，一个仆役正在和丫环们聊天。南边是康府
后院，北边是书房，西边是一座佛堂。
LONG
	);
        set("outdoors", "city2");
	set("exits", ([
  		"north" : "/d/city2/shufang",
  		"south" : "/d/city2/kang3",
  		"west" : "/d/city2/fotang",
	]));
	set("objects", ([
  		"/d/city2/npc/puyi": 1,
  		"/d/city2/npc/yahuan": 2,
	]));
	setup();
	replace_program(ROOM);
}
