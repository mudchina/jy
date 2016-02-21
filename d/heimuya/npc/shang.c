//shang.c
inherit NPC;
inherit F_MASTER;
inherit F_UNIQUE;

void greeting(object);
void init();
void create()
{
	set_name("桑三娘", ({ "shang"}) );
	set("gender", "女性" );
	set("age", 45);
	set("long", "身情古怪，面无丝毫微笑，由胜似母夜叉。 \n"
                    );
	set("attitude", "friendly");
	set("shen_type", 1);

	set("str", 23);
	set("int", 23);
	set("con", 22);
	set("dex", 29);

	set("max_qi", 1000);
	set("max_jing",1000);
	set("neili", 300);
	set("max_neili", 300);
	set("combat_exp", 350000);
	set("score", 30000);
	set("jiali",50);
	set_skill("force", 140);
	set_skill("dodge", 130);
	set_skill("unarmed", 100);
	set_skill("parry", 80);
	set_skill("hammer",100);
	set_skill("taiji-shengong",70);
	set_skill("tiyunzong", 80);
	set_skill("taiji-jian", 100);

	map_skill("force", "taiji-shengong");
	map_skill("dodge", "tiyunzong");
	
	map_skill("parry", "taiji-jian");
	map_skill("blade", "taiji-jian");


	create_family("日月神教",2,"弟子 天香堂长老");

	set("chat_chance", 3);
	setup();
         carry_object(__DIR__"obj/changjian")->wield();
         carry_object(__DIR__"obj/cloth")->wear();
      

}



