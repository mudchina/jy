
inherit ROOM;

string* books = ({
	"/d/city2/obj/yljing",
	"/d/city2/obj/yljing1",
	"/d/city2/obj/yljing2",
//	"/d/city2/obj/yljian",
//	"/d/city2/obj/ylbian",
	"/d/shaolin/obj/book-bamboo",
	"/d/shaolin/obj/book-paper",
	"/d/shaolin/obj/book-silk",
	"/d/shaolin/obj/book-stone",
	"/d/shaolin/obj/book-iron",
	"/d/wudang/obj/quanpu",
        "/d/xingxiu/obj/dujing_1",
});

void create()
{
	set("short", "侧厅");
	set("long", @LONG
这里是侧厅，靠墙是一排书架，摆满了各种拳谱、书籍。墙角有一张木床。
天地会总舵主陈近南常常在这里读书、休息。
LONG
	);

	set("exits", ([
		"west" : __DIR__"dating",
	]));

        set("sleep_room", 1);   
	set("objects", ([
		books[random(sizeof(books))] : 1,
		books[random(sizeof(books))] : 1,
		books[random(sizeof(books))] : 1,
		books[random(sizeof(books))] : 1,
	]));

	setup();
	replace_program(ROOM);
}
