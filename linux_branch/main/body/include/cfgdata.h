#ifndef __H_SIMPLEC_CFGDATA
#define __H_SIMPLEC_CFGDATA

#include <array.h>

/*
 * 所有配置相关数据获取, 构建
 */
extern void data_start(void);

/*
 * 所有配置相关数据销毁, 释放
 */
extern void data_close(void);

/*----------------------------begin skill 技能数据相关-------------------------------*/
// 名称字符数
#define _INT_KNAME	24
// 描述大字符数
#define _INT_BDESC	320

struct skill {
	char name[_INT_KNAME + 1];				// 技能名称
	char desc[_INT_BDESC + 1];				// 技能描述
	unsigned short keepround;				// 保持的回合数
	int addblood;							// 增加的血量
	short addattack;						// 增加攻击力, 按照百分比
	short adddefense;						// 增加防御力
	short addacceleration;					// 增加速度
	short addfortunately;					// 增加幸运
	short needmp;							// 释放需要mp(魔法值)
	unsigned short level;					// 需要的等级
	bool isallowed;							// 是否允许释放
};

/*
 * 得到配置中关于技能配置的所有数据
 *		: 返回技能对象数组
 */
extern const array_t data_skills(void);
/*----------------------------e n d skill 技能数据相关-------------------------------*/

/*----------------------------begin goods 物品数据相关-------------------------------*/

#define _GOOD_DRUGS			(1)		// 药品
#define _GOOD_WEAPONS		(2)		// 武器
#define _GOOD_ELIXIR		(3)		// 仙丹, 奇宝

struct good {
	char name[_INT_KNAME + 1];				// 物品名称
	char desc[_INT_KNAME + 1];				// 物品描述
	unsigned char type;						// 物品类型, see _GOOD_*
	int addmp;								// 增加的魔法MP值
	int addblood;							// 增加的血量
	short addattack;						// 增加攻击力
	short adddefense;						// 增加防御力
	short addacceleration;					// 增加速度
	short addfortunately;					// 增加幸运
	int pirce;								// 价格
	unsigned char panel;					// 占用包裹格子数
	short addcrit;							// 增加暴击量
	unsigned short cnt;						// 物品拥有数量
	unsigned short maxcnt;					// 物品最大拥有数量
	bool isbuy;								// 物品是否可以买
	bool issell;							// 物品是否可以卖
};

/*
 * 得到配置中关于物品的所有数组数据
 *		: 返回物品对象数组
 */
extern const array_t data_goods(void);

/*----------------------------e n d goods 物品数据相关-------------------------------*/

/*----------------------------begin maps 地图数据相关-------------------------------*/



/*----------------------------e n d maps 地图数据相关-------------------------------*/

// 描述小字符数
#define _INT_SDESC	192

struct map {
	char name[_INT_KNAME + 1];				// 地图名称
	char desc[_INT_SDESC + 1];				// 地图描述
	short start;							// 地图中怪物起点
	int number;								// 地图中怪物数量
	unsigned short level;					// 地图中怪物限制等级
};

/*
 * 得到配置中关于地图的所有数组数据
 *		: 返回地图对象数组
 */
extern const array_t data_maps(void);

/*----------------------------begin monsters 怪物数据相关-------------------------------*/

struct monster {
	char name[_INT_KNAME + 1];				// 怪物名称
	char desc[_INT_SDESC + 1];				// 怪物描述
	unsigned short level;					// 怪物等级
	short attack;							// 攻击力
	short defense;							// 防御力
	short acceleration;						// 速度 
	int blood;								// 当前血量
	int maxblood;							// 最大血量
	short mp;								// 当前魔法量
	short maxmp;							// 最大魔法量
	short experience;						// 携带的经验
	short gold;								// 携带的金币
	bool isdrugre;							// 是否携带随机物品奖励
	bool isweapons;							// 是否携带随机武器
	bool iselixir;							// 是否携带奇宝
	bool isescape;							// 是否允许逃跑
};

/*
 * 得到配置中关于怪物的所有数组数据
 *		: 返回怪物对象数组
 */
extern const array_t data_monsters(void);

/*----------------------------e n d monsters 怪物数据相关-------------------------------*/

#endif // !__H_SIMPLEC_CFGDATA