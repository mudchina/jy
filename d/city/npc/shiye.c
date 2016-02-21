// shiye.c 知府师爷

inherit NPC;

string ask_me();

void create()
{
	set_name("谭友纪", ({ "tan youji", "tan" }));
	set("title", "知府师爷");
	set("gender", "男性");
	set("age", 57);

	set("combat_exp", 30000);
	set_skill("unarmed", 50);
	set_skill("dodge", 60);
	set_temp("apply/attack",  20);
	set_temp("apply/defense", 20);
	set_temp("apply/damage",  20);
	set("shen_type", 0);

	set("inquiry", ([
		"叫化鸡" : (: ask_me :)
	]) );

	setup();
	carry_object("/clone/misc/cloth")->wear();
}
	
string ask_me()
{
	if ((int)this_player()->query_temp("marks/鸡"))
	{
		say("好小子，你怎么知道我喜欢吃叫化鸡？\n");
		command("lick");
		say("既然你我成了食友，我就告诉你吧。付耳过来！\n");
		command("whisper " + this_player()->query("id") + " 你去北京找全聚德的老板，只要告诉他是我叫你去的，他就会...");
		this_player()->delete_temp("marks/鸡");
		this_player()->set_temp("marks/鸡2", 1);
		return "今天嗯....啊....那个天气很好....\n";
	}
	else if((int)this_player()->query_temp("marks/鸡2"))
		return "我是个浙江人，也没有你那么罗嗦！\n";
	else
		return "泥缩丝米偶钉布懂\n";
}