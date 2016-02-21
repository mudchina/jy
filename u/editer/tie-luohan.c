/* tie-luohan.c */

inherit NPC;
inherit F_CLEAN_UP;

void create()
{
        set_name("铁罗汉", ({ "tie luohan", "tie", "luohan" }) );
        set("gender", "男性" );
        set("age", 35);
        set("long", "这是一个铁制的罗汉，是明教为了弟子们练功特意打制的。\n");
        set("attitude", "heroism");

        set("str", 25);        
        set("cor", 25);
        set("cps", 25);
        set("int", 25);

        set("max_qi", 300);
        set("qi", 300);
        set("max_jing", 100);
        set("jing", 100);
        set("force", 300);
        set("max_force", 300);
        set("force_factor", 10);
        set("shen_type", 0);

        set("combat_exp", 70000);

        set_skill("force", 30); 
        set_skill("unarmed", 30);
        set_skill("dodge", 30);
        set_skill("parry", 30);

        set("fight_times", 0);
        setup();
        
}

int accept_fight(object ob)
{
        object me;
        mapping hp_status, skill_status, map_status, prepare_status;
        string *sname, *mname, *pname;
        int i, temp;


        if (is_fighting()) return 0;

        if (me->query("damaged"))
                return notify_fail("这个铁罗汉已经无法使用了！\n");

        if (random(me->query("fight_times")) >= 10) {
                me->set("damaged", 1);
                return notify_fail("这个铁罗汉已经无法使用了！\n");
        }

        if (me->query("last_fighter") == ob->query("id"))
                 return 1;
             return  notify_fail("你练了很久了，休息一下吧！\n");

        me->set("last_fighter", ob->query("id"));
        me->add("fight_times", 1);

        remove_call_out("renewing");
        call_out("renewing", 300 + random(300), me);
/* delete and copy skills */

        if ( mapp(skill_status = me->query_skills()) ) {

                for(i=0; i<temp; i++) {
                        me->delete_skill(snamei);
                }
        }

        if ( mapp(skill_status = ob->query_skills()) ) {

                for(i=0; i<sizeof(skill_status); i++) {
                        me->set_skill(snamei, skill_statussname);
                }
        }
        
/* delete and copy skill maps */
        if ( mapp(map_status = me->query_skill_map()) ) {


                for(i=0; i<temp; i++) {
                        me->map_skill(mnamei);
                }
        }

        if ( mapp(map_status = ob->query_skill_map()) ) {

                for(i=0; i<sizeof(map_status); i++) {
                        me->map_skill(mnamei, map_statusmname);
                }
        }
        
/* delete and copy skill prepares */

        if ( mapp(prepare_status = me->query_skill_prepare()) ) {
                for(i=0; i<temp; i++) {
                        me->prepare_skill(pnamei);
                }
        }

        if ( mapp(prepare_status = ob->query_skill_prepare()) ) {

                for(i=0; i<sizeof(prepare_status); i++) {
                        me->prepare_skill(pnamei, prepare_statuspname);
                }
        }
        

                me->set("str", hp_statusstr);
                me->set("int", hp_statusint);
                me->set("con", hp_statuscon);
                me->set("cps", hp_statuscps);

                me->set("max_kee",    hp_statusmax_kee);
                me->set("eff_kee",    hp_statuseff_kee);
                me->set("kee",        hp_statuskee);
                me->set("max_gin",  hp_statusmax_gin);
                me->set("eff_gin",  hp_statuseff_gin);
                me->set("gin",      hp_statusgin);
                me->set("max_force", hp_statusmax_force);
                me->set("force",     hp_statusforce);
                me->set("force_factor",     hp_statusforce_factor);
                me->set("combat_exp",hp_statuscombat_exp);

        return 1;
}

void renewing(object me)
{
        me->delete("last_fighter");
}
