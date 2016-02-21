//room: changl11.c
inherit ROOM;

void create()
{
  set("short","画廊");
  set("long",@LONG
这是一条非常精美的长廊，柱子和栏杆是用华贵的紫檀木制成，上面
雕饰着美丽的图画，画工精巧，美不胜收。地板不知是用什么材料做的，
走在上面毫无声息，你只感到脚下软软的，非常舒服。西面是天山童姥关
押犯人的地方，那里是本派禁地，没有童姥的许可，谁也不能进去。
LONG
     );

  set("exits",([
      "east" : __DIR__"changl9",
      "west" : __DIR__"men1",

     ]));

 setup();
 replace_program(ROOM);
}