#include <sctimer.h>

static int _sm;

static void _timer(void* arg)
{
	stime_t tstr;
	stu_getntstr(tstr);
	printf("%p + %d => %s\n", arg, ++_sm, tstr);
}

int main_sctimer(int argc, char* argv[])
{
	st_add(0, 5, 2000, _timer, (void*)1, false);
	st_add(3000, 2, 2000, _timer, (void*)2, false);
	st_add(4000, 1, 2000, _timer, (void*)3, false);

	// 开启一个多线程的永久异步方法
	int tid = st_add(0, 0, 1000, _timer, (void*)4, true);

	// 等待5秒后关闭 上面永久的定时器事件
	SLEEPMS(5000);
	st_del(tid);

	// 再注册一个方法
	st_add(100, 0, 5000, _timer, (void*)5, false);
	
	sh_pause();
	return 0;
}
