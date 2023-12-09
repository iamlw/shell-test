#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
int main(int argc, char const *argv[])
{
    int i = 0;
    for(i = 0; i < 2; i++)
    {
        int pid = fork();
        if(pid == 0)
        {
            break;
        }
    }

    if(i == 0)
    {
        //子进程1:打印字母
        for(int j = 65; j < 91; j++)
        {
            char c = (char) j;
            
            printf("%c\n",c);
            sleep(1);
        }
        _exit(0);
    }
    else if(i == 1)
    {
        //子进程2:打印数字
        for(int j = 0; j < 26; j++)
        {
            printf("%d\n",j);
            sleep(1);
        }
        _exit(0);
    }
    else{
        //主进程,回收子进程
        while(1)
        {
            int pid = waitpid(-1,NULL,WNOHANG);
            if (pid < 0)
            {
                break;
            }
            
        }
        printf("OVER\n");
    }
    return 0;
}
