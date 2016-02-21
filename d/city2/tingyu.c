inherit ROOM;
#include <ansi.h>
#define POEM_DOC   "/doc/poem/doc"
#define POEM_DIR "/doc/poem/"

string look_shelf();

void create()
{	
set("short", "听雨轩");
set("long", @LONG	
这是一间清幽的小竹舍。一尘不染的书架(shelf) 上放满各种书籍，
其中有无数绝美的诗词。你可以用read来读取。一位天仙般的少女正低
着头读书，听得脚步，抬头望你。
LONG	);	
set("valid_startroom",1);
set("no_steal", "1");
set("exits", ([	
"south" : "/d/city2/xiaoyuan",
"north" : "/d/city2/xukong",
]));
set("objects", ([
	"/u/wind/liling2" : 1,
	]));
set("item_desc", ([
                "shelf" : (: look_shelf :),
	]));
setup();
}

void init()
{
	add_action("do_read", "read");
}

string look_shelf()
{
        this_player()->start_more(read_file(POEM_DOC));
        return "\n";
}

int do_read(string arg)
{
        if (arg == "" || file_size(POEM_DIR + arg) <= 0)
                return notify_fail("这里没有这本书。\n");
	log_file("POEM", sprintf("%s read %s.\n", this_player()->query("name"), arg));
	this_player()->start_more(read_file(POEM_DIR + arg));
	return 1;
}
