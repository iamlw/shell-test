#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>
pthread_mutex_t lock;
int num = 1000;
void * sell(void * arg)
{
    while (num >0)
    {
        pthread_mutex_lock(&lock);
        if (num <=0)
        {
            pthread_mutex_unlock(&lock);
            break;
        }
        
        num -- ;
        sleep(0.1);
        char *name =(char *)arg;
        printf("%s卖了一包方便面,还剩%d包\n",name,num);
        pthread_mutex_unlock(&lock);
    }
    
}

int main(int argc, char const *argv[])
{
    pthread_mutex_init( &lock,NULL);

    pthread_t t1,t2,t3,t4;
    pthread_create(&t1,NULL,sell,"小丽");
    pthread_create(&t2,NULL,sell,"小美");
    pthread_create(&t3,NULL,sell,"小舒");
    pthread_create(&t4,NULL,sell,"小云");

    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
    pthread_join(t3,NULL);
    pthread_join(t4,NULL);
    pthread_mutex_destroy(&lock);


    return 0;
}
