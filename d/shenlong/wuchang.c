
inherit ROOM;
string* npcs = ({
	"/d/shenlong/npc/boy",
	"/d/shenlong/npc/boy2",
	"/d/shenlong/npc/boy3",
	"/d/shenlong/npc/boy4",
	"/d/shenlong/npc/girl",
	"/d/shenlong/npc/boy",
	"/d/shenlong/npc/boy2",
	"/d/shenlong/npc/boy3",
	"/d/shenlong/npc/boy4",
	"/d/shenlong/npc/girl",
	"/d/shenlong/npc/girl",
});


void create()
{
	set("short", "练武场");
	set("long", @LONG
这是一个宽大的练武场，有几个手执短剑的少年少女在这里练功。
旁边站着几人,有男有女,年纪轻的三十来岁,老的已有六七十岁,身上
却不带兵刃.北边一条山路直上山顶.
LONG
	);
	set("exits", ([
		"east" : __DIR__"wuchang2",
		"west" : __DIR__"road",
		"north" : __DIR__"road2",
	]));
	set("objects", ([
		npcs[random(sizeof(npcs))] : 1,
		npcs[random(sizeof(npcs))] : 1,
		npcs[random(sizeof(npcs))] : 1,
		npcs[random(sizeof(npcs))] : 1,
		npcs[random(sizeof(npcs))] : 1,
                "/d/shenlong/npc/old": 2+random(3),
	]));
        setup();
	replace_program(ROOM);
}

