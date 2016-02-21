inherit ROOM;			   
      
void create()
{
        set("short", "ÁîÅÆÌÃ");
        set("long",@LONG
ÕâÀïÊÇºÚÄ¾ÑÂµÄµÚ¶ş´óÌÃ°×»¢ÌÃµÄÁîÅÆÊÒ¡£ÊÒÄÚÇà×©ÆÌµØ.×ÀÉÏÓĞÒ»
ºĞ×Ó(box1).£
LONG );		  
        set("exits", ([	
		 "west"      : __DIR__"qing",
  
]));

       
		          
          set("item_desc", ([
        "box1": "ÕâÊÇ¸ö·ÅÁîÅÆµÄºĞ×Ó,²»¹ıÒÔ±»ÈË´ò¿ª,¿Õ¿ÕÈçÒ² ¡£\n",
        	]) );
 
setup();
         replace_program(ROOM);
}