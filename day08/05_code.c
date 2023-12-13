#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
void * show_num(void * arg)
{
    for (int i = 1; i < 53; i++)
    {
        printf("%d\n",i);
    }
    return NULL;
    
}
void * show_char(void * arg)
{
    for (int i = 97; i < 123; i++)
    {
        char  c=(char )i;
        printf("%c\n",i);
    }
    return NULL;

    
}
int main(int argc, char const *argv[])
{
    pthread_t t1,t2;
    pthread_create(&t1,NULL,show_num,NULL);
    pthread_create(&t2,NULL,show_char,NULL);

    pthread_join(t1,NULL);
    pthread_join(t2,NULL);

    return 0;
}
