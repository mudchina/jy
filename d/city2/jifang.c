
inherit ROOM;
#include <ansi.h>


void create()
{
	set("short", "网络机房");
	set("long", @LONG
这里是一个拥有两百多台586的超大规模机房.计算机系、电信系、信息系、
应科系等各系的网虫们，都经常聚在这里泡网。今天屋里又座无虚席,然而竟然
没有一个人play MUD。墙上贴着一份通告 (tonggao)，旁边的架子上摆着一块
小黑板(board).
LONG
	);
	set("exits", ([ 
  "west" : __DIR__"xukong",
  "north" : __DIR__"ximenwai",
]));

       set("item_desc", ([
                "tonggao" :   
  HIR "本机房郑重宣布,以下大虾小虾皆被停机一月:\n" NOR +
  HIR "并罚款五十两白银,望其它虾咪引以为戒:\n" NOR +
  HIM "华山第十四代弟子[武痴]卓云白(zyb)\n" NOR +
  HIM "云龙门第三代弟子[笑比哭好]司马湘云(huak)\n" NOR +
  HIM "武当第三代弟子 何停雨(xiao)\n" NOR +
  HIR ".......\n" NOR,
 "board" :   HIC "请注意,以下机器因长期被敲敲打打，已不能正常使用：\n" NOR +
  HIM "55号机，60号机，78号机，136号，。。。。。\n" NOR,
	]));

      set("valid_startroom",1);
	set("objects", ([ 
		"/d/city2/npc/zhuge" : 1,
	]));
	setup();
}

int valid_leave(object me, string dir)
{
    int i;
    object *inv;
if(dir=="west")
 {
        inv = all_inventory(me);
        for(i=sizeof(inv)-1; i>=0; i--)
		if(objectp(present("zhuge", environment(me)))&&living(present("zhuge", environment(me))))
                    return notify_fail("诸葛老太上前大喝一声："+
                        RANK_D->query_rude(me) + "哪里走？！\n");
	return ::valid_leave(me, dir);
 }
return ::valid_leave(me, dir);
}

