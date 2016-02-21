#include <ansi.h>

inherit NPC;
inherit F_UNIQUE;

void create()
{
	set_name(HIC "玉骢马" NOR, ({ "yu cong ma","yu","ma"}));
	set("race", "野兽");
	set("gender", "雄性");
	set("age", 2+random(3));
	set("long", "这是一匹玉骢宝马，日行千里，夜行八百。\n"+
		"玩家可以骑上它去任何地方(ride/down)。\n");
	set("int", 30);
	set("qi", 300);
	set("max_qi", 300);
	set("jing", 100);
	set("max_jing", 100);
	set("shen_type", 0);
	set("combat_exp",50000);
	set("attitude", "peaceful");

	set("limbs", ({ "头部", "腹部", "尾巴","后腿","前腿" }) );
	set("verbs", ({ "bite","hoof","knock" }) );
	set_temp("apply/attack", 50);
	set_temp("apply/armor", 15);
	set_temp("apply/damage", 25);

	setup();
}

void init()
{
 add_action("do_ride", "ride");
 add_action("do_go", "go");
 add_action("do_down", "down");
}


int do_ride ( )
{
    string dir,dir2;
    object ob = this_player () ;
    if(ob->query("meili")<20)
    {
      message_vision("$N一跃身跨上了玉骢马。只见白雕仰天长啸，突然猛然一颠......\n"
                     HIR "把$N狠狠摔在了地上,结果$N受了点轻伤。\n" NOR,ob);
      ob -> receive_damage ("qi",50) ;
      ob -> receive_wound  ("qi",50) ;
      remove_call_out("kill_ob");
      call_out("kill_ob", 1, ob);
      return 1;
    }
   if( objectp(query("rider"))) 
   {
    return notify_fail("现在马上已经有人了！\n" ) ;
   }
   else
   {    
   ob->set_temp("onhorse",1);
   this_object()->set("rider",this_player());
   message_vision("$N一跃身跨上了玉骢马。\n" , ob );
   this_object()->set_leader(this_player());
   command("follow "+ob->query("id"));
   write("请输入要去的地名, 示例(go baituo):\n"+
   "baituo: 白陀山\nshaolin: 少林寺\nyangzhou: 扬州城\n"+
   "beijing: 北京城\ntaohua: 桃花岛\nxingxiu: 星宿海\n"+
	"xueshan: 雪山寺\n"+
   "huasan: 华山\nhaigang: 海港\n");
   return 1; 
  }	
}

int do_down()
{
  object ob;
  ob = this_player () ;
  if(!objectp(query("rider"))) return notify_fail("马上没人。\n");
  if(ob->query_temp("onhorse"))
  {
  message_vision("\n$N身行一转，跃下马来，姿态十分优美。\n" , ob );
  delete("rider");
  command("follow none");
  ob->delete_temp("onhorse");
  }
  else 
  switch(random(3))
  {
   case 0: 
   message_vision("\n$N一把把马上的人拉下来，想自己跳上去。\n" , ob );
   command("follow none");
   query("rider")->delete_temp("onhorse");
   delete("rider");
   ob->set_temp("onhorse");
   break;
   case 1: 
   case 2:
   message_vision("\n$N想把马上的人拉下马来,但没有成功。\n" , ob );
   }	  
  return 1;
 }

int do_go ( string arg )
{
   object ob ;
   ob = this_player () ;
   if( !arg || arg=="" )  return notify_fail("你要去哪儿？\n");
   if(!ob->query_temp("onhorse")) return notify_fail("你还没上马。\n");
   if( arg=="baituo" ) 
   {
   message_vision("\n只见$N骑两腿一夹，玉骢马向前急驰而去。\n" , ob );
   ob->move("/d/baituo/damen");
   this_object()->move("/d/baituo/damen");
   message_vision("\n只见$N骑着玉骢马急奔而来。\n" , ob );
   message_vision("\n奔到近前，$N身行一转，跃下马来，姿态十分优美。\n" , ob );
   delete("rider");
   ob->delete_temp("onhorse");
   command("follow none");
    return 1 ;
   }
   if( arg=="xueshan" ) 
   {
   message_vision("\n只见$N骑两腿一夹，玉骢马向前急驰而去。\n" , ob );
   ob->move("/d/xueshan/shenghu") ;
   this_object()->move("/d/xueshan/shenghu");
   message_vision("\n只见$N骑着玉骢马急奔而来。\n" , ob );
   message_vision("\n奔到近前，$N身行一转，跃下马来，姿态十分优美。\n" , ob );
   delete("rider");
   ob->delete_temp("onhorse");
   command("follow none");
    return 1 ;
   }
   if( arg=="taohua" ) 
   {
   message_vision("\n只见$N骑两腿一夹，玉骢马向前急驰而去。\n" , ob );
   ob->move("/d/taohua/dayuan") ;
   this_object()->move("/d/taohua/dayuan");
   message_vision("\n只见$N骑着玉骢马急奔而来。\n" , ob );
   message_vision("\n奔到近前，$N身行一转，跃下马来，姿态十分优美。\n" , ob );
   delete("rider");
   ob->delete_temp("onhorse");
   command("follow none");
    return 1 ;
   }
   if( arg=="huashan" ) 
   {
   message_vision("\n只见$N骑两腿一夹，玉骢马向前急驰而去。\n" , ob );
   ob->move("/d/huashan/path1") ;
   this_object()->move("/d/huashan/path1") ;
   message_vision("\n只见$N骑着玉骢马急奔而来。\n" , ob );
   message_vision("\n奔到近前，$N身行一转，跃下马来，姿态十分优美。\n" , ob );
   ob->delete_temp("onhorse");
   delete("rider");
   command("follow none");
    return 1 ;
   }
   if( arg=="beijing" ) 
   {
   message_vision("\n只见$N骑两腿一夹，玉骢马向前急驰而去。\n" , ob );
   ob->move("/d/city2/tian_anm") ;
   this_object()->move("/d/city2/tian_anm") ;
   message_vision("\n只见$N骑着玉骢马急奔而来。\n" , ob );
   message_vision("\n奔到近前，$N身行一转，跃下马来，姿态十分优美。\n" , ob );
   delete("rider");
   ob->delete_temp("onhorse");
   command("follow none");
    return 1 ;
   }
   if( arg=="xingxiu" ) 
   {
   message_vision("\n只见$N骑两腿一夹，玉骢马向前急驰而去。\n" , ob );
   ob->move("/d/xingxiu/xxroad2") ;
   this_object()->move("/d/xingxiu/xxroad2") ;
   message_vision("\n只见$N骑着玉骢马急奔而来。\n" , ob );
   message_vision("\n奔到近前，$N身行一转，跃下马来，姿态十分优美。\n" , ob );
   delete("rider");
   ob->delete_temp("onhorse");
   command("follow none");
    return 1 ;
   }
   if( arg=="shaolin" ) 
   {
   message_vision("\n只见$N骑两腿一夹，玉骢马向前急驰而去。\n" , ob );
   ob->move("/d/shaolin/shanmen") ;
   this_object()->move("/d/shaolin/shanmen") ;
   message_vision("\n只见$N骑着玉骢马急奔而来。\n" , ob );
   message_vision("\n奔到近前，$N身行一转，跃下马来，姿态十分优美。\n" , ob );
   delete("rider");
   ob->delete_temp("onhorse");
   command("follow none");
    return 1 ;
   }
   if( arg=="yangzhou" ) 
   {
   message_vision("\n只见$N骑两腿一夹，玉骢马向前急驰而去。\n" , ob );
   ob->move("/d/city/guangchang") ;
   this_object()->move("/d/city/guangchang") ;
   message_vision("\n只见$N骑着玉骢马急奔而来。\n" , ob );
   message_vision("\n奔到近前，$N身行一转，跃下马来，姿态十分优美。\n" , ob );
   delete("rider");
   ob->delete_temp("onhorse");
   command("follow none");
    return 1 ;
   }
   if( arg=="haigang" ) 
   {
   message_vision("\n只见$N骑两腿一夹，玉骢马向前急驰而去。\n" , ob );
   ob->move("/d/city2/haigang") ;
   this_object()->move("/d/city2/haigang") ;
   message_vision("\n只见$N骑着玉骢马急奔而来。\n" , ob );
   message_vision("\n奔到近前，$N身行一转，跃下马来，姿态十分优美。\n" , ob );
   delete("rider");
   ob->delete_temp("onhorse");
   command("follow none");
    return 1 ;
   }
   return notify_fail("没有这个地方\n");
}
