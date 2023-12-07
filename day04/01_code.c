#include<stdio.h>
#include<sys/types.h>
#include<signal.h>
#include<unistd.h>
#include<sys/wait.h>
int main(int argc, char const *argv[])
{
    int pid = fork();
    if (pid == 0)
    {
        while (1)
        {
            printf("在玩\n");
            sleep(1);
        }
        _exit(0);
    }
    else if (pid > 0)
    {
        printf("写作业去\n");
        sleep(3);
        kill(pid,SIGKILL);
        wait(NULL);
        printf("%d没了\n",pid);
    }
    
    return 0;
}
