// /u/tiansha/npc/right_killer.c
 
#include <ansi.h>
inherit NPC;
int time_period(int timep,object me);
 
void create()
{
        set("chat_chance", 25);
 
        set_name("右四", ({ "rightkiller" }) );
        set("title", "天杀门右接引使");
        set("gender", "女性" );
        set("age", 28);
        set("str", 26);
        set("int", 24);
        set("cps",30);
        set("long",
                "天杀门右接引使负责承接暗杀的生意。\n");
        set("combat_exp", 200000);
        set("attitude", "heroism");
 
        set("force", 1000);
        set("max_force", 1000);
        set("force_factor", 10);
 
        set_skill("dodge", 100);
        set_skill("unarmed", 100);
        set_skill("whip", 120);
        set_skill("stormdance", 100);
        set_skill("snowwhip", 100);
        map_skill("dodge", "stormdance");
        map_skill("whip", "snowwhip");
 
       set("inquiry", ([  "天杀门": "你敢乱说, 小心姑奶奶宰了你! \n",
        ]) );
 
        setup();
        carry_object("/obj/weapon/whip")->wield();
        carry_object(__DIR__"obj/pink_cloth")->wear();
}
int accept_fight(object me)
{
        command("say 小子！你赶惹天杀门, 不要命了！");
        return 0;
}
 
void init()
{
        add_action("give_quest", "quest");
}
 
int give_quest()
{
        mapping quest ;
        object me;
        int j, combatexp, timep,factor,num;
        string tag = "1000000";
 string *levels = ({
                         "1000",
                        "1500",
                        "2000",
                        "3000",
                        "5000",
                        "8000",
                        "10000",
                        "13000",
                        "17000",
                        "22000",
                        "30000",
                        "45000",
                        "60000",
                        "80000",
                        "100000",
                        "200000"
//                        "350000",
//                        "600000",
//                        "1000000"
        });
        me = this_player();
        combatexp = (int) (me->query("combat_exp"));
 
        if(combatexp<1000)
          {
        message_vision("左三对$N哼了一声道: 这种小角色还想请天杀门, 你也真好意思开口...
.\n",me);
         return 1;
          }
 
// Let's see if this player still carries an un-expired task
        if((quest =  me->query("quest")))
        {
        if( ((int) me->query("task_time")) >  time() )
                return 0;
        else
        {
         message_vision("右四对$N妩媚的一笑道: 想要天杀门出手, 先帮我找样东西。\n", me)
;
         me->set("kee",(int)(me->query("kee")/2+10));
        }
        }
 
        for(j= sizeof(levels) - 1 ; j>=0; j--)
        {
                if( atoi(levels[j])  <= combatexp )
                        {
                      num=j;
                          factor=10;
                          break;
                        }
        }
        if (num>0)
        {
                if (random(50)>45)
                {
                num=num-1;
                }
        } else {
                if ((num<sizeof(levels)-1)&&(random(100)>95))
                {
                num=num+1;
                factor=15;
                }
        }
        tag=levels[num];
        quest = QUEST_D(tag)->query_quest();
        timep = quest["time"];
 
        while (quest["quest_type"] == "杀")
        {
        quest = QUEST_D(tag)->query_quest();
        timep = quest["time"];
        }
 
        time_period(timep, me);
        tell_object(me,"先找回『"+quest["quest"]+"』给我,或许我给你派杀手。\n" NOR);
        quest["exp_bonus"]=quest["exp_bonus"];
        quest["pot_bonus"]=quest["pot_bonus"];
        quest["score"]=quest["score"];
 
        me->set("quest", quest);
        me->set("task_time", (int) time()+(int) quest["time"]);
        me->set("quest_factor",factor);
        return 1;
}
 
int time_period(int timep, object me)
{
        int t, d, h, m, s;
        string time;
        t = timep;
        s = t % 60;             t /= 60;
        m = t % 60;             t /= 60;
        h = t % 24;             t /= 24;
        d = t;
 
        if(d) time = chinese_number(d) + "天";
        else time = "";
 
        if(h) time += chinese_number(h) + "小时";
        if(m) time += chinese_number(m) + "分";
        time += chinese_number(s) + "秒";
 
        tell_object(me,HIW "右四说道：\n在" + time + "内");
        return 1;
}
 
int accept_object(object who, object ob)
{
        int bonus, exp, pot, score,factor;
        string test;
        mapping quest;
 
        if(!(quest =  who->query("quest")))
        {
        tell_object(who,"右四说道：这不是我想要的。\n");
        return 0;
        }
 
        if( ob->name(1) != quest["quest"])
        {
        tell_object(who,"右四说道：这不是我想要的。\n");
        return 0;
        }
 
        if ((int) who->query("task_time") < time() )
        {
        tell_object(who,"右四说道：真可惜！你没有在指定的时间内回来！\n");
        destruct(ob);
        return 0;
        }
 
        else
        {
        tell_object(who,"右四说道：对不起！现在天杀门还不能派杀手！\n");
        exp = quest["exp_bonus"]/2 + random(quest["exp_bonus"]/2);
        pot = quest["pot_bonus"]/2 + random(quest["pot_bonus"]/2);
        score = quest["score"]/2 + random(quest["score"]/2);
        factor=who->query("quest_factor");
        destruct(ob);
 
        if (factor)
        {
                exp=exp*factor/10;
                pot=pot*factor/10;
                score=score*factor/10;
        }
 
        bonus = (int) who->query("combat_exp");
        bonus += exp;
        who->set("combat_exp", bonus);
        bonus = (int) who->query("potential");
        bonus = bonus - (int) who->query("learned_points");
        bonus = bonus + pot;
        if( bonus > 100) bonus = 100;
        bonus += (int) who->query("learned_points");
        who->set("potential", bonus );
        bonus = (int) who->query("score");
        bonus += score;
        who->set("score", bonus);
        tell_object(who,HIW"你被奖励了：\n" + chinese_number(exp)
          + "点实战经验\n"+ chinese_number(pot) + "点潜能\n"
          + chinese_number(score)+"点综合评价\n"NOR);
        who->set("quest", 0 );
        return 0;
        }
     return 0;
}