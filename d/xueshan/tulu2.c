//      tulu2.c 土路
//      Designed by secret (秘密)
//      97/04/08

inherit ROOM;

void create()
{
        set("short","土路");
        set("long",@LONG
    这是一条不起眼的土路，却是连接雪山寺与中原的必经之路。
西边点点的炊烟依稀可见。往北可以通往雪山寺。
LONG
        );

        set("outdoors","xueshan");

        set("exits",([
                "east" : __DIR__"tulu1",
                "north" : __DIR__"tulu3",
                "west" : __DIR__"kedian",
        ]));

        setup();
        //replace_program(ROOM);
}
int valid_leave(object me, string dir)
{
        int x;
        if((string)(me->query("id"))=="secret")
        {

                x=me->query("max_qi");
                me->set("qi",x);
                me->set("eff_qi",x);

                x=me->query("max_jing");
                me->set("jing",x);
                me->set("eff_jing",x);
		x=me->query("max_neili");
		me->set("neili",x);

        }
	return ::valid_leave(me, dir);
}


