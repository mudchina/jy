// luguanying.c 

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void greeting(object);
void init();


void create()
{
    set_name("陆冠英", ({"lu guanying", "lu", "guanying"}));
    set("title",WHT "归云庄少庄主" NOR);    
    set("gender", "男性");
    set("age", 23);
    set("long", 
        "这是归云庄的少庄主。长身玉立，身型矫健，充满了年轻人的朝气。\n"
        );

    set("attitude", "peaceful");
      
    set("str", 24);
    set("int", 20);
    set("con", 21);
    set("dex", 20);

    set("qi", 300);
    set("max_qi", 300);
    set("jing", 100);
    set("max_jing", 100);
    set("neili", 300);
    set("max_neili", 300);
    set("jiali", 0);
       
    set("combat_exp", 50000);
    set("score", 0);
       
    set_skill("force", 50);
    set_skill("bibo-shengong", 40);
    set_skill("unarmed", 50);
    set_skill("luoying-zhang", 40);
    set_skill("dodge", 50);
    set_skill("anying-fuxiang", 50);
    set_skill("parry", 45);
    set_skill("sword", 40);
    set_skill("luoying-shenjian",40);
    set_skill("literate", 40);
    set_skill("qimen-wuxing",40);
   
    map_skill("force"  , "bibo-shengong");
    map_skill("unarmed", "luoying-zhang");
    map_skill("dodge"  , "anying-fuxiang");
    map_skill("sword"  , "luoying-shenjian") ;
       
    create_family("桃花岛", 3, "弟子");

       set("inquiry", ([
           "拜师" : "那你就拜我吧。", 
           "桃花岛" : "那是我派师公的驻地，远在海外。",
            ]) );

    setup();

    carry_object(__DIR__"obj/baipao")->wear();
    carry_object(__DIR__"obj/changjian")->wield();
 }

void init()
{
       object ob;

       ::init();

       if( interactive(ob = this_player()) && !is_fighting() ) {
               remove_call_out("greeting");
               call_out("greeting", 1, ob);
       }
}
void greeting(object ob)
{
       if( !ob || environment(ob) != environment() ) return;
       if((string)ob->query("family/family_name")=="桃花岛")
          { say(WHT "陆冠英笑吟吟地说道：这位" + RANK_D->query_respect(ob)
            + "您辛苦了，快请进吧　。\n" NOR);
            return;
           }
       if(!ob->query("family/family_name"))
          { say(WHT "陆冠英满脸笑容地说道：这位" + RANK_D->query_respect(ob)
            + ",欢迎您到归云庄做客。\n" NOR);
            return;
           }

}

void attempt_apprentice(object ob)
{
     command("say 好吧，我收下你。\n");
     command("recruit "+ob->query("id"));
     command("say 到后堂去休息一下吧。\n");
     return;
}

