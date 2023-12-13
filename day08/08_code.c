#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
sem_t mysem;

void * fun01(void *arg)
{
    printf("线程1将对信号量-1\n");
    sem_wait(&mysem);
    printf("线程1对信号量-1完成\n");
    sleep(5);
    printf("线程1休眠结束,即将被信号量+1\n");
    sem_post(&mysem);
    return NULL;
}
void * fun02(void *arg)
{
    printf("线程2将对信号量-1\n");
    sem_wait(&mysem);
    printf("线程2对信号量-1完成\n");
    sleep(5);
    printf("线程2休眠结束,即将被信号量+1\n");
    sem_post(&mysem);
    return NULL;
}

int main(int argc, char const *argv[])
{
    sem_init(&mysem,0,1);
    pthread_t t1,t2;

    pthread_create(&t1,NULL,fun01,NULL);
    pthread_create(&t2,NULL,fun02,NULL);

    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
    return 0;
}
