inherit ROOM;

void create()
{
    set("short", "墓地");
	set("long", @LONG
这里是黑木崖日月神教教众的墓地。墓地周围种了一些矮矮的花树。
树上的白花星星点点。白花中间是一高大的石碑(bei)，整个墓地干
干净净，显然天天有人打扫。
LONG
	);
	set("exits", ([
        
        "west"      : __DIR__"grass1",
        ]));
	set("item_desc", ([
        "bei": "上面刻着：神教子民,永生不灭。\n"
	]) );

	setup();
        replace_program(ROOM);

}