// mei_chaofeng.c
// written by Dewey

#include <ansi.h>

inherit NPC;

int do_look(string var);
int ask_me();

void create()
{
	set_name("梅超风", ({ "mei chaofeng", "mei", "chaofeng" }));
	set("long", "她是一个盲了双眼的中年妇人，面目狰狞，好似有什么\n"+
            "深仇大恨。\n");
	set("nickname",HIB "铁尸" NOR);
	set("gender", "女性");
	set("age", 37);
	set("attitude","heroism");
	set("str", 30);
	set("dex", 32);
	set("con", 17);
	set("int", 25);
	set("shen_type", -1);

        create_family("桃花岛", 2, "弟子");

	set_skill("force", 60);
        set_skill("bibo-shengong", 60);
        set_skill("dodge", 150);
        set_skill("anying-fuxiang", 100);
        set_skill("parry", 90);
//      set_skill("sword", 60);
//      set_skill("luoying-shenjian",60);
        set_skill("unarmed",70);
        set_skill("jiuyin-baiguzhao",60);       

        map_skill("force"  , "bibo-shengong");
        map_skill("unarmed"   , "jiuyin-baiguzhao");
        map_skill("dodge"  , "anying-fuxiang");
        map_skill("parry"  , "jiuyin-baiguzhao");

       
    
	set("jiali",50);

	set("combat_exp", 180000);

	set("max_qi", 500);
	set("max_jing", 200);
	set("neili", 400);
	set("max_neili", 400);

	set("inquiry", ([
	    "name" : "站远点！",
	    "陈玄风" : "你问我的贼汉子做什么？他已经死了",
	    "思过" : "我早年背叛师门，才被师傅罚在这里思过。",
	    "九阴真经" : (: ask_me :),
            "黑风双煞" : "那是我和我的贼汉子的名号，你也听说过？",
       ]) );

	set("chat_chance", 10);
	set("chat_msg", ({
	    "梅超风幽幽地叹了一口气，自言自语：「不知道我那贼汉子在地下可有想我？」\n",
	    "梅超风说道：「当年我和我的贼汉子是何等的威风！」\n",
	     }) );

	setup();
	carry_object("/d/taohua/obj/cloth")->wear();
	
}


int ask_me()
{
	object me;

	me = this_player();
	   message("vision",
   HIY "梅超风冷笑一声：『我这就带你去找。』\n"
       "梅超风决心杀死" + me->name() +"\n"
   NOR, environment(), this_object() );
		   kill_ob(this_player());
   return 1;
}


