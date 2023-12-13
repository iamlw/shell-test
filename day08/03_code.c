#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>
pthread_mutex_t lock;
int num;
void *myread(void * arg)
{
    pthread_mutex_lock(&lock);
    printf("线程读:%d\n",num);
    sleep(1);
    pthread_mutex_unlock(&lock);
    return NULL;
}

void * mywrite(void * arg)
{
    pthread_mutex_lock(&lock);
    num = rand()%100;
    printf("线程写:%d\n",num);
    sleep(1);
    pthread_mutex_unlock(&lock);
    return NULL;
}
int main(int argc, char const *argv[])
{
    srand(time(NULL));
    pthread_t ts[23];
    pthread_mutex_init(&lock,NULL);
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
    pthread_mutex_destroy(&lock);
    


    return 0;
}
