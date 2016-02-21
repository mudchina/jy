//room: restroom.c
//restroom
inherit ROOM;

void create()
{
  set("short","憩凤阁");
  set("long",@LONG
这里是灵鹫宫弟子睡觉的地方，一进门就闻到一阵悠悠的香气，只见
房中点了一支大红烛,照的满室生春,床上珠罗纱的帐子，白色缎被上绣着
一只黄色的凤凰，壁上挂着一幅工笔仕女图。西首一张几上供着一盆兰花，
架子上停着一只白鹦鹉。
LONG
     );

  set("exits",([
      "west" : __DIR__"changl3",
     ]));

  set("sleep_room", 1);
  set("no_fight",1);
  set("no_steal",1);

 setup();
 replace_program(ROOM);
}
