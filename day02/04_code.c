#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
int main(int argc, char const *argv[])
{
    int fd_r = open("a.txt",O_RDONLY);
    if (fd_r < 0)
    {
        printf("待读取文件打开失败\n");
        return 0;
    }
    int fd_w = open("b.txt",O_WRONLY | O_CREAT |O_APPEND,0666);
    if (fd_w < 0 )
    {
        printf("待写入文件打开失败\n");
    }

    while (1)
    {
        char buf[5];
        int len = read(fd_r,buf,sizeof(buf));
        write(fd_w,buf,len);
        if (len < sizeof(buf))
        {
            break;
        }
        
    }
    
    if (close(fd_w)<0)
    {
        printf("待写入文件关闭失败");
    }
        
    if (close(fd_r)<0)
    {
        printf("待读取文件关闭失败");
    }
    printf("over\n");
    
    
    
    return 0;
}
