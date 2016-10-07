#include <schead.h>

/*
 * 这里主要测试 sctimeutil.h 接口能否正常使用
 * 
 */
int main_sctimeutil(int argc, char * argv[]) {
	stime_t tstr;
	bool rt;
	time_t t;
	struct tm st;

	// 注册结束等待函数
	INIT_PAUSE();

	printf("Now begin time is : %s\n", stu_getntstr(tstr));

	rt = stu_gettime("2016-07-13 20:04:07", &t, &st);
	printf("rt = %d, t = %lld, sec = %d\n", rt, t, st.tm_sec);

	// 万能转换
	rt = stu_gettime("2016年7月13日20:56:53", &t, &st);
	printf("rt = %d, t = %lld, year = %d, sec = %d\n", rt, t, st.tm_year, st.tm_sec);

	rt = stu_sisday("2016年7月13日20:57:56", "2016年08月13日20:58:00");
	printf("rt = %d\n", rt);

	printf("Now e n d time is : %s\n", stu_getntstr(tstr));
	return 0;
}