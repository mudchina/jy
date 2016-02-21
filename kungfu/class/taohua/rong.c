// rong.c 黄蓉

inherit NPC;
inherit F_MASTER;

string ask_chicken();

void create()
{
    set_name("黄蓉", ({"huang rong", "huang", "rong"}));
    set("title", "桃花岛主独生爱女");
    set("gender", "女性");
    set("age", 18);
    set("long", 
        "这是桃花岛主的独生女儿。由于岛主夫人早死，岛主对这个女儿备加疼爱。\n"
        "她生性跳脱飞扬，喜欢四处乱跑。\n");

    set("attitude", "peaceful");
       
    set("str", 18);
    set("int", 30);
    set("con", 21);
    set("dex", 26);

    set("qi", 800);
    set("max_qi", 800);
    set("jing", 1000);
    set("max_jing", 1000);
    set("neili", 1000);
    set("max_neili", 1000);
    set("jiali", 0);
       
    set("combat_exp", 200000);
    set("score", 0);
       
    set_skill("force", 60);
    set_skill("bibo-shengong", 80);
    set_skill("unarmed", 80);
    set_skill("luoying-zhang", 80);
    set_skill("dodge", 150);
    set_skill("anying-fuxiang", 100);
    set_skill("parry", 85);
    set_skill("sword", 80);
    set_skill("luoying-shenjian",80);
    set_skill("qimen-wuxing",80);
       
    map_skill("force"  , "bibo-shengong");
    map_skill("unarmed", "luoying-zhang");
    map_skill("dodge"  , "anying-fuxiang");
    map_skill("sword"  , "luoying-shenjian") ;
       
    create_family("桃花岛", 2, "弟子");

       set("inquiry", ([
               "叫化鸡" : (: ask_chicken :)
       ]) );

    setup();
    carry_object(__DIR__"obj/ruanwei")->wear();
    carry_object(__DIR__"obj/shudai")->wear();

 }void init()
{
       object ob;
       mapping myfam;
        
       ::init();
       add_action("do_kiss", "kiss");
       if (interactive(ob = this_player()) && !is_fighting()) {
               myfam = (mapping)ob->query("family");
               if ((!myfam || myfam["family_name"] != "桃花岛") &&
                       (!wizardp(ob)))
               {
                       remove_call_out("saying");
                       call_out("saying",2,ob);
               }
       }
}
int do_kiss ( string arg )
{
   object ob ;
   ob = this_player () ;
   if( !arg || arg!="rong" )
     return 0;
   
   if ( (string) ob -> query ("gender") == "男性" )
      command ("say 救命啊！救命啊！"+ ob->query("name") + "要非礼我！\n") ;
   else
      message_vision("\n黄蓉对$N笑道：“好姐姐不要这样，我怕痒！”\n", ob);
   return 1 ;
}

void saying(object ob)
{
    if (!ob || environment(ob) != environment())
        return;
    if ((string)ob->query("gender") == "男性")
        message_vision("\n黄蓉面现惊奇之色，打量了$N一眼，说到：“你是什么人，"
        "竟敢乱闯我的闺房？\n再不滚出去，看我怎么整你！”\n", ob);
    else
        message_vision("\n黄蓉看了看$N，说到：“好久没生人来过了，"
        "不知这位姐姐可有我靖哥哥的消息？\n", ob);
}

void attempt_apprentice(object ob)
{
    command("say 我年纪这么小就收徒弟，岂不让人笑掉大牙！");
}

string ask_chicken()
{
       if (this_player()->query_temp("marks/鸡", 1))
               return "你这个人怎么这么烦？老说车轱辘话！\n";
       else
       {
               say("蓉儿神往地说：叫化鸡可是杭州著名特产，我爹当年费了好大的劲才搞到了制作\n"
                       "它的秘方。你问它来干什么？\n");
               this_player()->set_temp("marks/鸡", 1);
               return "你可以出去了。\n";
       }
}

