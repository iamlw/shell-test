#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main(int argc, char const *argv[])
{
    printf("当前进程的进程号：%d\n",getpid());
    printf("当前进程的父进程号：%d\n",getppid());
    printf("当前进程的组进程号：%d\n",getpgid(getpid()));
    printf("当前进程的组进程号：%d\n",getpgrp());

    
    
    return 0;
}
