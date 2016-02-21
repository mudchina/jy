 
// objmaker.c created by Hunter(秋风) 
// for ESLib 
 
#define RMK_VERSION "(v1.0)" 
 
inherit ITEM; 
inherit F_AUTOLOAD; 
 
string *special_props = ({ 
        "name", "long" }); 
 
int save_room_file(string file,string str); 
 
void create() 
{ 
        set_name("物件编辑器" + RMK_VERSION, ({ "objmaker", "maker" }) ); 
        set_weight(100); 
        set("unit", "个" ); 
        set("long", @LONG 
这是一个用来「快速」制造房间的工具，帮助时间不多或有严重  lag 的巫师 
利用线上输入制造简单的房间，不过如果你想提高自己区域房间的品质，最好 
不要太依赖这个东西，你可以使用以下几个指令： 
 
mkobj <物件档名> 
 
    造出一个「废物」放在身上，之後你可以 rrset 设定物件的    叙述或 
属性。 
 
rset1 <物件属性> <属性内容> 
 
    设定你身上的临时物件属性，如 name(not short!)，long,id 等 set 内 
有引号的set 。 
 
 
saveobj 
 
    将你身上的临时物件存档为正式物件。 
 
rset2 <物件属性> <属性内容> 
        设定那些 set 内没有引号的属性，如 no_drop,no_get,value等。 
LONG 
        ); 
} 
 
int query_autoload() { return 1; } 
 
void init() 
{ 
        if( wizardp(environment()) ) { 
                seteuid(getuid(environment())); 
                add_action("do_mkobj", "mkobj"); 
                add_action("do_rset", "rset1"); 
                add_action("do_saveobj", "saveobj"); 
                add_action("do_rrset","rset2"); 
        } 
} 
 
int do_mkobj(string arg) 
{ 
        string file,code; 
        object file1; 
 
        if( sscanf(arg, "%s", file)!=1 ) 
return notify_fail("指令格式：mkobj <物件档名>\n"); 
        seteuid(geteuid(this_player())); 
        file = resolve_path(this_player()->query("cwd"), file) + ".c"; 
        if( file_size(file)!=-1 ) 
                return notify_fail("档案 " + file + " 已经存在了。\n"); 
        if( !write_file(file ,@OBJ_CODE 
// This is a obj made by objmaker. 
 
inherit ITEM; 
 
void create() 
{ 
       set_name("无用物", ({ "obj" }) ); 
        set("long", "这是一个不值钱的废物。\n"); 
        setup(); 
} 
 
OBJ_CODE 
        ) ) return notify_fail("你没有写入档案(" + file +")的权利。\n"); 
        file1=new(file); 
        file1->move(this_player()); 
        message_vision("只听到$N的物件编辑器「哔」的一声，你觉得身上多了一件东西。\n", this_player()); 
        return 1; 
} 
 
int do_rset(string arg) 
{ 
        string prop, str; 
        object ob; 
        mixed data; 
 
        if( !arg || sscanf(arg, "%s %s", prop, str)!=2 ) 
                return notify_fail("指令格式：rset1 <物件属性> <属性内容>\n"); 
 
        if( sscanf(str, "%d", data)!=1 ) 
                data = str; 
        ob=present("obj",this_player()); 
        ob->set(prop,str); 
//      environment(this_player())->set(prop, str); 
        write("Ok.\n"); 
        return 1; 
} 
 
int do_rrset(string arg) 
{ 
        string prop; 
        object ob; 
        mixed str; 
 
        if( !arg || sscanf(arg, "%s %d", prop, str)!=2 ) 
                return notify_fail("指令格式：rset2 <物件属性> <属性内容>\n"); 
 
/*      if( sscanf(str, "%d", data)!=1 ) 
                data = str;*/ 
        ob=present("obj",this_player()); 
        ob->set(prop,str); 
//      environment(this_player())->set(prop, str); 
        write("Ok.\n"); 
        return 1; 
} 
 
int do_saveobj(string arg) 
{ 
        object env; 
        string str, *name1, file1,file; 
        mapping prop; 
        int i,age1; 
        env = present("obj",this_player()); 
        file1 = file_name(env) + ".c"; 
        if( !arg || sscanf(arg, "%d",age1)!=1 ) 
                return notify_fail("指令格式：saveobj <重量>\n"); 
        str = "// Obj: "+file1 +  @OBJ_CODE 
 
 
inherit ITEM; 
 
void create() 
{ 
OBJ_CODE 
        ; 
        str += sprintf("\tset_name(\"%s\", ({\"%s\"}));\n", env->query("name"),env->query("id")); 
        str += sprintf("\tset(\"long\", @LONG\n%s\nLONG\n\t);\n", env->query("long") ); 
        prop = env->query_entire_dbase(); 
        name1 = keys(prop); 
        for(i=0; i<sizeof(name1); i++) { 
                if( member_array(name1[i], special_props)!=-1 ) continue; 
                str += sprintf("\tset(\"%s\", %O);\n", name1[i], prop[name1[i]] ); 
        } 
        str += sprintf("\tset_weight(%O);\n",age1); 
        str += "\n\tsetup();\n}\n"; 
 
        // Replace current directory with __DIR__ macro to make relocatable code. 
/*      if( file_size(file)!=-1 ) { 
                write("档案 " + file + " 已存在，要删除旧档吗？[y/n]"); 
                input_to("save_room_file",file,str); 
                return 1; 
        }*/ 
 
//      return save_room_file("y",file,str); 
        write("请输入新档名: "); 
        input_to("save_room_file",str); 
        return 1; 
} 
 
int save_room_file(string file,string str) 
{ 
        object ob; 
        file = resolve_path(this_player()->query("cwd"), file) + ".c"; 
 
//      if( wizardp(environment()) ) { 
        ob=present("obj",this_player()); 
//              seteuid(getuid(environment())); 
                seteuid(getuid(ob)); 
 
//      if( strlen(yn)<1 || yn[0]!='y' ) return 1; 
        rm(file); 
        printf(str); 
        write("存档 " + file + "...."); 
        if( write_file(file, str) ) { 
                write("Ok.\n"); 
                return 1; 
        } else 
                return notify_fail("你没有写入这个档案(" + file + ")的权利。\n"); 
} 
 
void owner_is_killed() { destruct(this_object()); } 
 
 
