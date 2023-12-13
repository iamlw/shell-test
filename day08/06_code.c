#define _XOPEN_SOURCE 500
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
pthread_mutex_t lock; 
pthread_cond_t cond;

void * show_num(void * arg)
{
    pthread_mutex_lock(&lock);
    for (int i = 1; i < 53; i++)
    {
        printf("%d\n",i);
        if (i%2 == 0)
        {
            pthread_cond_broadcast(&cond);
            pthread_cond_wait(&cond,&lock);
        }
        pthread_mutex_unlock(&lock);

        
    }
    return NULL;
    
}
void * show_char(void * arg)
{
    sleep(0.1);
    for (int i = 97; i < 123; i++)
    {
        pthread_mutex_lock(&lock);
        char  c=(char )i;
        printf("%c\n",i);
        pthread_cond_broadcast(&cond);
        if (i !=122)
        {
        pthread_cond_wait(&cond,&lock);
        }
        
        pthread_mutex_unlock(&lock);
    }
    return NULL;

    
}
int main(int argc, char const *argv[])
{
    pthread_mutex_init(&lock,NULL);
    pthread_cond_init(&cond,NULL);

    pthread_t t1,t2;
    pthread_create(&t1,NULL,show_num,NULL);
    pthread_create(&t2,NULL,show_char,NULL);

    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
    pthread_mutex_destroy(&lock);
    pthread_cond_destroy(&cond);
    return 0;
}
