//room: didao2.c
inherit ROOM;

void create()
{
  set("short","秘道");
  set("long",
	"你来到了一条秘道,看样子它不太平常,若隐若显的几盏油灯，昏暗如豆\n"
        "但是看上去前方似有光亮，你要是觉得害怕,现在回头还是可以的,不过\n"
        "这异常的幽静却也极大激发了你的好奇心,大丈夫死又何足道载,真是勇\n"
        "气可佳.\n"
    );

  set("exits",([
      "down" : __DIR__"mishi",
      "west" : __DIR__"didao1", 
      "south" : __DIR__"didao5",
     ]));

 setup();
 replace_program(ROOM);
}