#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void consider();

void create()
{
    set_name("西方失败", ({"xifang shibai", "xifang"}));
    set("nickname", HIY "天下无敌" NOR );
    set("gender", "女性");
    set("age", 42);
    set("long",
        "她就是日月神教教主。号称无人可敌，因此有一称号为「西方失败」。\n");
    set("attitude", "peaceful");

    set("str", 31);
    set("int", 10);
    set("con", 26);
    set("dex", 30);

    set("chat_chance", 1);
    set("chat_msg", ({
 "西方失败叹了口气道：“唉 …… 那东方不败是谁呀，你们烦不烦啊！\n",
        }));
    set("inquiry", ([
        "杨莲亭"   : "你敢直称我爱人的名字,想找死呀？ \n",
        "葵花宝典" : "如果你能帮我取得葵花宝典上册，我一定重重谢你。\n",
    ]));

    set("qi", 1000);
    set("max_qi", 1000);
    set("jing", 500);
    set("max_jing", 500);
    set("neili", 500);
    set("max_neili", 500);
    set("jiali", 20);

    set("combat_exp", 250000);
    set("score", 0);

    set_skill("force", 100);             // 基本内功
    set_skill("finger", 100);            // 基本指法
    set_skill("tanzhi-shentong", 100);   // 弹指神通
    set_skill("dodge", 100);             // 基本躲闪
    set_skill("anying-fuxiang", 100);    // 暗影浮香
    set_skill("parry", 100);             // 基本招架
    set_skill("sword", 100);             // 基本剑法
    set_skill("pixie-jian", 80);        // PiXieJian
    set_skill("qimen-wuxing",100);       // 奇门五行
    set_skill("literate",100);           // 读书识字
    set_skill("kuihua-xinfa", 100);       // 葵花心法

    map_skill("force"  , "kuihua-xinfa");
    map_skill("sword", "pixie-jian");
    map_skill("finger" , "tanzhi-shentong");
    map_skill("dodge"  , "anying-fuxiang");
    map_skill("parry"  , "pixie-jian");

    create_family("日月神教", 2, "教主");

    setup();
    carry_object(__DIR__"obj/zhen")->wield();
    carry_object(__DIR__"obj/hongchouxiaoshan")->wear();

}

void attempt_apprentice(object ob)
{
    if (ob->query_int() < 20) {
        command("say 我不收资质差的弟子，您请回吧！\n");
                return;
    }
   
    command("say 很好，很好。\n");
    command("recruit " + ob->query("id"));
}
int recognize_apprentice(object ob)
{
        mapping myfam;
        myfam = (mapping)ob->query("family");
        if ( myfam["family_name"] == "黑木崖") return 1 ;
        if ((int)ob->query_temp("tmark/东") == 1 )
        message_vision("东方不败看了看$N，说道：咱们现在是谁也不欠谁,\n"
                          "你不要再找我学习技艺了。\n", ob);
        if (!(int)ob->query_temp("tmark/东"))
                return 0;
        ob->add_temp("tmark/东", -1);
        return 1;
}



int accept_object(object who, object ob)
{

        if ( (string) ob->query("id") =="kuihua baodian1" ) {
                if (!(int)who->query_temp("tmark/东",)) who->set_temp("tmark/东",100);
                message_vision("东方不败看了看$N送来的秘籍，点了点头，说道：\n"
                               "难得你将宝典送回。你送我的东西我就收下了。\n"
                               "作为补偿,你可以从我这里学点功夫。\n", who);
                who->add_temp("tmark/东", 100);
                return 1;

        }
        return 0;
}