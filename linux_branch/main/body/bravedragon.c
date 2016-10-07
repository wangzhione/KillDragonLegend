#include <bravedragon.h>
#include <cfgdata.h>
#include <scconf.h>

#ifdef __GNUC__  // 下面是依赖GCC编译器实现

#	define BDCOLOR(v) \
		system("\033[" #v ";30m ")

#elif _MSC_VER // 下面是依赖Visual Studio编译器实现

#	define BDCOLOR(v) \
		system("color " #v)

#else	
#	error "error : Currently only supports the Visual Studio and GCC!"
#endif

#define _INT_PAUSETIME	(1000)

// 灭龙传说动画头部
static int _bd_head(void) {
	static bool _isstart = true;

	// 只有第一次进入的时候会播放动画
	if (_isstart) {
		_isstart = false;
		CONSOLECLS();
		BDCOLOR(31);
		puts("********************************************************************************\n");
		bd_animates("                              § 欢迎进入【灭龙传说】§\n", 50, _INT_PAUSETIME);
		puts("\n********************************************************************************");
		SLEEPMS(_INT_PAUSETIME);
	}

	CONSOLECLS();
	BDCOLOR(30);
	puts("********************************************************************************\n\n");
	puts("                                    【灭龙传说】\n");
	puts("                               [A]--新的征程");
	puts("                               [B]--旧的回忆");
	puts("                               [C]--隐居山林");
	puts("\n\n********************************************************************************");

	return toupper(sh_getch());
}

// 灭龙传说退出情况
static bool _bd_end(void) {
	int ch;
	CONSOLECLS();
	printf("你确认要退出游戏？<y/N>");
	ch = sh_getch();
	return ch == 'y' || ch == 'Y';
}

//角色：角色名，等级，攻击，防御，速度，幸运，金币，存在判断（ 若yesp=99则判定用户已存在），经验，升级经验，血量和魔法值。 
struct player {
	char name[_INT_KNAME];			// 角色名称
	unsigned short level;			// 角色等级
	short attack;					// 攻击力
	short defense;					// 防御力
	short acceleration;				// 速度 
	short luck;						// 幸运
	int gold;						// 玩家拥有的角色信息
	int exp;						// 玩家当前经验
	int exped;						// 玩家升级需要的经验
	int hp;							// 玩家当前血量
	int hpmax;						// 玩家最大血量
	short mp;						// 玩家当前蓝量
	short mpmax;					// 玩家最大的蓝量
};

// 数据监测, 有问题直接退出
static void _bd_check(struct player * play) {
	if (play->level >= 101 
		|| play->gold > 200000
		|| play->acceleration > 1000 
		|| play->exp < 0
		|| play->exped > 100000) {
		bd_errs("程序数据异常，可能存在利用BUG作弊或者档案读取异常，游戏将自动结束,请按照规则进行游戏!", "【BUG警告】", "严重", 0);
		exit(EXIT_FAILURE);
	}
}

static void _bd_menuf_heroinfo(struct player * play) {
	char ch;
	bd_animatesa("", "【角色信息】", true, false, 0, 0);
	printf("\n\n侠名：%s", play->name);
	printf("\n\n等级:%d (%d/%d)", play->level, play->exp, play->exped);
	printf("\n血量:%d/%d    魔力:%d/%d", play->hp, play->hpmax, play->mp, play->mpmax);
	printf(" \n攻击力:%d \n防御:%d \n速度:%d", play->attack, play->defense, play->acceleration);
	printf(" \n幸运:%d \n金币:%d  ", play->luck, play->gold);
	printf("\n\n[W]--装备         [Y]--物品     ");
	printf("\n\n[K]--技能         [Q]--返回     ");

	for (;;) {
		ch = toupper(sh_getch());
		switch (ch) {
		case 'W': // 需要自己去实现装备系统

			break;
		case 'Y': // 技能展示

			break;

		case 'K': // 物品展示

			break;

		case 'Q': // 返回主界面
			return;
		}
	}
}

static void _bd_menuf(struct player * play) {
	int ch;
	const char * help;
	_bd_check(play);
	BDCOLOR(30);

	help = mconf_get("bravedragon_help");
	for (;;) {

		// 数据头部信息
		CONSOLECLS();
		printf("\n                            【灭龙传说】\n");
		printf("------------------------------------------------------------------------");
		printf("\n\n勇士：%s (%d级)", play->name, play->level);
		printf("\n\n[A]--人物信息       [B]--包裹              [C]--商店");
		printf("\n\n[D]--【战场】       [E]--档案              [F]--返回");
		printf("\n\n[G]--小游戏         [H]--帮助");

		ch = sh_getch();
		ch = toupper(ch);

		switch (ch) {
		case 'A':
			_bd_menuf_heroinfo(play);
			break;
		case 'B':
			break;
		case 'C':
			break;
		case 'D':
			break;
		case 'E':
			break;
		case 'F':
			break;
		case 'G':
			break;

		case 'H': // 游戏帮助某块
			bd_animatesa(help, "【游戏帮助】", true, false, 0, 0);
			sh_getch();
			break;
		}
	}
}

// 新的征程
static void _bd_newgame(struct player * play) {
	static bool _iswelcome = true;
	char name[_INT_KNAME + 1];

	CONSOLECLS();

	// 播放新的游戏序
	if (_iswelcome) {
		_iswelcome = false;
		bd_animatesa(mconf_get("bravedragon_main"), mconf_get("bravedragon_title"),
			true, false, 0, _INT_PAUSETIME << 1);
	}

	CONSOLECLS();
	bd_animatesa("欢迎你！勇士！请告诉我你的名字：", "【勇士注册】", 1, 0, 0, 0);
	// 错误输入
	if (fgets(name, _INT_KNAME, stdin) == NULL) {
		bd_errs("勇士, 不能乱搞啊!!!!!!", "【警告】", "普通", 0);
		SLEEPMS(_INT_KNAME);
		return;
	}

	// 去掉\n
	name[strlen(name) - 1] = '\0';

	// 开始构建数据对象
	strcpy(play->name, name);
	play->level = 1;					// 角色等级
	play->attack = 5;					// 攻击力
	play->defense = 8;					// 防御力
	play->acceleration = 3;				// 速度 
	play->luck = 5;						// 幸运
	play->gold = 1000;					// 玩家拥有的角色信息
	play->exp = 0;						// 玩家当前经验
	play->exped = play->level * 50;		// 玩家升级需要的经验
	play->hp = 100;						// 玩家当前血量
	play->hpmax = 100;					// 玩家最大血量
	play->mp = 50;						// 玩家当前蓝量
	play->mpmax = 50;					// 玩家最大的蓝量

	// 下面开始走新的目录函数
	_bd_menuf(play);
}

// 灭龙传说的主函数
void 
bd_main(void) {
	// 玩家对象信息
	struct player hero;

	// 加载配置信息
	data_start();

	for (;;) {
		// 播放动画, 并得到玩家输入 大写控制字符
		char ch = _bd_head();

		switch (ch) {
		case 'A':						// 新的征程
			_bd_newgame(&hero);
			break;	
		case 'B':						// 旧的回忆
			break;
		case 'C':						// 隐居山林
			if (_bd_end())
				goto _end;
			break;
		}
	}

_end:
	// 释放配置信息
	data_close();
}

// 输出文本str, 每打印一个字符停顿tn毫秒, 最后停顿tb毫秒
void 
bd_animates(const char * str, int tn, int tb) {
	char c;
	while ((c = *str++)) {
		putchar(c);
		SLEEPMS(tn);
	}

	SLEEPMS(tb);
}

// 动画输出错误信息, errs:错误信息, title标题, levs错误等级, iscls是否清除头部部分
void 
bd_errs(const char * errs, const char * title,
		const char * levs, bool iscls) {
	int c;

	if (iscls)
		CONSOLECLS();

	printf("\n\n\a                    %s\n", title);
	printf("********************************************************************************\n");
	printf("\n\n【错误等级】：%s\n\n", levs);
	printf("【错误原因】：\n ");

	while ((c = *errs++)) {
		putchar(c);
	}

	sh_getch();
}

// 控制更强的打印函数
void 
bd_animatesa(const char * str, const char * title,
			 bool isclsh, bool isclsb, int tn, int tb) {
	int c;

	if (isclsh)
		CONSOLECLS();

	printf("                    %s\n", title);
	while ((c = *str++)) {
		putchar(c);
		SLEEPMS(tn);
	}

	if (isclsb)
		CONSOLECLS();
	SLEEPMS(tb);
}

// 标题打印函数, 美化符号标题
void 
bd_butis(const char * str, const char * title) {
	CONSOLECLS();
	printf("\n                              %s\n", title);
	for (int i = 0; i < 80; ++i)
		printf("%s", str);
	putchar('\n');
}

// 打印区间条信息
void 
bd_mms(char str[], int len) {
	putchar('\n');
	for (int i = 0; i < len; ++i)
		printf("%s", str);
}
