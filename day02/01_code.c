#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
int main(int argc, char const *argv[])
{
    int fd = open("a.txt",O_RDWR |O_CREAT | O_APPEND );
    if (fd < 0)
    {
        printf("文件打开失败");
        return 0;
    }
    char buf[]="hello";
    int len = write(fd,buf,sizeof(buf)-1);
    if (len<0)
    {
        printf("写入失败");
    }

    if (close(fd) < 0)
    {
        printf("关闭失败");
    }
    
    
    
    return 0;
}
