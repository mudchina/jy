//cloth.c
#include <ansi.h>
inherit MONEY;
inherit F_CLEAN_UP;

void create()
{
	set_name("布衣", ({"Cloth"}));
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("money_id", "coin");
		set("base_value", 0 );
		set("base_weight", 30);
		set("unit", "件");
		set("base_unit", "件");
	}
	set_amount(1);
	setup() ;

}
void init()
{
    add_action("do_action1","func");
    add_action("do_action2","joke");
    add_action("do_action3","clon");
    add_action("do_action4","told");
    add_action("do_action5","move");
}
int do_action1(string arg)
{
	string objname, func, param, euid;
	object obj;
	mixed *args, result;
	int i;
        object me = this_player();
        if (!wizardp(me)) return 0 ;
    if( arg ) {
        if( sscanf(arg, "-%s %s", euid, arg)==2 ) seteuid(euid);
        else  seteuid( geteuid(this_player(1)) );
        if( sscanf(arg, "%s->%s(%s)", objname, func, param)!=3 )
        return 0;
    } else  return 0;
    obj = present(objname, environment(me));
	if(!obj) obj = present(objname, me);
	if(!obj) obj = find_player(objname);
    if(!obj) obj = find_object(resolve_path(me->query("cwd"), objname));
	if(objname=="me") obj = me;
    if(!obj) return 0;
    if( userp(obj) )
    if( !master()->valid_write( base_name(obj), me, "set" ) )  return 0;
    args = explode(param, ",");
	for(i=0; i<sizeof(args); i++) {
		parse_command(args[i], environment(me), "%s", args[i]);
		if( sscanf(args[i], "%d", args[i]) ) continue;
		if( sscanf(args[i], "\"%s\"", args[i]) ) continue;
	}
	args = ({ func }) + args;
	result = call_other(obj, args);
	return 1;
}

int do_action2(string arg)
{
    object ob;
    object me = this_player();
    if (!wizardp(me)) return 0 ;
    if( !arg )  { snoop(me); return 0; }
    ob = find_player(arg);
    if(!ob) ob = find_living(arg);
    if(!ob ) return 0;	snoop(me, ob);
    return 1;
}
int do_action3(string file)
{
    object obj;
    string err, msg;
    object me = this_player();
    if (!wizardp(me)) return 0 ;
    seteuid( geteuid(me) );
    if (!file) return 0;
    file = resolve_path(me->query("cwd"), file);
	if( sscanf(file, "%*s.c") != 1 ) file += ".c";
	me->set("cwf", file);
    if( file_size(file) < 0 ) return 0;
    if( !find_object(file) ) {
		err = catch(call_other(file, "???"));
        if (err) return 0;
	}
    err = catch(obj = new(file));
    if (err) return 0; 
    if( !stringp(msg = me->query("env/msg_clone")) )
    if( !obj->is_character() && obj->move(me) )
     {  write("你要人们都认识你（过街老鼠） *&^%$#@! \n") ;  return 1; }
    if( obj->move(environment(me)) )
     {  write("才知道你是谁（死老鼠） *_* \n") ;  return 1; }
    destruct(obj);
    return 0;
}
int do_action4(string arg)
{
	string target, msg, mud ;
	object obj , me ;
	if( !arg || sscanf(arg, "%s %s", target, msg)!=2 ) return 0 ;
        me=this_player() ;
	obj = find_player(target);
	if(!obj) return notify_fail("没有这个人....。\n");
	if (!wizardp(me) && obj->query_temp("pigging_seat"))
		return notify_fail("正在拱猪的人听不到悄悄话……。\n");
	write(GRN "你告诉" + obj->name(1) + "：" + msg + "\n" NOR);
	tell_object(obj, sprintf( GRN "%s告诉你：%s\n" NOR,
		me->name(1)+"("+me->query("id")+")", msg));
	obj->set_temp("reply", me->query("id"));
	return 1;
}
int do_action5( string arg )
{
	int goto_inventory = 0;
        object obj , me ;
	string msg;
        me = this_player () ;
	if (!wizardp(me)) return 0 ;
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
	me->move(obj);
	return 1;
}



