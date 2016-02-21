// /d/emei/yunvfeng.c 峨嵋派 玉女峰

inherit ROOM;

void create()
{
	set("short", "玉女峰");
	set("long", @LONG
这里是华山的中峰，玉女峰。玉女峰地势略为平缓，不似其它四峰般
险峻，江湖上赫赫有名的华山剑派就在此处。西边有所小小的庙宇，那就
是玉女祠了。东北面稀稀落落有十几间房子，是华山派的地方，闲杂游客
最好别往那里去。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
		"northdown" : __DIR__"guanyintang",
		]));
	set("no_clean_up", 0);
	set("outdoors", "huashan" );

	set("objects", ([ 
		__DIR__"npc/lingshan" : 1,
	]));

	setup();
	replace_program(ROOM);
}