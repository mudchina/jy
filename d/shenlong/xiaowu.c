#include <ansi.h>

inherit ROOM;
string* books = ({
	"/d/shaolin/obj/book-bamboo",
	"/d/shaolin/obj/book-paper",
	"/d/shaolin/obj/book-silk",
	"/d/shaolin/obj/book-stone",
	"/d/shaolin/obj/book-iron",
	"/d/wudang/obj/quanpu",
        "/d/xingxiu/obj/dujing_1",
//        "/d/shenlong/obj/zhangfa",
//        "/d/shenlong/obj/shoufa",
//        "/d/shenlong/obj/bufa",
});


void create()
{
    set("short", "小屋");
    set("long", @LONG
一进小屋,只见墙上挂满了无数名贵的字画.书架上也堆满了
平时难得一见的各种各样的书籍.一个相貌英武的中年文士正对
着一幅字画唉声叹气.
LONG
    );

    set("exits", ([
		"south" : __DIR__"kongdi",

    ]));
    set("objects", ([
		"/d/shenlong/npc/lu": 1,
		books[random(sizeof(books))] : 1,
		books[random(sizeof(books))] : 1,
    ]));
    set("outdoors", "shenlong");
    setup();
   replace_program(ROOM); 
}


