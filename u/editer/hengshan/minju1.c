//  /d/hengshan/minju1.c
// written by Dewey

inherit ROOM;

void create()
{
        set("short", "民居");
	set("long", @LONG
这是一间破旧的房屋，屋里只有几件残破的家俱。由于战
乱的影响，这里人们的生活都比较贫困。在靠门口的墙角有几
条正在缝制中的口袋，似乎这家人是依靠缝制口袋为生的。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
            "south" : __DIR__"cyxijie",
           ]));
        
        set("no_clean_up", 0);
        
        set("objects", ([
                __DIR__"npc/oldwoman": 1 ]) );

        setup();
        replace_program(ROOM);
}
 
