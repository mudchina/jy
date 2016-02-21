
inherit ROOM;
string* npcs = ({
	"/d/shenlong/npc/boy",
	"/d/shenlong/npc/boy2",
	"/d/shenlong/npc/boy3",
	"/d/shenlong/npc/boy4",
	"/d/shenlong/npc/girl",
});


void create()
{
	set("short", "神龙教大厅");
	set("long", @LONG
过了一条长廊,眼前突然现出一座大厅.此厅硕大无朋,足可容千人
之众.只见一群群少年男女衣分五色,分站五个方位.青、白、黑、黄
四色的都是少年,穿红的却是少女,背上各负短剑,每一队约有百人.
LONG
	);

	set("exits", ([
		"south" : __DIR__"damen",
	]));

	set("objects", ([
		npcs[random(sizeof(npcs))] : 1,
		npcs[random(sizeof(npcs))] : 1,
		"/d/city2/npc/dizi": 1,
                "/d/shenlong/npc/old": 1+random(2),
		"/d/shenlong/npc/hong": 1,
		"/d/shenlong/npc/zhang": 1,
		"/d/shenlong/npc/wugen": 1,
	]));

	setup();
}

