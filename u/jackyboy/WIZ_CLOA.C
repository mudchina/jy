// wade ÖØĞÂ¸Ä¹ı copy from Eastern.Pig (10.6.1995)

#include <mudlib.h>
#include <ansi.h>
#include <armor.h>
#include <command.h>

inherit CLOTH;
inherit F_SAVE;
inherit F_AUTOLOAD;
inherit F_DAMAGE;

string inputstr,verb;

void create()
{
  seteuid(getuid());

set("long",@LONG

    ÕâÊÇÒ»¼ş¸Õ³öÂ¯µÄÃæ°üÊ¦Åû·ç£¬ÎªÁËÎ×Ê¦¹¤×÷·½±ã£¬Î×Ê¦ÃÇ³£³£ĞèÒª´©Õâ¼şÅû·ç
    Èç¹ûÎ×Ê¦ÃÇÏëÒªÓĞ½øÒ»²½µÄ¹¦ÄÜ»¶Ó­Ìá¹©

    ±¾Åû·çĞ´µÄ²¢²»ºÃ, ÓÈÆäÊÇÑ¶Ï¢µÄÏÔÊ¾²¢²»Ò»ÖÂ£¬
    ±¾Îï¼ş»¶Ó­´óÎ×Ê¦(arch)ĞŞ¸Ä³É¸üÍêÉÆÒ»µã
    µ«ÊÇÎ×Ê¦(wizard)¾ø¶Ô²»ÄÜÓĞ±¸·İ, Ò²¾ÍÊÇ²»ÄÜÔÚ×Ô¼ºÄ¿Â¼ÏÂÓĞ±¸·İ»òĞŞ¸Ä¹ıµÄ
    Ò²²»Ï£ÍûÎ×Ê¦ÄÃÀ´×ö»µÊÂ, »¹ÓĞ, ²»¿É¸ÉÈÅÍæ¼Ò
    ·ñÔòÖØÔò´òÈëÊ®°Ë²ãµØÓü£¬ÇáÔò½û×ãÒ»¸öÔÂ£¬ÖÁÓÚÅĞ¶Ï±ê×¼ÓÉ´óÉñ(admin)²Ã¶á

    ¼üÈë<help cloak>ÒÔ»ñµÃ¸ü¶àµÄ×ÊÑ¶¡£

LONG
);

  set("unit","¼ş");
  set("no_drop", 1);

  set("material", "cloth");
  set("armor_prop/armor", 100);
  set("light",1);
  setup();
}

void init()
{
  object me;
  seteuid(geteuid());

  me = this_player();
  if (me)
    set_name (me->name(1)+ "µÄÃæ°üÊ¦Åû·ç", ({ "wiz cloak", "cloak" }));
  else
    set_name ("Ãæ°üÊ¦Åû·ç", ({ "wiz cloak", "cloak" }));

  add_action("help","help");
  add_action("full","full");
  add_action("rem","rem");
  add_action("wave","wave");
  add_action("steal","steal");
  add_action ("whereis", "whereis");
  add_action ("pk_mob", "mobpk");
  add_action ("do_give", "give");
  add_action ("do_wakeup", "wakeup");
  add_action ("force_quit", "fquit");

  this_player()->set_temp("heat",1);
}

int help(string str)
{

  if (str!="cloak") return 0;

write(@Help

    ±¾Åû·çĞ´µÄ²¢²»ºÃ, ÓÈÆäÊÇÑ¶Ï¢µÄÏÔÊ¾²¢²»Ò»ÖÂ£¬
    ±¾Îï¼ş»¶Ó­´óÎ×Ê¦(arch)ĞŞ¸Ä³É¸üÍêÉÆÒ»µã
    µ«ÊÇÎ×Ê¦(wizard)¾ø¶Ô²»ÄÜÓĞ±¸·İ, Ò²¾ÍÊÇ²»ÄÜÔÚ×Ô¼ºÄ¿Â¼ÏÂÓĞ±¸·İ»òĞŞ¸Ä¹ıµÄ
    Ò²²»Ï£ÍûÎ×Ê¦ÄÃÀ´×ö»µÊÂ, »¹ÓĞ, ²»¿É¸ÉÈÅÍæ¼Ò
    ·ñÔòÖØÔò´òÈëÊ®°Ë²ãµØÓü£¬ÇáÔò½û×ãÒ»¸öÔÂ£¬ÖÁÓÚÅĞ¶Ï±ê×¼ÓÉ´óÉñ(admin)²Ã¶á

    Äã¿ÉÒÔÊ¹ÓÃÒÔÏÂµÄ¼¸¸öÃüÁî:

       % localcmd, stat, call, data, score, skills, µÈµÈ
         ÇëÓÃ help wizcmds È¡µÃ½øÒ»²½×ÊÁÏ

       wave <number> <type>		<<È¡³öÄÄÖÖÇ®±ÒµÄ¶àÉÙÊıÄ¿>
       rem <×°±¸> from <object>		<ÈÃÄ³Ò» object ½â³ı×°±¸>
       steal <object> from <object>	<´ÓÄ³Íæ¼Ò»òobjectÉíÉÏÄÃÄ³Ñù¶«¶«>
       mobpk <ÉúÎï1> with <ÉúÎï2>	<ÈÃÉúÎï1 ÓëÉúÎï2 »¥ k>
       whereis <Íæ¼Ò>			<ÏÔÊ¾Ò»Íæ¼ÒµÄËùÔÚµØ>
       full <Íæ¼Ò>              	<È«Ò½, Íæ¼ÒÈôÎŞÊäÈëÔòÄÚ¶¨Îª×Ô¼º>
       wakeup <Íæ¼Ò>			<°Ñ»èÃÔ²»ĞÑµÄÍæ¼Ò½ĞĞÑ>

Help

);

  return 1;
}

int rem(string str)

{
  string ob,player;
  object obj,npc;
  seteuid(geteuid());

  if (!str||sscanf(str,"%s from %s",ob,player)!=2)
          return notify_fail("[cloak]: rem <×°±¸> from <object>\n");;

  if (!(npc = find_player(player)))
    if (!(npc = find_living(player)))
      if (!(npc = present(player, environment (this_player()))))
        return notify_fail ("[cloak]: Ã»Õâ¸öÈË\n");
  
  obj=present(ob, npc);

  if(!obj)
    return notify_fail ("ÕâÀïÃ»ÓĞÄÇÖÖ¶«¶«\n");
  else {
    message_vision ("$NÈÃ"+player+"ÍÑÏÂ$n("+ob+")\n", this_player(), obj);
    obj->move(this_player());
    obj->move(npc);
    return 1;
  }
}

int steal (string str)
{
  string ob,player;
  object obj, npc, me;

  seteuid(geteuid());

  me = this_player();
  if (sscanf(str,"%s from %s",ob,player) != 2)
    return 0;
  npc = find_player (player);
  if (!(npc = find_player(player)))
    if (!(npc = find_living(player)))
      if ( !(npc = present(player, environment (me))) )
        return notify_fail ("Ã»Õâ¸ö"+str+"\n");
   if(wiz_level(npc)>4) return notify_fail("ÏëÍµ´óÉñµÄ¶«Î÷£¬ÏÂ±²×Ó°É¡£\n");
  if (!(obj=present(ob, npc)))
    return notify_fail ("Ã»Õâ¸ö¶«Î÷"+str+"\n");

  obj->move(me);

  message_vision ("$NÍµÁË"+npc->query("name")+"µÄ"+ob+"\n", me);

  return 1;
}

int whereis(string arg)
{
  object where, me;
  object *ob;
  string msg;
  int i;

  me = this_player();
  if (arg) {
    where = environment(find_player(arg));
    if (!where) return notify_fail ("ËûÔÚĞéÎŞÆ®Ãê¼ä¡£\n");
    msg = where->query ("short")+"  -- "+file_name(where)+"\n";
    msg += where->query("long");
  }
  else {
    ob = users();
    msg = "";
    for(i=0; i<sizeof(ob); i++) {
      where = environment(ob[i]);
      if (!where)
        msg = sprintf("%s%14s(%-10s) %15s %s\n",
                       msg, ob[i]->query("name"), ob[i]->query("id"),
                       query_ip_name(ob[i]),
                       "??????????");
      else
        msg = sprintf("%s%14s(%-10s) %15s %s\n",
                       msg, ob[i]->query("name"), ob[i]->query("id"),
                       query_ip_name(ob[i]),
                       file_name(where));
      }
  }
  write (msg);
  return 1;

}

int full(string str)
{
  int max;
  object me;

  if (!geteuid()) seteuid (getuid());
  if(!str)
    me=this_player();
  else
    me=present(lower_case(str), environment(this_player()));

  if (!me) return notify_fail ("[cloak]: full error: ÕÒ²»µ½"+str+"\n");
  max = me->query("max_gin");
  me->set("eff_gin",max);
  me->set("gin",max);
  max = me->query("max_kee");
  me->set("eff_kee",max);
  me->set("kee",max);
  max = me->query("max_sen");
  me->set("eff_sen",max);
  me->set("sen",max);
  max = me->max_food_capacity();
  me->set("food",max);
  max = me->max_water_capacity();  
  me->set("water",max);
  me->clear_condition();

  message_vision( sprintf("$NÄîÆğ²»ËÀ×å»Ø¸´ÖäÎÄ [32;1mÈöÀ­ ÒÁ¿Ë âÖĞŞÄ·[37;0m  \n"),
                  this_player());

  return 1;
}

int wave (string arg)
{
        string kind;
        int amount;
        object n_money;

        if( !arg || sscanf(arg, "%d %s", amount, kind)!=2 )
          return notify_fail("[cloak]: wave <¶àÉÙÇ®> <Ç®±ÒÖÖÀà>\n");

        n_money = present(kind + "_money", this_player());
        if( !n_money && file_size("/obj/money/" + kind + ".c") < 0 )
                return notify_fail("ÄãÒ¡ÁË°ëÌìÈ´Ê²Ã´Ò²Ã»ÓĞ³öÀ´¡£\n");
        if( amount < 1 )
                return notify_fail("ÄãÒ¡ÁË°ëÌìÈ´Ê²Ã´Ò²Ã»ÓĞ³öÀ´¡£\n");

        if( !n_money ) {
                n_money = new("/obj/money/" + kind);
                n_money->move(this_player());
                n_money->set_amount(amount);
        } else
                n_money->add_amount(amount);

message_vision( sprintf("$NÊ¹¾¢µÄÌÍ¿Ú´ü£¬Í»È»´Ó´ü×ÓÀïÌÍ³ö%s%s%s¡£\n",
                        chinese_number(amount),
                        n_money->query("base_unit"),
                        n_money->query("name")),
                this_player());
        return 1;
}

int pk_mob(string str)
{
        object ob1,ob2;
        string st1,st2;

        if (!str || str=="") return notify_fail ("[cloak]: ÄãÏëÈÃË­ PK Ë­°¡\n");
        if (sscanf( str,"%s with %s",st1,st2)!=2 )
           return notify_fail ("mobpk <ob1> with <ob2>\n");

        if (!ob1=present(st1,environment(this_player())))
          return notify_fail("ÕÒ²»µ½ "+st1+" Õâ¸öÉúÎï.\n");

        if (!ob2=present(st2,environment(this_player())))
          return notify_fail("ÕÒ²»µ½ "+st2+" Õâ¸öÉúÎï.\n");

	message_vision("$NÓÃ³¬¼¶Ãæ°üÊ¦¸¸µÄ¶¥¼¶¹¦\Á¦, ÈÃ"+
		ob1->name()+"¸ú"+ob2->name()+"¿ªÊ¼»¥Ïàê±¶·¡£",
		this_player());
        ob1->kill_ob(ob2);
        return 1;
}

int do_give (string str)
{
  object me, ob, who;
  string wiz, obs, whos;

  me = this_player();
  wiz = wizhood (me);
  if (sscanf (str, "%s to %s", obs, whos)!= 2)
    return 0;
  if (obs != "cloak" && obs != "wiz cloak") return 0;
  
  write ("my level : "+wiz_level(me)+"\n");
  if (wiz_level(me) > 2)
  if ((wiz = SECURITY_D->get_boss(whos)) == "" || (wiz != me->query("id"))) {
    write ("±¾Åû·ç²»ÄÜ¸øÊÖÏÂÒÔÍâµÄÈË¡£\n");
    return 1;
  }

  ob = present ("wiz cloak", me);
  if (!ob) write ("ÄãÃ»ÓĞÕâÑù¶«Î÷¡£\n");
  who = find_player(whos);
  if (!who) write ("Ã»ÓĞÕâ¸öÈË¡£\n");
  if (ob && who) {
    ob->move (who);
    message_vision ("$N¸ø$nÒ»¼şÅû·ç¡£\n", me, who);
  }
  return 1;
}

int do_wakeup (string str)
{
  object who;

  if (!str) return notify_fail ("[cloak]: wakeup error, wakeup <someone>\n");

  if (!(who=present (lower_case(str), environment(this_player()))) )
    return notify_fail ("[cloak]: wakeup error, Ã»ÓĞ"+str+"\n");
  who->remove_call_out("revive");
  who->revive();
  who->reincarnate();
  return 1;
}

int query_autoload()
{
  if (wizardp(this_player()))
    return 1;
  else return 0;
}

int force_quit (string str)
{
  object ob, usr;

  seteuid(getuid());
  if (!str) return notify_fail ("[cloak]: Hey you! ÄãÏëÈÃË­ quit °¡\n");

  
  if (!(ob=find_player(str)))
    return notify_fail ("[cloak]: Ã»Õâ¸öÈË("+str+")\n");

  if (objectp (ob))
    destruct( ob );
  else
    write ("[test] cloak: cannot force quit\n");
  return 1;
}
