//wuqiku.c

inherit ROOM;

void create()
{
        set("short", "武器库");
        set("long",
             "这里是『白驼山』弟子的武器库，『白驼山』弟子可以到此\n"
         "拿取练功用的各种武器。不过别派弟子是不允许进来的。\n"
        );
        set("exits", ([
                "east" : __DIR__"yuanzi",
        ]));
	set("objects",([
		"/clone/weapon/gangzhang":2,
	]));
        setup();
        replace_program(ROOM);
}






