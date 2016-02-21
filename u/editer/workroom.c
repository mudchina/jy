
// Room: /u/dewey/workroom.c

#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "虚清子的工作室");
        set("long", 
"这是一间宁静的小屋，清晨的阳光静静地从窗外洒进来。\n"+
"房间里除了一个书架和一张放着电脑的工作台之外，几乎什么\n"+
"都没有。墙上贴着一幅龙飞凤舞的字："+BLINK HIB"“宁静而志远”。\n" NOR         
        );
 
        set("no_clean_up", 0);
        
        set("exits", ([ /* sizeof() == 3 */
           "northeast" : "/d/city2/dating",
           "north" : "/u/dewey/workroom",
           "west" : "/u/editer/hengshan/shaodao1",
            ]));

      
        
        setup();

        replace_program(ROOM);
}
