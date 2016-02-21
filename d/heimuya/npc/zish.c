inherit NPC;
 
void create()
{
        set_name("×ÏÉÀÊÌÕß", ({ "zishan shizhe","shizhe","zhe" }) );
        set("gender", "ÄĞĞÔ" );
        set("age",18);
        set("class", "hemuya");
        set("combat_exp", 1000);
        set_skill("unarmed", 50);
        set_skill("dodge", 70);
        set_skill("force",100);
        set("force",300);
        set("max_force",300);

        setup();
	carry_object(__DIR__"obj/zichoush")->wear();
}
