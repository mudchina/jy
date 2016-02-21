//room: chengdedian.c
inherit ROOM;

void create()
{
  set("short","成德殿");
  set("long",
	"这就是日月神教教主平日发号施令的地方, 殿中无窗, 殿口点着\n"
        "明晃晃的蜡烛, 大殿彼端高设一座, 坐着一个英俊的中年人, 自是\n"
        "名震江湖的东方不败的姘头杨莲亭了!\n" 
     );

  set("exits",([
      "south" : __DIR__"huoting",
      "westdown":__DIR__"up4",
     ]));
  set("objects",([
		               __DIR__"npc/dizi" : 2,
                               __DIR__"npc/yang"    :1,
        ]));
  

 setup();
 replace_program(ROOM);
}