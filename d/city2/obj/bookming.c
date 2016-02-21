
inherit ITEM;

void init()
{
        add_action("do_shake", "doudong");
        add_action("do_shake", "twitter");
}

void create()
{
        set_name("明史辑略", ({"book ming","book","ming"}));
        set_weight(1500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一本厚厚的书。\n");
                set("unit", "本");
                set("material", "paper");
        }
        setup();
}


int do_shake(string arg)
{
	object me,goldleaf1,goldleaf2;
	me = this_player();

        if( !arg || arg=="" ) return 0;
        if( arg=="book"||arg=="ming"||arg=="ming book") 
	{
                if(!me->query_temp("gotgold"))
		{
		message("vision","突然，几片金叶从书中掉了出来。\n",environment(me));
                goldleaf1 = new("/d/city2/obj/goldleaf");
                goldleaf1->move(environment(me));
                goldleaf2 = new("/d/city2/obj/goldleaf");
                goldleaf2->move(environment(me));
                me->set_temp("gotgold",1);
                }
		else message("vision","不管怎么抖，再没金叶了。\n",environment(me));
	return 1;
	}
}	





