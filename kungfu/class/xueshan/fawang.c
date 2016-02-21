//
// /kungfu/class/xueshan/fawang.c  金轮法王
// by secret

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("金轮法王", ({ "jinlun fawang", "fawang" }));
        set("long",@LONG
他是雪山寺的护教法王。在雪山寺的地位仅次与掌门人鸠摩智。
身穿一件紫红袈裟，头带僧帽。
LONG
        );
        set("title", HIY "法王" NOR);
        set("gender", "男性");
        set("age", 50);
        set("attitude", "peaceful");
        set("shen_type", -1);
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);
        set("max_qi", 5000);
        set("max_jing", 5000);
        set("neili", 4500);
        set("max_neili", 4500);
        set("jiali", 100);
        set("combat_exp", 1500000);
        set("score", 200000);

        set_skill("force", 150);
        set_skill("xiaowuxiang", 150);
        set_skill("dodge", 150);
        set_skill("shenkong-xing", 120);
        set_skill("unarmed", 120);
        set_skill("yujiamu-quan", 100);
        set_skill("parry", 120);
        set_skill("sword", 100);
        set_skill("mingwang-jian", 100);
        set_skill("mizong-xinfa", 150);
        set_skill("literate", 80);
        set_skill("hammer", 150);
        set_skill("riyue-lun", 150 );


        map_skill("force", "xiaowuxiang");
        map_skill("dodge", "shenkong-xing");
        map_skill("unarmed", "yujiamu-quan");
        map_skill("parry", "riyue-lun");
        map_skill("sword", "mingwang-jian");
        map_skill("hammer", "riyue-lun");

        create_family("雪山寺", 2, "护教法王");
        set("class", "bonze");

        setup();
        carry_object("/d/xueshan/obj/jinlun")->wield();
        carry_object("/d/xueshan/obj/p-jiasha")->wear();
        carry_object("/d/xueshan/obj/sengmao")->wear();
        add_money("gold",50);
}

void attempt_apprentice(object ob)
{

        if ((string)ob->query("gender") != "男性") {
                command("say 修习密宗内功需要纯阳之体。");
                command("say 这位" + RANK_D->query_respect(ob) +
                        "还是请回吧！");
                return;
        }

        if ((string)ob->query("class") != "bonze") {
                command("say 我佛门的清规戒律甚多。");
                command("say 这位" + RANK_D->query_respect(ob) +
                        "还是请回吧！");
                return;
        }

        if ((string)ob->query("family/family_name") != "雪山寺")        {
                command("say 这位" + RANK_D->query_respect(ob) +
                        "既非本寺弟子，还是请回吧！");
                return;
                  }

        if ((int)ob->query_skill("mizong-xinfa", 1) < 80) {
                command("say 入我雪山寺，修习密宗心法是首要的。");
                command("say 这位" + RANK_D->query_respect(ob) +
                        "是否还应该多多钻研本门的心法？");
                return;
        }

        command("smile");
        command("nod");
        command("say 你就随我学习佛法吧！");
        command("recruit " + ob->query("id"));

        ob->set("title", HIY"活佛"NOR);
}
