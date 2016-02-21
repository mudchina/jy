// Room: /u/dewey/shandao.c

inherit ROOM;

#include <ansi.h>

void create()
{
        set("short", "山道");
        set("long", @LONG
你走在登山的路径上，路的左边有一条大铁链，链外就是
万丈的深渊。脚下的路又窄又陡，象是嵌在石壁之中。北方的
朔风在山谷里呼呼地吹过。你不禁为这险峻的景象惊呆了。            
LONG
        );

        set("no_clean_up", 0);

        set("exits", ([ /* sizeof() == 1 */
           "east" : "/u/editer/workroom",
           ]));

        setup();

        replace_program(ROOM);
}
