#include<stdio.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char const *argv[])
{
 
    int i;
    for (i = 0; i < 3; i++)
    {
        int pid = fork();
        if (pid == 0)
        {
            break;
        }
        else
        {
            printf("创建进程%d\n",pid);
        }     
    }
    if (i == 0)
    {
        printf("创建第一个进程\n");
        _exit(10);
    }
    else if (i == 1)
    {
        printf("创建第二个进程\n");
        _exit(20);

    }    
    else if (i == 2)
    {
        printf("创建第三个进程\n");
        _exit(30);

    }
    else
    {
        printf("主进程:%d\n",getpid());
        while (1)
        {
            int status = 0;
            int pid = waitpid(0,&status,WNOHANG);

            if (pid == 0)
            {
                
            }
            else if (pid > 0)
            {
                printf("子进程%d被回收\n",pid);
            }
            else if (pid < 0)
            {
                break;
            }
            
            
            
        }
        

    }
    
    
    
    return 0;
}
