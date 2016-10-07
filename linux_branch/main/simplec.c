#include <schead.h>
#include <scconf.h>
#include <bravedragon.h>

// 第一次见面的函数
static void _simplec_go(void) {
	const char * verson;
	const char * author;
	const char * website;
	const char * image;

	// 得到配置的版本信息
	verson = mconf_get("Verson");
	author = mconf_get("Author");
	website = mconf_get("Website");
	image = mconf_get("Image");

	// 打印简单信息
	printf("Welcome to the %s\n", verson);
	printf("More detailed information need to travel %s\n", website);
	printf("Thank you so much by %s\n", author);
	printf("%s\n", image);
}

/*
 * simple c 框架业务层启动的代码
 */
void simplec_main(void) {

	// 开始动画部分
	_simplec_go();
	SLEEPMS(6666);
	CONSOLECLS();

	// 进入游戏, 走灭龙传说的逻辑
	bd_main();
}