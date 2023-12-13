#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void * fun01(void * arg)
{
    for (int i = 1; i < 53; i++)
    {
        printf("%d\n",i);
        sleep(0.1);
    }
    
}


void * fun02(void * arg)
{
    for (int i = 65; i < 91; i++)
    {
        printf("%c\n",i);
        sleep(0.1);

    }
    
}
int main(int argc, char const *argv[])
{
    pthread_t t1;
    pthread_create(&t1,NULL,fun01,NULL);
    pthread_t t2;
    pthread_create(&t2,NULL,fun02,NULL);
    while(1);
    return 0;
}
