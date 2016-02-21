// yanfeng.c
// by shilling 97.2

inherit ROOM;

void create()
{
        set("short", "岩缝");
        set("long", @LONG
忽然，你感觉到被什么东西钩了一下，原来是一棵横着伸出悬崖的古松
止住了下坠之势，细看山崖中裂开了一条大缝，似乎可以攀缘而下。
LONG
        );

       set("exits", ([
               "up" : __DIR__"pubu",
               "down" : __DIR__"gudi",
       ]));
       setup();
	replace_program(ROOM);
}

int valid_leave(object me,string dir)
{
        if(dir=="up") 
	tell_object(me,"你攀着藤蔓，很艰难地向上爬。哎呀唷。，哎呀。。唷。。\n");
	return ::valid_leave(me,dir);
}

