//road1.c 黄土路
// by Xiang

inherit ROOM;

void create()
{
        set("short", "乱石坡");
	set("long", @LONG
这是一处乱石怪异的小山岗，向西便是通向云南的大路了.
据说前方经常有野兽出没，不可久留。
LONG
	);
        set("outdoors", "wudang");

        set("exits", ([
                "northwest" : "/d/wudang/wdroad5",
                "west" : __DIR__"linjxd1.c",
                "east" : __DIR__"dating4",
        ]));
        set("objects",([  
           __DIR__"npc/laozhe" : 1 ,])); 

        setup();
        replace_program(ROOM);
}