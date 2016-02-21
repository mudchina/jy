//westroad1.c

inherit ROOM;

void create()
{
        set("short", "山路");
        set("long",
             "这是一条直通西方的山路，向西远望，群山巍峨，云雾飘渺，\n"
         "再往前不远，就要进入深山之中了。东方香烟缭绕之处，就是武当山。\n"
	);
	set("exits",([
		      "west" : __DIR__"westroad2",
		      "east" : "/d/wudang/shanmen",
	   ]));
	setup();
	replace_program(ROOM);
}
        