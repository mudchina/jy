// go.c

inherit F_CLEAN_UP;

mapping default_dirs = ([
	"north":		"北",
	"south":		"南",
	"east":			"东",
	"west":			"西",
	"northup":		"北边",
	"southup":		"南边",
	"eastup":		"东边",
	"westup":		"西边",
	"northdown":	"北边",
	"southdown":	"南边",
	"eastdown":		"东边",
	"westdown":		"西边",
	"northeast":	"东北",
	"northwest":	"西北",
	"southeast":	"东南",
	"southwest":	"西南",
	"up":			"上",
	"down":			"下",
	"enter":		"里",
	"out":			"外",
]);

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	string dest, mout, min, dir;
	object env, obj;
	mapping exit;
	object *f_obs, *ob;
	int count = 0, my_dex, i;

	if( !arg ) return notify_fail("你要往哪个方向走？\n");

	if( me->over_encumbranced() )
		return notify_fail("你的负荷过重，动弹不得。\n");

	if( me->is_busy() )
		return notify_fail("你的动作还没有完成，不能移动。\n");
	if (me->is_fighting()) {
		f_obs = me->query_enemy();
		if (objectp(f_obs[0]))
		if (5 + random((int)me->query("dex")) <= 
			random((int)f_obs[0]->query("dex"))) {
			me->start_busy(1);
//added by King
			message_vision("$N见势不好，转身要走，被$n一把拦在面前。想走？没那么容易！\n", me, f_obs[0]);
//end of appendence

			return notify_fail("你逃跑失败。\n");
		}
	}

	env = environment(me);
	if(!env) return notify_fail("你哪里也去不了。\n");

	if( !mapp(exit = env->query("exits")) || undefinedp(exit[arg]) ) {
		if( query_verb()=="go")
			return notify_fail("这个方向没有出路。\n");
		else
			return 0;
	}

	dest = exit[arg];

	if( !(obj = find_object(dest)) )
		call_other(dest, "???");
	if( !(obj = find_object(dest)) )
		return notify_fail("无法移动。\n");

// Added by Hop
	ob = all_inventory(obj);
	for(i=0; i<sizeof(ob); i++)
		if( living(ob[i]) && ob[i] != me )
			count++;
	my_dex = (int)me->query_dex();
	if(!objectp(present("zhu xi", environment(me)))
        &&!objectp(present("wind", environment(me)))
        &&!objectp(present("peter", environment(me)))) 
//暂时用判断是否有这几个npc来确定是否是先贤祠；
	if(((my_dex < 15) && (count > 6))
	|| ((my_dex < 20) && (count > 8))
	|| ((my_dex < 30) && (count > 10))
	|| ((my_dex < 40) && (count > 12)))
		return notify_fail("前面人太多了，你怎么挤也挤不过去。\n");
// End of appendence	
 
	if( !env->valid_leave(me, arg) ) return 0;

	if( !undefinedp(default_dirs[arg]) )
		dir = default_dirs[arg];
	else
		dir = arg;

	if( me->is_fighting() ) {
		mout = me->name() + "往" + dir + "落荒而逃了。\n";
		min = me->name() + "跌跌撞撞地跑了过来，模样有些狼狈。\n";
	}
	else {
		if(me->query("gender") == "女性"){
			mout = "一条倩影往" + dir + "离开。\n";
			min = "一条倩影走了过来。\n";
		}
		else{
			mout = "一条人影往" + dir + "离开。\n";
			min = "一条人影走了过来。\n";
		}
	}

	message( "vision", mout, environment(me), ({me}) );
	if( me->move(obj) ) {
		me->remove_all_enemy();
		message( "vision", min, environment(me), ({me}) );
		me->set_temp("pending", 0);
		all_inventory(env)->follow_me(me, arg);
		return 1;
	}

	return 0;
}

void do_flee(object me)
{
	mapping exits;
	string *directions;

	if( !environment(me) || !living(me) ) return;
	exits = environment(me)->query("exits");
	if( !mapp(exits) || !sizeof(exits) ) return;
	directions = keys(exits);
	tell_object(me, "看来该找机会逃跑了...\n");
	main(me, directions[random(sizeof(directions))]);
}

int help(object me)
{
	write(@HELP
指令格式 : go <方向>
 
让你往指定的方向移动。
 
HELP
    );
    return 1;
}
