//room: jian.c

inherit ROOM;

void init();
int do_zou(string);

void create()
{
  set("short","百丈涧");
  set("long",@LONG
山道到此突然消失，在你面前是一条山涧，山涧之中云雾缭绕，你根
本无法看清对面。一条铁索(tiesuo)深入云中，旁边有一块石碑(bei)。
LONG
     );
  set("outdoors", "lingjiu");
  set("exits",([
      "southdown" : __DIR__"yan",
     ]));
  set("objects",([
    __DIR__"npc/yupopo" : 1,
    ]));
  set("item_desc",([
      "bei" : "『灵鹫宫』重地，擅入者死！\n" ,
      "tiesuo" : "这是通往对面的“接天桥”，你也许可以走过(zou)去。\n" ,
     ]));
  setup();
}

void init()
{
	add_action("do_zou", "zou");
}

int do_zou(string arg)
{
	object me=this_player(), room;

	if(!arg || arg!="tiesuo")
		return notify_fail("你要走什么？\n");

	if(!( room = find_object(__DIR__"xianchou")) )
		room = load_object(__DIR__"xianchou");

	if(!objectp(room))
		return notify_fail("ERROR:not found 'xianchou.c' \n");
	message_vision("$N踩上铁索，飘然而去。\n",me);
//       　message("vision","你只见一个身影飘然而来。\n", room);
        me->move(room);
        return 1;
}