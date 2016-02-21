#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void consider();

void create()
{
    set_name("东方不败", ({"dongfang bubai", "dongfang", "dong"}));
    set("nickname", HIY "天下无敌" NOR );
    set("gender", "男性");
    set("age", 42);
    set("long",
        "他就是日月神教教主。号称无人可敌，因此有一称号为「东方不败」。\n");
    set("attitude", "peaceful");

    set("str", 21);
    set("int", 30);
    set("con", 26);
    set("dex", 30);

    set("chat_chance", 1);
    set("chat_msg", ({
 "东方不败叹了口气道：“唉 …… 我的杨大哥....他怎么还不回来,我好\n"
 "挂念他 ……东方不败眼中流露无限迷茫。\n",
        }));
    set("inquiry", ([
        "杨莲亭"   : "你敢直称我爱人的名字,想找死呀？ \n",
        "葵花宝典" : "如果你能帮我取得葵花宝典上册，我一定重重谢你。\n",
    ]));

    set("qi", 4000);
    set("max_qi", 4000);
    set("jing", 1000);
    set("max_jing", 1000);
    set("neili", 3500);
    set("max_neili", 3500);
    set("jiali", 100);

    set("combat_exp", 2500000);
    set("score", 0);

    set_skill("force", 150);             // 基本内功
    set_skill("bibo-shengong", 150);     // 碧波神功
    set_skill("finger", 170);            // 基本指法
    set_skill("tanzhi-shentong", 170);   // 弹指神通
    set_skill("unarmed", 120);           // 基本拳脚
    set_skill("dodge", 150);        // 基本躲闪
    set_skill("anying-fuxiang", 120);    // 暗影浮香
    set_skill("parry", 150);             // 基本招架
    set_skill("sword", 200);             // 基本剑法
    set_skill("pixie-jian", 200);        // PiXieJian
    set_skill("qimen-wuxing",150);       // 奇门五行
    set_skill("literate",150);           // 读书识字
    set_skill("kuihua-xinfa", 150);       // 葵花心法

    map_skill("force"  , "kuihua-xinfa");
    map_skill("sword", "pixie-jian");
    map_skill("finger" , "tanzhi-shentong");
    map_skill("unarmed", "luoying-zhang");
    map_skill("dodge"  , "anying-fuxiang");
    map_skill("parry"  , "luoying-shenjian");

    create_family("日月神教", 2, "教主");

    setup();
    carry_object(__DIR__"obj/yuxiao")->wield();
    carry_object(__DIR__"obj/cloth")->wear();

}

void attempt_apprentice(object ob)
{
    if (ob->query_int() < 30) {
        command("say 我不收资质差的弟子，您请回吧！\n");
                return;
    }
    if (ob->query("gender") !="无性" ) {
        command("say 要练神功，必须自宫。");
              return;
    }
    if ((int)ob->query("shen") >100000 || (int)ob->query ("shen") < -100000 ) {
        command("say 我黑木崖与世隔绝，向来不与您这种成名人物打交道，您请回吧！;\n");
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