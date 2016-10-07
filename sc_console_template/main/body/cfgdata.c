#include <cfgdata.h>
#include <scconf.h>
#include <scjson.h>

// 配置解析函数
struct cfgparse {
	// 对应config.ini中配置信息
	char * inikey;
	// return < 0 表示error
	int (* parse)(const cjson_t);
};

/*----------------------------begin skill 技能数据相关-------------------------------*/
/*
 * 得到配置中关于技能配置的所有数据
 *		: 返回技能对象数组
 */
static array_t _cfg_skills;
inline const array_t
data_skills(void) {
	return _cfg_skills;
}

// 所有技能相关配置信息, 得到和解析
static int _cfg_get_skills(const cjson_t arrs) {
	int i, len;
	cjson_t arr, aidx;
	struct skill * node;

	// 创建 _cfg_skills 技能数组对象
	_cfg_skills = array_new(0, sizeof(struct skill));

	len = cjson_getlen(arrs);
	assert(len >= 1);
	for (i = 0; i < len; ++i) {
		// 得到特定行json 数组数据
		arr = cjson_getarray(arrs, i);
		// 得到最终其中一个数组对象
		node = array_push(_cfg_skills);

		// 依次读取下面行数据, 
		aidx = arr->child;
		strncpy(node->name, aidx->vs, _INT_KNAME);	// 技能名称

		aidx = aidx->next;
		strncpy(node->desc, aidx->vs, _INT_BDESC);	// 技能描述

		aidx = aidx->next;
		node->keepround = (unsigned short)aidx->vd;	// 保持的回合数

		aidx = aidx->next;
		node->addblood = (int)aidx->vd;				// 增加的血量

		aidx = aidx->next;
		node->addattack = (short)aidx->vd;			// 百分比增加攻击力

		aidx = aidx->next;
		node->adddefense = (short)aidx->vd;			// 增加防御力

		aidx = aidx->next;
		node->addacceleration = (short)aidx->vd;	// 增加速度

		aidx = aidx->next;
		node->addfortunately = (short)aidx->vd;		// 增加幸运

		aidx = aidx->next;
		node->needmp = (short)aidx->vd;				// 释放需要mp(魔法值)
		
		aidx = aidx->next;
		node->level = (unsigned short)aidx->vd;		// 需要的等级

		aidx = aidx->next;
		node->isallowed = aidx->vd >= 1;			// 是否允许释放

		// 简单检查一下
		if (NULL != aidx->next) {
			CERR("_get_cfg_skills NULL != aidx->next i = %d.", i);
			return -1;
		}
	}

	return 0;
}
/*----------------------------e n d skill 技能数据相关-------------------------------*/

/*----------------------------begin goods 物品数据相关-------------------------------*/

/*
 * 得到配置中关于物品的所有数组数据
 *		: 返回物品对象数组
 */
static array_t _cfg_goods;
inline const array_t 
data_goods(void) {
	return _cfg_goods;
}

// 所有物品相关配置信息, 得到和解析
static int _cfg_get_goods(const cjson_t arrs) {
	int i, len;
	cjson_t arr, aidx;
	struct good * node;

	// 创建 _cfg_skills 技能数组对象
	_cfg_goods = array_new(0, sizeof(struct skill));

	len = cjson_getlen(arrs);
	assert(len >= 1);
	for (i = 0; i < len; ++i) {
		// 得到特定行json 数组数据
		arr = cjson_getarray(arrs, i);
		// 得到最终其中一个数组对象
		node = array_push(_cfg_goods);

		// 依次读取下面行数据, 
		aidx = arr->child;
		strncpy(node->name, aidx->vs, _INT_KNAME);	// 物品名称

		aidx = aidx->next;
		strncpy(node->desc, aidx->vs, _INT_KNAME);	// 物品描述

		aidx = aidx->next;
		node->type = (unsigned char)aidx->vd;	// 物品类型, see _GOOD_*
		assert(node->type >= _GOOD_DRUGS && node->type <= _GOOD_ELIXIR);
								
		aidx = aidx->next;
		node->addmp = (int)aidx->vd;				// 增加的魔法MP值

		aidx = aidx->next;
		node->addblood = (int)aidx->vd;				// 增加的血量

		aidx = aidx->next;
		node->addattack = (short)aidx->vd;			// 增加攻击力

		aidx = aidx->next;
		node->adddefense = (short)aidx->vd;			// 增加防御力

		aidx = aidx->next;
		node->addacceleration = (short)aidx->vd;	// 增加速度

		aidx = aidx->next;
		node->addfortunately = (short)aidx->vd;		// 增加幸运

		aidx = aidx->next;
		node->pirce = (int)aidx->vd;				// 物品价格

		aidx = aidx->next;
		node->panel = (unsigned char)aidx->vd;		// 占用包裹格子数

		aidx = aidx->next;
		node->addcrit = (short)aidx->vd;			// 增加暴击量

		aidx = aidx->next;
		node->cnt = (unsigned short)aidx->vd;		// 物品拥有数量

		aidx = aidx->next;
		node->maxcnt = (unsigned short)aidx->vd;	// 物品最大拥有数量
		
		aidx = aidx->next;
		node->isbuy = aidx->vd >= 1;				// 物品是否可以买
		
		aidx = aidx->next;						
		node->issell = aidx->vd >= 1;				// 物品是否可以卖
		
		// 简单检查一下
		if (NULL != aidx->next) {
			CERR("_get_cfg_skills NULL != aidx->next i = %d.", i);
			return -1;
		}
	}

	return 0;
}

/*----------------------------e n d goods 物品数据相关-------------------------------*/

/*----------------------------begin maps 地图数据相关-------------------------------*/



/*----------------------------e n d maps 地图数据相关-------------------------------*/

/*
 * 得到配置中关于地图的所有数组数据
 *		: 返回地图对象数组
 */
static array_t _cfg_maps;
inline const array_t 
data_maps(void) {
	return _cfg_maps;
}

// 辅助操作宏, json -> 具体值
#define AIDXTONODE(type, val, msg) \
	node->##val = (type)aidx->vd;\
	aidx = aidx->next

// 所有地图相关配置信息, 得到和解析
static int _cfg_get_maps(const cjson_t arrs) {
	int i, len;
	cjson_t arr, aidx;
	struct map * node;

	// 创建 _cfg_skills 技能数组对象
	_cfg_maps = array_new(0, sizeof(struct skill));

	len = cjson_getlen(arrs);
	assert(len >= 1);
	for (i = 0; i < len; ++i) {
		// 得到特定行json 数组数据, 并且得到具体的那行数据
		arr = cjson_getarray(arrs, i);
		aidx = arr->child;
		// 得到最终其中一个数组对象
		node = array_push(_cfg_maps);
		assert(arr && aidx && node);

		// 依次读取下面行数据, 
		strncpy(node->name, aidx->vs, _INT_KNAME);	// 物品名称
		aidx = aidx->next;

		strncpy(node->desc, aidx->vs, _INT_SDESC);	// 物品描述
		aidx = aidx->next;

		AIDXTONODE(short, start, "地图中怪物起点");
		AIDXTONODE(int, number, "地图中怪物数量");
		AIDXTONODE(unsigned short, level, "地图中怪物限制等级");

		// 简单检查一下
		if (NULL != aidx) {
			CERR("_get_cfg_skills NULL != aidx->next i = %d.", i);
			return -1;
		}
	}

	return 0;
}

/*----------------------------begin monsters 怪物数据相关-------------------------------*/

/*
 * 得到配置中关于怪物的所有数组数据
 *		: 返回怪物对象数组
 */
static array_t _cfg_monsters;
inline const array_t 
data_monsters(void) {
	return _cfg_monsters;
}

// 所有怪物相关配置信息, 得到和解析
static int _cfg_get_monsters(const cjson_t arrs) {
	int i, len;
	cjson_t arr, aidx;
	struct monster * node;

	// 创建 _cfg_skills 技能数组对象
	_cfg_monsters = array_new(0, sizeof(struct skill));

	len = cjson_getlen(arrs);
	assert(len >= 1);
	for (i = 0; i < len; ++i) {
		// 得到特定行json 数组数据, 并且得到具体的那行数据
		arr = cjson_getarray(arrs, i);
		aidx = arr->child;
		// 得到最终其中一个数组对象
		node = array_push(_cfg_monsters);
		assert(arr && aidx && node);

		// 依次读取下面行数据, 
		strncpy(node->name, aidx->vs, _INT_KNAME);	// 怪物名称
		aidx = aidx->next;

		strncpy(node->desc, aidx->vs, _INT_SDESC);	// 怪物描述
		aidx = aidx->next;

		AIDXTONODE(unsigned short, level, "怪物等级");
		AIDXTONODE(short, attack, "攻击力");
		AIDXTONODE(short, defense, "防御力");
		AIDXTONODE(short, acceleration, "速度");
		AIDXTONODE(int, blood, "当前血量");
		AIDXTONODE(int, maxblood, "最大血量");
		AIDXTONODE(short, mp, "当前魔法量");
		AIDXTONODE(short, maxmp, "最大魔法量");
		AIDXTONODE(short, experience, "携带的经验");
		AIDXTONODE(short, gold, "携带的金币");
		AIDXTONODE(bool, isdrugre, "携带的金币");
		AIDXTONODE(bool, isweapons, "是否携带随机武器");
		AIDXTONODE(bool, iselixir, "是否携带奇宝");
		AIDXTONODE(bool, isescape, " 是否允许逃跑");

		// 简单检查一下
		if (NULL != aidx) {
			CERR("_get_cfg_skills NULL != aidx->next i = %d.", i);
			return -1;
		}
	}

	return 0;
}

/*----------------------------e n d monsters 怪物数据相关-------------------------------*/


/*
 * 所有配置相关数据获取, 构建
 */
void 
data_start(void) {
	const char * path;
	cjson_t arrs;
	int i = -1;

	// 需要每次添加配置动态添加这个解析key对映解析函数数据
	struct cfgparse cfgs[] = {
		{ "cfgdata_skills", _cfg_get_skills },
		{ "cfgdata_goods", _cfg_get_goods },
		{ "cfgdata_maps", _cfg_get_maps },
		{ "cfgdata_monsters", _cfg_get_monsters },
	};

	while (++i < LEN(cfgs)) {
		struct cfgparse * cfg = cfgs + i;

		// 初始化技能相关配置
		path = mconf_get(cfg->inikey);
		if (!path || !*path)
			CERR_EXIT("mconf_get $CfgSkills is error");
		arrs = cjson_newfile(path);
		if (NULL == arrs)
			CERR_EXIT("cjson_newfile path = %s is error!", path);

		// 开始解析相关配置信息
		if (0 > cfg->parse(arrs)) {
			cjson_delete(arrs);
			data_close();
			CERR_EXIT("cjson_newfile path = %s is error! need check!", path);
		}

		// 释放已经解析完毕临时json信息集
		cjson_delete(arrs);
	}
}

/*
 * 所有配置相关数据销毁, 释放
 */
inline void 
data_close(void) {
	array_die(_cfg_skills);
	array_die(_cfg_goods);
	array_die(_cfg_maps);
	array_die(_cfg_monsters);
}