inherit ROOM;
 
void create()
{
        set("short", "Ê¥¹ÃÌÃ");
        set("long",@LONG
ÕâÀïÊÇºÚÄ¾ÑÂµÄÊ¥¹ÃËùÔÚµØ¡°Ê¥¹ÃÌÃ¡±¡£ÌÃÉÏÎŞ²ÊÔÆÂŞ,É²ÊÇ
Æ¯ÁÁ.ÌÃÖĞÒ»Î»ÃîÁäÅ®×Ó,Éñ²ÊŞÈŞÈ.£
LONG );
        set("exits", ([
  "east"   : __DIR__"chitang",
]));
        set("objects", ([
		__DIR__"npc/ren" : 1,
		__DIR__"npc/shinu":2,
           ]));       
         setup();
         replace_program(ROOM);
}