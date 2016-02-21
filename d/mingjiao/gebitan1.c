//gebitan1.c

inherit ROOM;

void create()
{
        set("short", "¸ê±ÚÌ²");
	set("long", @LONG
ÖÕÓÚ´©³öÁËÃÜÁÖ£¬ÑÛÇ°ÊÇÒ»ÍûÎŞ¼ÊµÄ¸ê±ÚÌ²£¬Ã»ÓĞÂ·±ê£¬Ò²Ã»
ÓĞÒ»¸öĞĞÈË£¬ÌìÏÔµÃºÜ¸ß£¬Ô¶É½ÅûÑ©£¬²ÔÓ¥°¿Ïè£¬ºÃÒ»ÅÉ²»Í¬ÓÚÖĞ
ÍÁµÄÒìÓò·ç¹â¡£²»Ô¶´¦£¬¼¸Ö»°×¹ÇÉ¢ÂäµØÉÏ£¬ËÆºõÊÇêóÅ£µÄÊ¬¹Ç¡
×ßÔÚÕâÃ£Ã£¸ê±ÚÖ®ÉÏ£¬ÄãËÆºõÃÔÂ·ÁË¡£
LONG
	);
 	set("exits",([
		      "east" : __DIR__"westroad2",
		      "west" : __DIR__"gebitan2",	
		      "north" : __DIR__"gebitan1",
                      "south" : __DIR__"gebitan1",  				
	]));
	set("objects",([
			"/d/mingjiao/obj/shigu":3,	
	]));
	setup();
	replace_program(ROOM);
}