#ifndef _H_SIMPLEC_BRAVEDRAGON
#define _H_SIMPLEC_BRAVEDRAGON

#include <schead.h>

// 灭龙传说的主函数
extern void bd_main(void);

// 输出文本str, 每打印一个字符停顿tn毫秒, 最后停顿tb毫秒
extern void bd_animates(const char * str, int tn, int tb);

// 动画输出错误信息, errs:错误信息, title标题, levs错误等级, iscls是否清除头部部分
extern void bd_errs(const char * errs, const char * title,
					const char * levs, bool iscls);

// 控制更强的打印函数
extern void bd_animatesa(const char * str, const char * title, 
						 bool isclsh, bool isclsb, int tn, int tb);

// 标题打印函数, 美化符号标题
extern void bd_butis(const char * str, const char * title);

// 打印区间条信息
extern void bd_mms(char str[], int len);

#endif // !_H_SIMPLEC_BRAVEDRAGON