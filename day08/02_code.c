#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
pthread_mutex_t lockA,lockB;
void * funA(void * arg){
    printf("张三即将进入A锁\n");
    pthread_mutex_lock(&lockA);
    printf("张三进入A锁\n");
    sleep(2);
    printf("张三即将进入B锁\n");
    pthread_mutex_lock(&lockB);
    printf("张三进入B锁\n");
    pthread_mutex_unlock(&lockB);
    printf("张三退出B锁\n");
    pthread_mutex_unlock(&lockA);
    printf("张三退出A锁\n");
    return NULL;
}
void * funB(void * arg){
    printf("李四即将进入B锁\n");
    pthread_mutex_lock(&lockB);
    printf("李四进入B锁\n");
    sleep(2);
    printf("李四即将进入A锁\n"); 
    pthread_mutex_lock(&lockA);
    printf("李四进入A锁\n");
    pthread_mutex_unlock(&lockA);
    printf("李四退出A锁\n");
    pthread_mutex_unlock(&lockB);
    printf("李四退出B锁\n");
    return NULL;
}
int main(int argc, char const *argv[])
{
    pthread_mutex_init(&lockA,NULL);
    pthread_mutex_init(&lockB,NULL);

    pthread_t t1,t2;
    pthread_create(&t1,NULL,funA,NULL);
    pthread_create(&t2,NULL,funB,NULL);
    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
    pthread_mutex_destroy(&lockA);
    pthread_mutex_destroy(&lockB);
    
    
    return 0;
}
