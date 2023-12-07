#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
#include<unistd.h>
#include<sys/wait.h>
int main(int argc, char const *argv[])
{
    printf("3s后自杀\n");
    sleep(3);
    abort();
    printf("OVER\n");
    
    return 0;
}
