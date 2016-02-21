
inherit NPC;
void greeting(object ob);
string inquiry_map();

void create()
{
        set_name("欧阳锋", ({ "ouyang feng", "ouyang", "feng" }));
        set("long", "他是白驼山庄主，号称“西毒”的欧阳锋。\n"
                   +"由于习练「九阴真经」走火入魔，已变得精\n"
                   +"神错乱，整日披头散发，衣冠不整。\n");
        set("title", "老毒物");
        set("gender", "男性");
        set("age", 53);
        set("nickname","西毒");
 
        set("attitude", "peaceful");
 
        set("str", 30);
        set("int", 24);
        set("con", 30);
        set("dex", 24);
 
        set("qi", 500);
        set("max_qi", 500);
        set("jing", 300);
        set("str", 30);
        set("int", 24);
        set("con", 30);
        set("dex", 24);
 
        set("qi", 500);
        set("max_qi", 500);
        set("jing", 300);
        set("max_jing", 300);
        set("neili", 1500);
        set("max_neili", 1500);
        set("jiali", 50);
 
        set("combat_exp", 1500000);
        set("score", 200000);
        set_skill("force", 200);
        create_family("白驼山派",1, "开山祖师");

   // other set needed for future use.
        set("class", "taoist");
        set("inquiry", ([
        "地图": (: inquiry_map :),
        ]));

        setup();
}
 
void init()
{
        object ob;
 
        ::init();
 
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}
void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch(random(3)) {
        case 0:write("你是谁？我要杀了你！哈￣哈￣哈￣")
                break;
        case 1:write("谁说我疯了！我没疯￣");
                break;
        }
}
string inquiry_map()
{
	object ob;
	object me=this-player();
	if((string)me->query("family/family_name")!="白驼山派")
		return "我岂能把秘密告诉外帮弟子。你以为我真的啥都不知道了吗？哈￣";
	else
	{
		if(me->query("combat_exp")<=10)
			return "哼！你刚拜完师就问这问那，难道想当家贼？小心我宰了你！";
    message_vision("欧阳锋微微一笑，凑近$N的耳根，小声嘀咕起来。",me);
    command("tell "+(string)me->query("id")+
              "这是从走出沙漠的正确通路，你要听仔细。东。。");
    command("smile");
    return "记住了吧。";
   }
}
/*string inquiry_map()
{
 object ob,room=enviroment();
 object me=this-player();

 if((string)me->query("family/family_name")!="白头山派")
   return "我岂能把秘密告诉外帮弟子。你以为我真的啥都不知道了吗？哈￣";
 else
  {
    if(me->query("combat_exp")==0)
     return "哼！你刚拜完师就问这问那，难道想当家贼？小心我宰了你！";
    if(!objectp(present("key",enviroment(me))))
        return "我没有什么key哇！";
    if(present("key",me))
        return "你小子怎么贪得无厌！";
    if(me->query("combat_exp")<1500)
        return "等你的实战经验再高些，为师的再告诉你。";
    ob=new(__DIR__"../obj/key");
    ob->move(room);
    return "这是后门的key,你拿去吧。";
   }
} */



