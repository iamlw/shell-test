#define _XOPEN_SOURCE 500
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>
pthread_rwlock_t lock;
int num;
void *myread(void * arg)
{
    pthread_rwlock_rdlock(&lock);
    printf("线程读:%d\n",num);
    sleep(1);
    pthread_rwlock_wrlock(&lock);
    return NULL;
}

void * mywrite(void * arg)
{
    pthread_rwlock_rdlock(&lock);
    num = rand()%100;
    printf("线程写:%d\n",num);
    sleep(1);
    pthread_rwlock_wrlock(&lock);
    return NULL;
}
int main(int argc, char const *argv[])
{
    srand(time(NULL));
    pthread_t ts[23];
    pthread_rwlock_init(&lock,NULL);
    for (int i = 0; i < 20; i++)
    {
        pthread_create(&ts[i],NULL,myread,NULL);
    }
    for (int i = 20; i < 23; i++)
    {
        pthread_create(&ts[i],NULL,mywrite,NULL);
    }
    for (int i = 0; i < 23; i++)
    {
        pthread_join(ts[i],NULL);
    }
    pthread_rwlock_destroy(&lock);
    


    return 0;
}
