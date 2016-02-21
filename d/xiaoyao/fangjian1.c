// shishi1.c
// by shilling 97.2

inherit ROOM;

void create()
{
        set("short", "房间");
        set("long", @LONG
可以看出这里以前曾经是一个下棋的地方，房间除了一张石几，两只软
椅之外，空荡荡的一无所有，石几上刻着纵横十九道棋路，棋局上布着二百
多颗棋子，却是黑白对峙，竟然是一局没有下完的棋。
LONG
        );

       set("exits", ([
               "south" : __DIR__"shiji1",
       ]));
       setup();
	replace_program(ROOM);
}
