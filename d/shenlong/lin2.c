inherit ROOM;
string* npcs = ({
	"/d/shenlong/npc/jinshe",
	"/d/shenlong/npc/qingshe",
	"/d/shenlong/npc/jinshe",
	"/d/shenlong/npc/qingshe",
	"/d/shenlong/npc/fushe",
});
 
void create()
{
        set("short", "灌木林");
        set("long",@LONG
这是一片灌木林。走了不远,你就可以看得见前面的空地了。
LONG);
    set("exits", ([
        "north" : "/d/shenlong/kongdi",
        "south" : "/d/shenlong/lin1",
    ]));
        set("objects", ([
	"/d/shenlong/npc/dushe" : 1+random(2),
	npcs[random(sizeof(npcs))] : 1,
	npcs[random(sizeof(npcs))] : 1,
	npcs[random(sizeof(npcs))] : 1,
	]) );
        set("outdoors", "shenlong");
        setup();
	replace_program(ROOM);
}

