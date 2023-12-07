#include <stdio.h>
#include <unistd.h>
int main(int argc, char const *argv[])
{
        
    printf("准备子进程创建\n");
    int pid = fork();
    if (pid == 0)
    {
        //子进程代码
        printf("子进程代码\n");

    }
    else if (pid > 0)
    {
        //父进程代码
        printf("父进程代码\n");

    }
    else{
        //创建失败
        printf("创建失败\n");

    }
    
    
    // printf("子进程创建成功,进程号为：%d\n",pid);

    return 0;
}
