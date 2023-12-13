#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
void * turtle(void * arg)
{
    for (int i = 100; i >= 0; i--)
    {
        if (i==0)
        {
            printf("乌龟冲线了\n");
        }else
        {
        printf("乌龟还有%d米到终点\n",i);
        }
        sleep(0.2);
        
    }
    
}

void * rabbit(void * arg)
{
    for (int i = 100; i >= 0; i-=5)
    {
        if (i==0)
        {
            printf("兔子冲线了\n");
        }else if (i==5)
        {
            printf("兔子还有%d米到终点\n",i);
            printf("兔子睡大觉了\n");
            sleep(20);
        }
        else
        {
            printf("兔子还有%d米到终点\n",i);
        }
        sleep(0.2);
        
    }
}
int main(int argc, char const *argv[])
{
    int i=0;
    pthread_t t1;
    pthread_create(&t1,NULL,turtle,NULL);
    pthread_t t2;
    pthread_create(&t2,NULL,rabbit,NULL);
    
    while(1);
    return 0;
}
