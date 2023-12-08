#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
int main(int argc, char const *argv[])
{
    int pid = fork();
    if (pid == 0)
    {
        sleep(3);
        printf("子进程执行完毕\n");
        // exit(10);
        _exit(100);
    }
    else if (pid > 0)
    {
        int num = 0;
        wait(&num);
        printf("父进程执行完毕\n");
        printf("num = %d\n",num);
        printf("子进程是否正常退出：%d\n",WIFEXITED(num));
        printf("子进程结束的状态码：%d\n",WEXITSTATUS(num));
        

    }
    
    
    return 0;
}
