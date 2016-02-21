#include <ansi.h>

inherit ITEM;

void create()
{
   set_name("清心散", ({"qingxin san", "san"}));
   if (clonep())
      set_default_object(__FILE__);
   else {
      set("unit", "包");
      set("value", 1000);
   }
   setup();
}

int init()
{
   add_action("do_eat", "eat");
}

int do_eat(string arg)
{
   object me = this_player();

   if(!id(arg))
       return notify_fail("你要吃什么？\n");

   message_vision("$N吃下一包" + name() + "。\n", me);
   if ((int)me->query_condition("xx_poison") > 0) {
    if ((int)me->query_condition("xx_poison") < 11) {
      me->apply_condition("xx_poison", 0);
      message_vision("$N身上的毒气尽退，脸色看上去好多了。\n", me); }
   else {
   me->apply_condition("xx_poison", (int)me->query_condition("xx_poison") -10);
      message_vision("$N的脸色渐渐红润起来。\n", me);
   }
  }
    else tell_object(me, "你觉得浑身无比清爽。\n" NOR );

   destruct(this_object());
   return 1;
}
