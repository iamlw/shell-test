#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
int main(int argc, char const *argv[])
{
    int pid =fork();
    if (pid == 0)
    {
        printf("pid=%d\tppid=%dtpgid=%d\n",getpid(),getppid(),getpgrp());
        setpgid(getpid(),getpid());
        printf("pid=%d\tppid=%dtpgid=%d\n",getpid(),getppid(),getpgrp());
        _exit(0);
    }
    else if (pid > 0)
    {
        wait(NULL);
        printf("OVER\n");
    }
    
    
    return 0;
}
