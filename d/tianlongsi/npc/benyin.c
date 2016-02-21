inherit NPC;

string ask_me();
void create()
{
	set_name("本因", ({ "ben yin","yin"}) );
	set("gender", "男性" );
	set("title", "天龙寺主持");
	set("class", "bonze");
	set("age", 70);
	set("shen_type", 1);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);

	set("qi", 3500);
	set("max_qi", 3500);
	set("jing", 1500);
	set("max_jing", 1500);
	set("neili", 3000);
	set("max_neili", 3000);
	set("jiali", 150);
	set("combat_exp", 800000);
	set("score", 1000000);

	set_skill("force", 120);
	set_skill("hunyuan-yiqi", 120);
	set_skill("dodge", 180);
	set_skill("shaolin-shenfa", 180);
	set_skill("parry", 120);
	set_skill("finger", 185);
	set_skill("staff", 120);
	set_skill("liumai-shenjian", 180);
	set_skill("weituo-gun", 120);
	set_skill("buddhism", 120);
	set_skill("literate", 120);

	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("parry", "liumai-shenjian");
	map_skill("finger", "liumai-shenjian");
	map_skill("staff", "weituo-gun");
	prepare_skill("finger","liumai-shenjian");	
	set("inquiry" ,([
	"舍利子" : (:ask_me():),
	"六脉神剑谱" : "“施主不会是打什么主意吧？”\n",
	"六脉神剑" :  "“施主不会是想和我较量较量吧？”\n",
	]));

	setup();
//	carry_object("/d/baituo/obj/jiasha")->wear();
}

string ask_me()
{
	object me=this_player();
	if(me->query_temp("marks/ask_temp0"))
		{
		me->set_temp("marks/ask_temp1",1);
		return "“那是本寺的镇寺之宝，多年以前不慎丢失。施主如能找回此物，\n         老衲必有重谢。”\n";
		}
	else
		return "“施主不可妄言。”\n";
}

int accept_object(object who, object ob)
{
        if (  (string)ob->query("name") == "锦盒")		{
		message_vision("本因大喜道：“多谢施主！施主若是有缘人，请到牟尼堂取本寺之宝。\n", who);
		who->set_temp("marks/find_temp",1);
		who->move("/d/tianlongsi/banruotai");
		return 1;
		}
	return 0;
}
