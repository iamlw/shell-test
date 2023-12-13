#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
void * fun (void * arg)
{
    printf("线程开始\n");
    sleep(5);
    printf("线程结束\n");

}
int main(int argc, char const *argv[])
{
    pthread_t t;
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    int status = 0;
    pthread_attr_getdetachstate(&attr,&status);
    

    return 0;
}
