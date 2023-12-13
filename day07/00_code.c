#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <pthread.h>
int main(int argc, char const *argv[])
{
    printf("pid = %d\n",getpid());
    printf("tid = %ld\n",pthread_self());
    while (1);
    
    return 0;
}
