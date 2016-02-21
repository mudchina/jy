// ROOM : xuanya.c
inherit ROOM;
void create()
{
  set("short","悬崖");
  set("long",
      "你终于走出了那片阴深的森林, 不由长长地舒了口气. 可是, 一座\n"
      "陡峭的悬崖又立在了你的面前. 悬崖上仿佛有座白色的建筑. 可云\n"
      "烟缭绕看不清晰. 从悬崖上垂下一条绳索(rope). 看上去象是\n"
      "悬崖上下互通消息的工具.\n " 
     );
  set("exits",([      
      "west"  : __DIR__"linjxd6",
     ]));
 setup();
 replace_program(ROOM);
}
