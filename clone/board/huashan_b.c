// /clone/board/huashan_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("华山派弟子留言板", ({ "board" }) );
	set("location", "/d/huashan/buwei1");
	set("board_id", "huashan_b");
	set("long", "有有用的话就往这里说，乱灌水杀无赦。\n" );
	setup();
	set("capacity", 30);
	replace_program(BULLETIN_BOARD);
}

