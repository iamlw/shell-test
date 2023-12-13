#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

sem_t sem01,sem02;
void * testA()
{
    sem_wait(&sem01);
    printf("线程A开始执行\n");
    sleep(3);
    printf("线程A执行完毕\n");
    sem_post(&sem02);
    return NULL;
}

void * testB()
{
    sem_wait(&sem02);
    printf("线程B开始执行\n");
    sleep(3);
    printf("线程B执行完毕\n");
    return NULL;
}
int main(int argc, char const *argv[])
{
    sem_init(&sem01,0,1);
    sem_init(&sem02,0,0);

    pthread_t t1,t2;

    pthread_create(&t1,NULL,testA,NULL);
    pthread_create(&t2,NULL,testB,NULL);
    
    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
    return 0;
}

