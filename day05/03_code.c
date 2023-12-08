#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
int main(int argc, char const *argv[])
{
    //将进程1的数据发送给进程2
    //1,创建管道
    int fd[2];
    pipe(fd);
    //2,创建进程1与进程2
    int i = 0;
    for(i = 0; i < 2; i++)
    {
        int pid = fork();
        if (pid == 0)
        {
            break;
        }
    }
    //3,根本执行进程需要执行的任务
    if(i == 0)
    {
        //子进程1,发送数据
        //读无用,关闭
        close(fd[0]);
        //写数据
        char buf[] = "hello 2";
        write(fd[1],buf,sizeof(buf));
        //发送完毕关闭写
        close(fd[1]);
        //退出当前进程
        _exit(0);
    }
    else if(i == 1)
    {
        //子进程2,接收数据
        //写无用,关闭
        close(fd[1]);
        //读取数据
        char buf[100] = {0};
        read(fd[0],buf,sizeof(buf));
        //读取完毕,关闭读
        close(fd[0]);
        printf("进程2读取到的数据:%s\n",buf);
        _exit(0);
    }
    else if(i == 2)
    {
        //当前进程
        //回收所有子进程
        while(1)
        {
            int pid = waitpid(-1,NULL,WNOHANG);
            if(pid == -1)
            {
                break;
            }
        }
    }
    return 0;
}