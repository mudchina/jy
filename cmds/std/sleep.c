// sleep.c
// littlefish
// last updated 3/16/96

void wakeup(object,object);
void del_sleeped(object);

int main(object me, string arg)
{
        int rnd;
	mapping fam;
	object where = environment(me);
	

        seteuid(getuid());

	if ( (!(fam = me->query("family")) || fam["family_name"] != "丐帮")
             && !(where->query("sleep_room"))
             || (where->query("no_sleep_room")) )
             return notify_fail("这里不是你能睡的地方！\n");
   
	if (me->is_busy())
		return notify_fail("你正忙着呢！\n");

	if( me->is_fighting() )
		return notify_fail("战斗中不能睡觉！\n");
        
	if (where->query("hotel") && !(me->query_temp("rent_paid")))
	{
		message_vision("店小二从门外对$N大叫: 把这里当避难所啊! 先到一楼付钱后再来睡!\n",me);
		return 1;
	}
 
	if (me->query_temp("sleeped"))
		return notify_fail("你刚在三分钟内睡过一觉, 多睡对身体有害无益! \n");

	if (where->query("sleep_room"))
	{
		write("你往床上一躺，开始睡觉。\n");
		write("不一会儿，你就进入了梦乡。\n");
		me->set_temp("block_msg/all",1);
		message_vision("$N一歪身，倒在床上，不一会便鼾声大作，进入了梦乡。\n",me);
            rnd = random((60 - me->query_con()) / 3);
	}
	else { 
		write("你往地下角落一躺，开始睡觉。\n");
		write("不一会儿，你就进入了梦乡。\n");
		me->set_temp("block_msg/all",1);
		message_vision("$N往地下角落屈身一躺，不一会便鼾声大作，做起梦来。\n",me);
            rnd = 10 + random((100 - me->query_con()) / 3);
	}

	where->set("no_fight", 1);
	where->add_temp("sleeping_person", 1);

	me->set("no_get", 1);	
	me->set("no_get_from", 1);	
	
	if (!(where->query("hotel"))) 
		me->set_temp("sleeped",1);
	else
		me->delete_temp("rent_paid");

	me->disable_player("<睡梦中>");

        if ( rnd < 1 ) rnd = 0;
        call_out("wakeup", rnd + 10, me, where);
        
	return 1;
	
}

void wakeup(object me,object where)
{
	me->set("qi",    me->query("eff_qi"));
	me->set("jing",  me->query("eff_jing"));
	me->add("neili", me->query("max_neili")/2 - me->query("neili")/2 );
	me->enable_player();
  
	call_out("del_sleeped", 179, me);

	message_vision("$N一觉醒来，精力充沛地活动了一下筋骨。\n",me);
	me->set_temp("block_msg/all", 0);
	write("你一觉醒来，只觉精力充沛。该活动一下了。\n");

	if (!where->query("sleep_room") && !where->query("hotel"))
		where->delete("no_fight");
     
	where->add_temp("sleeping_person", -1);
	me->delete("no_get");	
	me->delete("no_get_from");	
 
}

void del_sleeped(object me)
{
	if (objectp(me) &&  me->query_temp("sleeped"))
		me->delete_temp("sleeped");
}
