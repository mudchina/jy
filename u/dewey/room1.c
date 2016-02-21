// Room: /d/snow/school.c                                                       
                                                                                
#include "/include/ansi.h";                                                     
inherit ROOM;                                                                   
inherit F_SAVE;                                                                 
int zhenfa;                                                                     
//int do_change();                                                              
void create()                                                                   
{                                                                               
                                                                                
string longtxt,randtxt;                                                         
mapping *notes;                                                                 
        int num;                                                                
        restore_object("/data/board/info_b");                                   
        notes = query("notes");                                                 
        zhenfa=random(4);                                                       
        set("short","书院");                                                    
        if( !arrayp(notes) || num < 1 || num > sizeof(notes) )                  
        {                                                                       
                                                                                
        switch( zhenfa ) {                                                      
        case 0:                                                                 
                randtxt="远方传来悦耳的风铃声，给这片山林带来了不少生机。";     
                break;                                                          
        case 1:                                                                 
                randtxt="远处传来清脆的木鱼声，给这片山林带来了不少生机。";     
                break;                                                          
        case 2:                                                                 
                randtxt="远方飘动着的一缕炊烟，给这片山林带来了不少生机。";     
                break;                                                          
        case 3:                                                                 
                randtxt="远处传来潺潺的流水声，给这片山林带来了不少生机。";     
                break;                                                          
        }                                                                       
        longtxt =                                                               
        "这里是一间宽敞的书院，虽然房子看起来很老旧了，但是打扫得很             
整洁，墙壁上挂著一幅山水画，意境颇为不俗，书院的大门开在北边。                  
"+randtxt+"\n";                                                                 
        set("long", longtxt                                                     
        );                                                                      
        set("exits", ([ /* sizeof() == 1 */                                     
        "south" : __DIR__"entry2",                                              
        "north" : __DIR__"entry",                                               
        "east":__DIR__"workroom",                                                  
        "down":__FILE__,                                                        
        ]));                                                                    
        }                                                                       
        else{ num=sizeof(notes)-1;                                              
        if (notes[num]["status"]) {set("short","废墟");                         
        set("long","这里是一片废墟，只有一块孤零零的石碑立在那里，气氛十分诡异");
}                                                                               
        delete("exits/down");}                                                  
                                                                                
        setup();                                                                
	 "/clone/board/wiz_b"->foo();
}                                                                               
void init()                                                                     
{       remove_call_out("help_signal");                                         
        call_out("help_signal",20);                                             
        this_player()->set("marks/zhen",zhenfa);                                
        add_action("do_change","destroy");                                      
        add_action("do_rebuild","rebuild");                                     
}                                                                               
int help_signal()                                                               
{                                                                               
        string signal;                                                          
        switch( zhenfa ) {                                                      
        case 0:                                                                 
                signal=CYN "一阵风铃摇曳之声传来，清脆悦耳，让你不禁忘了心中的烦恼" NOR;                                                                        
                break;                                                          
        case 1:                                                                 
                signal=HBYEL "一阵清脆的木鱼声传来，令你的心境顿时平静下来。" NOR;
;                                                                               
                break;                                                          
        case 2:                                                                 
                signal=HIW "远方炊烟袅袅，使久涉江湖的你不禁想起家中的亲人。" NOR;
;                                                                               
                break;                                                          
        case 3:                                                                 
                signal=BLU "远方流水潺潺，在这宁静的山林中显得格外的清晰。" NOR;
                break;                                                          
        }                                                                       
        write(signal+"\n");                                                     
        return 1;}                                                              
        int do_change(string arg)                                               
        {if (!arg) return notify_fail("请留言\n");                              
        set("short","废墟");                                                    
        set("long","这里是一片废墟，只有一块孤零零的石碑立在那里，气氛十分诡异");
                                                                                
        delete("exits/down");                                                   
        call_other("/clone/board/try_b","do_destroy",this_player(),arg);        
        return 1;}                                                              
int do_rebuild(string arg)                                                      
        {                                                                       
        if (!arg) return notify_fail("请题字\n");                               
        set("short","书院");                                                    
                                                                                
        set("long", "这里是一间宽敞的书院，虽然房子看起来很老旧了，但是打扫得很 
        整洁，墙壁上挂著一幅山水画，意境颇为不俗，书院的大门开在北边。          
        \n" );                                                                  
        set("exits/down",__FILE__);                                             
        call_other("/clone/board/try_b","do_rebuild",this_player(),arg);        
        return 1;}      //以上为房间原码                                        
