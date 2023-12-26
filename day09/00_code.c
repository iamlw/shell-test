#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <semaphore.h>
#include <unistd.h>
sem_t s1,s2,s3;

void *print01(void *argv)
{       
    int num=0;
    while (num<10)
    {    
        sem_wait(&s1);
        char * s=(char *)argv;
        printf("%s = %ld\n",s,pthread_self());    
        sem_post(&s2);
        num++;
    }
    return NULL;
}

void *print02(void *argv)
{
    int num=0;
    while (num<10)
    {    
        sem_wait(&s2);
        char * s=(char *)argv;
        printf("%s = %ld\n",s,pthread_self());
        sem_post(&s3);
        num++;
    }
    return NULL;
}

void *print03(void *argv)
{
    int num=0;
    while (num<10)
    {    
        sem_wait(&s3);
        char * s=(char *)argv;
        printf("%s = %ld\n",s,pthread_self());    
        sem_post(&s1);
        num++;
    }
    return NULL;
}
int main(int argc, char const *argv[])
{
    sem_init(&s1,0,1);
    sem_init(&s2,0,0);
    sem_init(&s3,0,0);

    pthread_t  p1,p2,p3;
    pthread_create(&p1,NULL,print01,"A");
    pthread_create(&p2,NULL,print02,"B");
    pthread_create(&p3,NULL,print03,"C");

    pthread_join(p1,NULL);
    pthread_join(p2,NULL);
    pthread_join(p3,NULL);

    sem_destroy(&s1);
    sem_destroy(&s2);
    sem_destroy(&s3);
    return 0;
}
