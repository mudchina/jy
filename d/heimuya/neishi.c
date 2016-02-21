//ROOM neishi.c
inherit ROOM;
void init();
int do_move(string);
void create()
{
        set("short", "日月神教后厅");
        set("long",
             "这里是日月神教的后厅。看上去满是灰尘,但中间有一个碗(wan),似乎有古怪.。\n"
        );
        set("exits", ([
                "east" : __DIR__"huayuan",
        ]));

       set("item_desc", ([
            "wan" : 这是一个自汉代流传下的古董,很别致。\n"
        ]));
        setup();
}
void init()
{
        add_action("do_circle", "circle");
}

int do_circle(string arg)
{

        object me = this_player();
        object room;

        if ((arg != "wan") || !arg)
          return notify_fail("你要旋什么？\n");
        if((int)me->query("str") < 20)
          return notify_fail("你旋不动它！\n");
        if(!( room = find_object(__DIR__"midao")) )
           room = load_object(__DIR__"midao");
        if(!objectp(room))  return notify_fail("ERROR:not found 'midao.c' \n");
        if (!query("exits/down"))
          {
          set("exits/down", __DIR__"midao");
          message_vision("$N将碗旋开，只见侧墙打开,露出一个黑幽幽
              的洞口。\n",me);
          room->set("exits/up", __FILE__);
        return notify_fail("你旋不动它！\n");
        if(!( room = find_object(__DIR__"midao")) )
           room = load_object(__DIR__"midao");
        if(!objectp(room))  return notify_fail("ERROR:not found 'midao.c' \n");
        if (!query("exits/down"))
          {
          set("exits/down", __DIR__"midao");
          message_vision("$N旋动了碗，只见侧墙打开,露出一个黑幽幽
              的洞口。\n",me);
          room->set("exits/up", __FILE__);
          message("vision", "外面传来一阵搬动碗的声音，一束光线射了进来。
          \n", room);
          }
         else
          {
          delete("exits/down");
          message_vision("很快碗又搬回了原位。侧墙上的洞口又被封住了。\n",me);
          room->delete("exits/up");
          message("vision", "外面传来一阵搬动碗的声音，洞口被封住了。\n", roo;
          }
       return 1;
}