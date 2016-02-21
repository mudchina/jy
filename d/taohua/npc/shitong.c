// shitong.c

inherit NPC;

void create()
{
	set_name("侍童",({ "shi tong","shi","tong" }) );
        set("gender", "男性" );
        set("age", 13);
        set("long", 
            "桃花岛上的侍童，长得清秀俊美，虽然表情严肃。\n"+
            "但眼睛却盯着你不停地骨碌碌乱转。\n");

        set("str", 17);
        set("dex", 16);
        set("con", 15);
        set("int", 17);
        set("combat_exp", 500);
        set("attitude", "peaceful");

        setup();
        carry_object("d/taohua/obj/cloth")->wear();
}