// 练武场
// written by dewey

inherit ROOM; 
 
void create() 
{ 
	set("short", "练武场"); 
	set("long", "这是一间什麽也没有的空房间。\n"); 
	setup(); 
	replace_program(ROOM); 
} 
