#include<stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
 #include <unistd.h>
int main(int argc, char const *argv[])
{
    int fd[2];
    pipe(fd);

    int i=0;
    for (int i = 0; i < 2; i++)
    {
        int pid = fork();
        if (pid == 0)
        {
            break;
        }    
    }
    if (i == 0)
    {
        close(fd[0]);
        char buf[]="hello";
        write(fd[1],buf,sizeof(buf));
        close(fd[1]);
        _exit(0);
    }
    else if (i == 1)
    {
        close(fd[1]);
        char buf[100]={0};
        read(fd[0],buf,sizeof(buf));
        close(fd[0]);
        printf("进程2读取到的数据:%s\n",buf);

        _exit(0);
    }
    else if (i == 2)
    {
        while (1)
        {
            int pid = waitpid(-1,NULL,WNOHANG);
            if (pid == -1)
            {
                break;
            }
            
        }
        

    }
    
    

    return 0;
}
