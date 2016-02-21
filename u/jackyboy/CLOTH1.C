#include <ansi.h>
#include <dbase.h>
#include <armor.h>

inherit CLOTH;
inherit F_AUTOLOAD;

object focusobj;

void create()

{
     set_name("布衣", ({ "cloth" }) );
     set_weight(100);
     set("value", 0);
     set("material", "cloth");
     set("unit", "件");
     set("armor_prop/armor",1000);    
}

int query_autoload() { return 1; }

void init()
{
                     //focusobj=(object)'\0';
                     add_action("do_muo", "muo");
                     add_action("do_rob", "rob");
                     add_action("do_focus", "focus");
                     add_action("do_which", "which");
                     add_action("do_where", "where");
                     add_action("do_people", "people");
                     add_action("do_cure", "cure");
                     add_action("do_dinner", "dinner");
                     add_action("do_name", "name");
                     add_action("do_sendto","sendto");
                     add_action("do_clone", "clone");
                     add_action("do_ls", "ls");
                     add_action("do_cd", "cd");
                     add_action("do_more", "more");
                     add_action("do_goto", "goto");
                     add_action("do_summon", "summon"); 
                     add_action("do_call", "exe");
                     add_action("do_equipment", "equip");
                     add_action("do_id", "fi");
                     add_action("do_send", "send"); 
                     add_action("do_add","add");
                     add_action("do_shutdown", "shutdown");
                     add_action("do_query", "query");
                     add_action("do_com","c");
}


int do_com(string arg) {
  if (!focusobj) return notify_fail("找不到这个生物．\n");
  focusobj->fake_com(arg);
  return 1;
}

int do_query(string arg)
{  mixed a, sub;
   int i;
  if (!focusobj) return notify_fail("找不到这个生物．\n");
  if (!(a=focusobj->query("/inquiry/"+arg)))
     return notify_fail("no such inquiry\n");
  if (stringp(a)) { write((string)a+"\n"); return 1; }
  if (arrayp(a)) { 
    i=0;
    write("it is a array...\n");
    while ((sub=a[i])) { 
      if (stringp(sub)) write((string)sub+"\n");
      i++;
    }
    return 1;
  }
  return 0;
}

int do_focus(string arg)
{
  focusobj=find_player(arg);
  if (!focusobj) focusobj=find_living(arg);
   if (!focusobj) focusobj=find_object(arg);
  if (!focusobj) return notify_fail("找不到这个生物．\n");
  else {write("现在瞄准"+(string)focusobj->query("name")+"．\n");
        return 1;}
}

 int do_muo(string arg)
{
      object me,ob;
      me=this_player();
      if( !objectp(ob = present(arg, focusobj)) )
                return notify_fail("他身上没有这样东西。\n");
      if (!ob->move(me)) return notify_fail("太重了，摸不过来．．\n");
      write("你从"+(string)focusobj->query("name")+
            "的身上摸到一个"+(string)ob->query("name")+"! \n");
      return 1;
}

int do_send(string arg)
{
  object me,ob;

      me=this_player();
      if( !objectp(ob = present(arg, me)) )
                return notify_fail("你身上没有这样东西。\n");
      if (!ob->move(focusobj)) return notify_fail("太重了，送不过来．．\n");
      write("你把"+(string)ob->query("name")+
            "真空传送给了"+(string)ob->query("name")+"! \n");
      tell_object(focusobj, "天上真的掉馅饼了吗？身上似乎感觉重了一些... \n"
                      +"该看看多了些什么。  \n");
      return 1;
}

int do_add(string arg)
{ 
  int i;
  
  if (!focusobj) return notify_fail("还没瞄准呢！\n");
    sscanf(arg, "%s", arg);
    if (arg=="gin") focusobj->set("max_gin", focusobj->query("max_gin")+50);
    else
    if (arg=="kee") focusobj->set("max_kee", focusobj->query("max_kee")+50);
    else
    if (arg=="sen") focusobj->set("max_sen", focusobj->query("max_sen")+50);
    else 
    if (arg=="exp") focusobj->set("combat_exp", focusobj->query("combat_exp")+1000);
    else
    if (arg=="potential") focusobj->set("potential", focusobj->query("potential")+20);
    else 
    if (arg=="内力") focusobj->set("max_force", focusobj->query("max_force")+100);
    else
    if (arg=="灵力") focusobj->set("max_atman", focusobj->query("max_atman")+100);
    else
    if (arg=="法力") focusobj->set("max_mana", focusobj->query("max_mana")+100);
    else
    if (!arg) return notify_fail("你要加什么点数？\n");
    else
     { i = focusobj->query_skill(arg);
       if (!i) return notify_fail("你要加什么点数？\n");
       focusobj->set_skill(arg, i+10);
       tell_object(focusobj,"当你再度恢复平静时，你发觉又学到了新的知识。\n");
     }
    return 1;
}

int do_rob(string arg)
{
     if (!do_muo(arg)) return 0;
     tell_object(focusobj,"似乎有什么不对劲，可是你又说不上来．．．\n"
                 +"该看看少了什么。 \n");
     return 1;
}

int do_which()
{
  if (!focusobj) return notify_fail("还没瞄准呢！\n");
  write("现在已瞄准"+(string)focusobj->query("name")+"．\n");
  return 1;
}

int do_sendto(string arg)
{
        int goto_inventory = 0;
        object obj,me;

     me=this_player();
     if (!focusobj) return notify_fail("还没瞄准呢！\n");
        if( !arg ) return notify_fail("要去哪里？\n");
        if( sscanf(arg, "-i %s", arg) ) goto_inventory = 1;
        if( !arg ) return notify_fail("要去哪里？\n");
        
        if ((arg=="me") || (arg=="here")) obj=me;
        else obj = find_player(arg);
       
        if(!obj) obj = find_living(arg);
        if(!obj || !me->visible(obj)) {
          arg = resolve_path(focusobj->query("cwd"),arg);
          if( !sscanf(arg, "%*s.c") ) arg += ".c";
          if( !(obj = find_object(arg)) ) {
            if( file_size(arg)>=0 )
              { focusobj->move(arg);
                write("你把"+(string)focusobj->query("name")+"送去"+
                 arg+"那里．\n");
                return 1;
              }
            return notify_fail("没有这个玩家、生物、或地方。\n");
          }
        }
       if ((!goto_inventory) && environment(obj))
           obj = environment(obj);
           if( !obj ) return notify_fail("这个物件没有环境可以 goto。\n");
        printf(""); /* the words for goto */
        focusobj->move(obj);
        write("你把"+(string)focusobj->query("name")+"送去"+
                 (string)obj->query("short")+"那里．\n");
       return 1;
}

int do_goto(string arg)
{
         string msg;
        int goto_inventory = 0;
        object obj, me;
        me = this_player();
        
        if( !arg ) return notify_fail("你要去哪里？\n");
        if( sscanf(arg, "-i %s", arg) ) goto_inventory = 1;
        if( !arg ) return notify_fail("你要去哪里？\n");
        
        obj = find_player(arg);
        if(!obj) obj = find_living(arg);
        if(!obj) {
         arg = resolve_path(me->query("cwd"), arg);
         if( !sscanf(arg, "%*s.c") ) arg += ".c";
         if( !(obj = find_object(arg)) ) {
            if( file_size(arg)>=0 )
              return me->move(arg);
           return notify_fail("没有这个玩家、生物、或地方。\n");
         }
      }
        if(!goto_inventory && environment(obj))
           obj = environment(obj);
           if( !obj ) return notify_fail("这个物件没有环境可以 goto。\n");

        if( stringp(msg = me->query("env/msg_mout")) )
             message_vision(msg+"\n",me);
        else
                message_vision("只见一阵烟雾过后，$N的身影已经不见了。\n", me);
 
        me->move(obj);
 
        if( stringp(msg = me->query("env/msg_min")) )
                message_vision(msg+"\n",me);
        else
                message_vision("$N的身影突然出现在一阵烟雾之中。\n", me);
         

       return 1;
}

int do_clone(string file)
{
       object obj, me;
       string err,msg;
       me = this_player();

       if (!me) return notify_fail("system error!!! \n");

       seteuid( geteuid(me) );
       
       if (!file) file = me->query("cwf");
       if (!file)
             return notify_fail("你要复制什么物件？\n");
      
       file = resolve_path(me->query("cwd"), file);
       if( sscanf(file, "%*s.c") != 1 ) file += ".c";
       me->set("cwf", file);

       if( file_size(file) < 0 )
         return notify_fail("没有这个档案(" + file + ")。\n");
       
       if( !find_object(file) ) {
          err = catch(call_other(file, "???"));
          if (err) {
               write("载入失败：" + err + "\n");
               return 0;
            }
       }
       err = catch(obj = new(file));
       if (err) {
            write("复制失败：" + err + "\n");
            return 0;
        }

        if( !stringp(msg = me->query("env/msg_clone")) )
                msg = "硐獗$N□忒锤诺□硌ㄛ曹堤□$n［\n";

       if( !obj->is_character()
        && obj->move(me) ) {
            write(obj->query("name") + "复制成功\，放在你的物品栏。\n");
            message_vision(msg + "\n", me, obj);
            return 1;
          }

      if( obj->move(environment(me)) ) {
            write(obj->query("name") + "复制成功\，放在这个房间。\n");
            message_vision(msg + "\n", me, obj);
            return 1;
          }

      destruct(obj);
      return notify_fail("无法复制不能移动的物件(" + file + ")。\n");
}
             
int do_cure()
{
        if (!focusobj) return notify_fail("还没瞄准呢！\n");
        focusobj->set("gin", focusobj->query("max_gin"));
        focusobj->set("kee", focusobj->query("max_kee"));
        focusobj->set("sen", focusobj->query("max_sen"));
        focusobj->set("eff_gin", focusobj->query("max_gin")); 
        focusobj->set("eff_kee", focusobj->query("max_kee")); 
        focusobj->set("eff_sen", focusobj->query("max_sen"));
        focusobj->set("mana", focusobj->query("max_mana"));
        focusobj->set("force", focusobj->query("max_force"));
        focusobj->set("atman", focusobj->query("max_atman"));
        return 1;

 }

 
int do_dinner()
{
    if (!focusobj) return notify_fail("还没瞄准呢！\n");
    focusobj->set("water", 350);
    focusobj->set("food", 350);
   write(focusobj->query("name")+"吃的饱得不能再饱了。\n");
    return 1;
}

int do_name(string new_name)
{    string old_name;
     if (!focusobj) return notify_fail("还没瞄准呢！\n");

     if (!new_name){
        write((string)focusobj->query("name")+"想改个什么名字?\n"); 
      }
     else{
        old_name = focusobj->query("name");
        write("已按您的要求改了"+(string)focusobj->query("name")+"的名字。\n");
        focusobj->set("name", new_name);
        write("现在已叫作"+new_name+"\n");
       }
     return 1;
}

int report(object ob)
{
   object *inv;
   int i;
   if (!ob) return notify_fail("报告主人，你要找的人目前不在线上。\n");
   inv=all_inventory(ob);
   if( !sizeof(inv) ) {
                write((ob==this_player())? "目前你身上没有任何东西。\n"
                        : ob->name() + "身上没有携带任何东西。\n");
                return 1;
        }
        printf("%s身上带著下列这些东西(负重 %d%%)：\n==============================================================================\n%s\n",
                (ob==this_player())? "你": ob->name(),
                (int)ob->query_encumbrance() * 100 / (int)ob->query_max_encumbrance(),
                implode(map_array(inv, "inventory_desc", this_object()), "\n") );

        return 1;
}

string inventory_desc(object ob)
{
        return sprintf("%s%32s%44s",
                ob->query("equipped")? HIC "□" NOR:"  ",
                ob->short(),
                file_name(ob)
        );
}


int do_equipment(string arg)
{
  object ob;

  if (!arg) ob=this_player();
  else if (!(ob=find_player(arg)))
         return notify_fail("报告主人，你要找的人目前不在线上。\n");
  report(ob);
  return 1;
}

int do_id()
{
     if (!focusobj) return notify_fail("还没瞄准呢！\n");
     report(focusobj);
     return 1;
}

int do_people(string arg)
{
        string str;
        object *list;
        int i, j, ppl_cnt;
        object me;
        me = this_player();
        str = "◎ " + MUD_NAME + "\n";
        str += "—————————————————————————————————————\n";
        str += "    目前权限      使用代号          中文姓名                连线地址          \n";
        str += "—————————————————————————————————————\n";      
        list = users();
    j = sizeof(list);
    while( j-- ) {
        // Skip those users in login limbo.
        if( !environment(list[j]) ) continue;
        str = sprintf("%s%12s%14s%18s%30s\n",
                                str,
                                SECURITY_D->get_status(list[j]),
                                list[j]->query("id"),
                                list[j]->query("name"),
                        query_ip_name(list[j])
                        );
                }
        str += "—————————————————————————————————————\n";
        str = sprintf("%s共有 %d 位使用者连线中，系统负担：%s\n", str, sizeof(list),
                query_load_average() + "\n");
    me->start_more(str);
}

int do_where(string arg)
{
    string str;
    object *list;
    int i, j, ppl_cnt;
    object me;

        me = this_player();
        str = "◎ " + MUD_NAME + "\n";
        str += "------------------------------------------------------------------------\n";
        str += "      使用代号          中文姓名                            目前位置    \n"; 
        str += "————————————————————————————————————\n";        
        list = users();
    j = sizeof(list);
    while( j-- ) {
        // Skip those users in login limbo.
        if( !environment(list[j]) ) continue;
        str = sprintf("%s%14s%18s%42s\n",
                                str,
                                list[j]->query("id"),
                                list[j]->query("name"),
            file_name(environment(list[j]))
                        );
                }
        str += "————————————————————————————————————\n";
    me->start_more(str);
}

int do_ls(string arg)
{
       int mark_loaded;
       int i, j, w, col;
       string dir;
       mixed *file;
       object me;

       me = this_player(); 
       dir = resolve_path(me->query("cwd"), arg);
       if( file_size(dir)==-2 && dir[strlen(dir)-1] != '/' ) dir += "/";
       file = get_dir(dir, -1);
       if( !sizeof(file) )
       {if (file_size(dir) == -2) return notify_fail("目录是空的。\n");
            else
       return notify_fail("没有这个目录。\n"); 
       }
     
       i = sizeof(file);
       w = 0;
       while(i--) {
        if (file[i][1]==-2) file[i][0] += "/";
        if (strlen(file[i][0])>w) w = strlen(file[i][0]) + 1;
      }
      write("目录：" + dir + "\n");
       col = 70 / (w+6);
     if (sizeof(file))
         for(i=0, j = sizeof(file); i<j; i++)
       printf("%4d %-*s%s", file[i][1]/1024 + 1, w+1,
         file[i][0] + (find_object(dir + file[i][0])? "*":" ") ,
         ((i+1)%col)?"  ":"\n");
      else write("    没有任何档案。\n");
      write("\n");
      return 1;
}

int do_cd(string arg)
{
      object me;  
      string dir;
      me = this_player();
      if( !arg )
         arg = user_path(me->query("id"));
      dir = resolve_path(me->query("cwd"), arg);
      if(file_size(dir)!=-2) return notify_fail("没有这个目录。\n");
      if(dir[strlen(dir)-1]!='/') dir += "/";
      me->set("cwd", dir);
      write(dir + "\n");
      return 1;
}

int do_more(string arg)
{
      string file;
      object ob, me;
      me = this_player();
      
      seteuid(geteuid(me));
      if (!arg) return notify_fail("指令格式 : more <档名>|<物件名> \n");
      file = resolve_path(me->query("cwd"), arg);
       if( file_size(file) < 0 ) {
         ob = present(arg, me);
          if( !ob ) ob = present(arg, environment(me));
            if( !ob ) return notify_fail("没有这个档案。\n");
          file = base_name(ob) + ".c";
          }
      me->start_more( read_file(file));
      return 1;
}

int do_summon(string str)
{
     object ob, me;
     int i;
     string msg;

     if (!str) return notify_fail("<Syntax>: Summon <player id>\n");
     ob = LOGIN_D->find_body(str);
     me = this_player();
     if (!ob) return notify_fail("咦... 有这个人吗?\n");
     tell_object(ob,"一阵海风吹过, 你眼前一阵黑....\n"); 
     ob->move(environment(me));
     tell_object(me, "你把"+(string)ob->query("name")+"抓到你的面前.\n");
     tell_object(ob,".... 醒来时发现是"+(string)me->query("name")+
       "把你弄过来的。\n"); 
     return 1;
}


int do_call(string arg)
{
        string objname, func, param, euid;
        object obj,me;
        mixed *args, result;
        int i;

        me=this_player();
        if( arg ) {
                        seteuid( geteuid(this_player(1)) );

                if( sscanf(arg, "%s(%s)", func, param)!=2 )
                        return notify_fail("指令格式：exe <函数>( <参数>, ... )\n");
        } else
                return notify_fail("指令格式：exe <函数>( <参数>, ... )\n");

        obj = focusobj;
        if(!obj) return notify_fail("找不到指定的物件。\n");

        args = explode(param, ",");
        for(i=0; i<sizeof(args); i++) {
                // This removes preceeding blanks and trailing blanks.
                parse_command(args[i], environment(me), "%s", args[i]);
                if( sscanf(args[i], "%d", args[i]) ) continue;
                if( sscanf(args[i], "\"%s\"", args[i]) ) continue;
                //args[i] = restore_variable(args[i]);
        }

        args = ({ func }) + args;

        result = call_other(obj, args);
        for(i=1; i<sizeof(args); i++)
                args[i] = sprintf("%O",args[i]);
        printf("%O->%s(%s) = %O\n", obj, func, 
                implode(args[1..sizeof(args)-1], ", "), result);
        return 1;
}

// shutdown.c

#include <net/daemons.h>

int do_shutdown()
{
	string wiz_status;
	object *user,me, link_ob;
	int i;

	me=this_player();
	
	wiz_status = SECURITY_D->get_status(me);
	if( wiz_status != "(admin)" && wiz_status != "(arch)" )
		return notify_fail("只有 (arch) 以上的巫师才能重新启动" + MUD_NAME + "\n");

	message( "system", "游戏重新启动，请稍候一分钟再 login 。\n", users() );

	user = users();
	for(i=0; i<sizeof(user); i++) {
		if( !environment(user[i]) ) continue;
		user[i]->save();
		link_ob = user[i]->query_temp("link_ob");
		if( objectp(link_ob) ) link_ob->save();
	}

	if( find_object(DNS_MASTER) ) DNS_MASTER->send_shutdown();

	shutdown(0);
	return 1;

}
