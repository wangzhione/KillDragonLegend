#include <stdio.h>
#include <scrwlock.h>
#include <pthread.h>

#define _INT_BZ     (13)
#define _INT_WTH    (2)
#define _INT_RTH    (10)

struct rwarg {
	pthread_t id;
	struct rwlock lock;    // 加锁用的  
	int idx;                 // 指示buf中写道那了
	char buf[BUFSIZ];        // 存储临时数据
};

// 写线程, 主要随机写字符进去
void twrite(struct rwarg * arg);
// 读线程
void treads(struct rwarg * arg);

/*
* 自己写读写锁底层
*/
int main_atom_rwlock(int argc, char * argv[]) {
	// 初始化定义需要使用的量
	int i;
	struct rwarg arg = { 0 };

	// 读线程跑起来
	for (i = 0; i<_INT_RTH; ++i)
		pthread_create((pthread_t *)&arg, NULL, (void * (*)(void *))treads, &arg);

	// 写线程再跑起来
	for (i = 0; i<_INT_WTH; ++i)
		pthread_create((pthread_t *)&arg, NULL, (void * (*)(void *))twrite, &arg);

	// 简单等待一下
	printf("sleep input enter:");
	getchar();

	return 0;
}

// 写线程, 主要随机写字符进去
void
twrite(struct rwarg * arg) {
	pthread_detach(pthread_self());

	while (arg->idx < _INT_BZ) {
		rwlock_wlock(&arg->lock);
		arg->buf[arg->idx] = 'a' + arg->idx;
		++arg->idx;
		rwlock_wunlock(&arg->lock);
	}
	puts("twrite is exit...");
}

// 读线程
void
treads(struct rwarg * arg) {
	pthread_detach(pthread_self());

	while (arg->idx < _INT_BZ) {
		rwlock_rlock(&arg->lock);
		puts(arg->buf);
		rwlock_runlock(&arg->lock);
	}
	puts("treads is exit...");
}