// Room: /city2/dongmen.c


inherit ROOM;

string look_gaoshi();

void create()
{
	set("short", "东门");
	set("long", @LONG
这是东城门，城门正上方刻着“东门”两个大字，城墙上贴着
几张官府告示(gaoshi)。一条笔直的青石板大道向东西两边延伸。
东边是郊外，越过城门可以看到驿道上人来车往，尘土飞扬。西边
通往城里。西北边是朝阳门。
LONG
	);
        set("outdoors", "city2");

	set("item_desc", ([
		"gaoshi" : (: look_gaoshi :),
	]));
	set("exits", ([
		"east" : "/d/city2/road1",
		"northwest" : __DIR__"chaoyan2",
		"west" : __DIR__"dongcha2",
	]));

	set("objects", ([
		"/d/city/npc/wujiang" : 1,
		"/d/city/npc/bing" : 2,
	]));

	setup();
}

string look_gaoshi()
{
	return "辑拿天地会一众反贼! \n举报一人，赏金十两;\n"
          "捉拿一人，赏金百两。\n知情不报者，立斩!\n鳌拜发\n";
}

