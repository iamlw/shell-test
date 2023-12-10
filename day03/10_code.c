#include<stdio.h>
#include<signal.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
int main(int argc, char const *argv[])
{
    signal(SIGHUP,SIG_IGN);

    int pid = fork();
    if (pid>0)
    {
        return 0;
    }
    setsid();
    chdir("/");
    umask(0002);
    close(0);
    // close(1);
    close(2);
    while (1)
    {
        printf("守护进程输出的内容\n");
        sleep(1);
    }
    
    

    return 0;
}
