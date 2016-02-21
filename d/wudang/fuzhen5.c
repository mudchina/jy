// cangjingge.c 藏经阁
// by Xiang
// 05/30/96 Marz

inherit ROOM;

/*
string* books = ({
	"laozi1",
	"daodejing-i",
	"laozi2",
	"daodejing-i",
	"laozi8",
	"daodejing-i",
	"laozi13",
	"laozi1",
	"laozi16",
	"daodejing-i",
	"laozi18"
});
*/
void create()
{
	set("short", "复真观五层");
	set("long", @LONG
	这里是复真观五层，靠墙是一排书架，摆满了道教的典籍，和一些武功秘籍。
这里是武当重地，有武当弟子才能入内。
LONG
	);

	set("exits", ([
		"southdown" : __DIR__"fuzhen4",
	]));

	set("objects", ([
//		CLASS_D("wudang") + "/songqing" : 1,
		"/u/fcxy/songqing":1,
	]));

	setup();
	replace_program(ROOM);
}
