// tyroad11.c 桃园小路
// by Marz 

inherit ROOM;
#include "feng.h"
string* npcs = ({
	"little_monkey",
	"monkey",
	"little_monkey",
	"little_bee",
	"bee",
	"little_bee",
});
                                
void do_tao();
int do_zhai(string arg);
void create()
{
	int i = random(sizeof(npcs));
	    
	set("short", "榔梅园");
	set("long", @LONG
	眼前豁然开朗，你轻松地走在榔梅园的小路上。两边是桃树林(tree)，树上盛开
着粉红的桃花，红云一片，望不到边。不时有蜜蜂「嗡嗡」地飞过，消失在在花丛
中；几只猴子在树上互相追逐着，叽叽喳喳地争抢桃子。远处是高高的天柱峰(feng)。
LONG
	);
	set("outdoors", "wudang");

	set("exits", ([
		"east" : __DIR__"lameigt",
	]));
	
	set("item_desc", ([
        	"feng" : (:look_feng:),
		"tree" : 
"这是一片桃林，上面结满了水蜜桃，引得人哈喇子都掉下来了。\n"
	 ]));
	set("objects", ([
 		CLASS_D("wudang") + "/shouyuan" : 1,
		__DIR__"npc/"+npcs[i] : 1

	]));
	set("taocount",2);
	        
	setup();
}
void init()
{
        add_action("look_feng", "look");
	add_action("do_zhai","zhai");
}

int do_zhai(string arg)
{       object tao;
         if( !arg || arg=="" ) {
message_vision("你想摘什么？\n", this_player());
return 1;
}
        if( arg=="tao"||arg=="taozi" ) {
            if(query("taocount") > 0){
                message_vision(
       "$N桃树上摘下一个熟透的水蜜桃。\n"
                        , this_player());
                tao = new(__DIR__"obj/mitao");
                tao->move(this_player());
		add("taocount",-1);
                return 1;
		}else
        message_vision(
	"你这么着急呀？桃还没熟呢。\n" , this_player());
	remove_call_out("do_tao");
        call_out("do_tao",60);
	return 1;	     
                }
        return 0;
}
void do_tao()
{
	set("taocount",2);
}