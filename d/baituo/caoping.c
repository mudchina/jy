// caoping.c
inherit ROOM;
void create()
{
        set("short","草坪");
        set("long",
             "这里是一块芳草坪，绿草茵茵，蝴蝶漫舞，让人感到惬意。\n"
         "不过偶尔也会碰到菜花蛇￣\n"
        );
        set("exits", ([
                "west" : __DIR__"shijie",
        ]));
         set("objects" , ([
             __DIR__"npc/caihuashe" : random(2),
             ]));
        set("outdoors", "baituo");
        setup();
        replace_program(ROOM);
}
