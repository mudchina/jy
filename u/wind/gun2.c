// gun.c

#include <ansi.h>
#include <weapon.h>

inherit BLADE;
inherit F_CLEAN_UP;

void init()
{
        add_action("do_aim","aim");
        add_action("do_fire","fire");
}

void create()
{
        set_name("迷你机关枪", ({ "qiang", "gun" }) );

        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("bullet", 10000);
		set("value", 0);
                set("material", "steel");
                set("long", "这是一把阿诺用过的迷你机关枪。\n");
                set("wield_msg", "$N端出一把$n，取出一箱子弹扛在肩上。\n");
                set("unequip_msg", "$N放下手中$n，取下子弹箱。\n");
        }
        init_blade(100);
        setup();
}

int do_aim(string arg)
{
        object me, obj;

        me = this_player();

        if( !arg )
                return notify_fail("你想杀谁？\n");

        if(!objectp(obj = present(arg, environment(me))))
                return notify_fail("这里没有这个人。\n");
        if( !obj->is_character() || obj->is_corpse() )
                return notify_fail("看清楚一点，那并不是活物。\n");

        if(obj == me)
                return notify_fail("用 suicide 指令会比较快:P。\n");
        message_vision(HIY "\n$N举起迷你机关枪，远远地瞄准$n，接着「克」地一声，把子弹上膛。 \n\n"NOR, 
                       me, obj);

        message_vision(HIR "\n$N对准$n扣动了扳机！！！\n只听「哒哒」地一阵巨响，$n被打得想蜂窝一样，慢慢地倒在血泊中。\n\n"NOR,
                       me, obj);

        tell_object(obj, HIR "\n你猛觉浑身如火烧般剧痛，神志迷困，头脑中一片空白！\n" NOR);

        obj->die();

        return 1;
}

int do_fire()
{
        object me;
        object* obj;
        string arg;
        int i;

        me = this_player();
        obj = all_inventory(environment(me));

        for(i=0; i<sizeof(obj); i++) {

         if( obj[i]==me ) continue;

         if( !obj[i]->is_character() || obj[i]->is_corpse() ) continue;

         message_vision(HIR "\n$N对准$n扣动了扳机！！！\n只听「哒哒」地一阵巨响，$n被打得想蜂窝一样，慢慢地倒在血泊中。\n\n"NOR,
                        me, obj[i]);

        tell_object(obj[i], HIR"\n你觉得浑身如火烧般剧痛，眼前一阵金星乱冒，头脑中一片空白。 \n"NOR);
     	if ( wizardp(obj[i]) ) { 
		obj[i]->set("env/immortal",0);
         	obj[i]->die();
		obj[i]->set("env/immortal",1);
	}
	else obj[i]->die();
               
        }

        return 1;
}



