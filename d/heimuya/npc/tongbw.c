//tonbaixiong.c
inherit NPC;
inherit F_MASTER;
inherit F_UNIQUE;

void greeting(object);
void init();
void create()
{
	set_name("童百熊", ({ "tongbai xiong","xiong"}) );
	set("gender", "男性" );
	set("age", 45);
	set("long", "他白发披散, 银髯戟张, 脸上的肌肉牵动, \n"
                    "圆睁双眼, 身上的鲜血已然凝结, 神情甚是可怖。\n");
	set("attitude", "friendly");
	set("shen_type", 1);

	set("str", 23);
	set("int", 23);
	set("con", 22);
	set("dex", 20);

	set("max_qi", 1000);
	set("max_jing",1000);
	set("neili", 300);
	set("max_neili", 300);
	set("combat_exp", 350000);
	set("score", 30000);

	set_skill("force", 100);
	set_skill("dodge", 90);
	set_skill("unarmed", 100);
	set_skill("parry", 80);
	set_skill("hammer",100);
	set_skill("blade",100);
	set_skill("taiji-shengong",70);
	set_skill("tiyunzong", 80);
	set_skill("taiji-dao", 100);

	map_skill("force", "taiji-shengong");
	map_skill("dodge", "tiyunzong");

	map_skill("parry", "taiji-dao");
	map_skill("blade", "taiji-dao");


	create_family("日月神教",2,"弟子 风雷堂长老");

	set("chat_chance", 3);
	set("chat_msg", ({
		 "童百熊怒瞪双眼道: “我没错, 我没有叛教! 东方兄弟你不能冤枉我呀! ”\n",
	         "童百熊叹了一口气说：“我和东方兄弟出生入死, 共历患难的时候, 你们还没生下来哪!”\n"
          }) );
	setup();
         carry_object(__DIR__"obj/zijinchui")->wield();
         carry_object(__DIR__"obj/cloth")->wear();
         carry_object(__DIR__"obj/card1")->wear();

}



void attempt_apprentice(object ob)
{
     command("say 我是患难之身, 怎么能收徒呢。壮士还是请回吧!\n");
  }

