//ROOM: hua1.c

inherit ROOM;

void create()
{
	set("short", "花园");
        set("long",
	     "这是一个极精致的小花园,园中,红梅绿竹, 青松翠柏\n"
	     ", 布置得颇具匠心, 往西去是一片青草地\n"
                         );
        set("exits", ([
		"west" : __DIR__"grass2",
                      ]));
        setup();
        replace_program(ROOM);
}