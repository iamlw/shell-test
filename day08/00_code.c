#include <stdio.h>
#include <pthread.h>
int main(int argc, char const *argv[])
{
    //动态初始化
    pthread_mutex_t lock1;
    pthread_mutex_init( &lock1,NULL);

    //静态初始化
    pthread_mutex_t lock2 = PTHREAD_MUTEX_INITIALIZER;

    //上锁
    pthread_mutex_lock(&lock1);
    //解锁
    pthread_mutex_unlock(&lock1);


    //锁的回收

    pthread_mutex_destroy(&lock1);
    pthread_mutex_destroy(&lock2);

    return 0;
}
