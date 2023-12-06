#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
int main(int argc, char const *argv[])
{
    int fd = open("a.txt",O_WRONLY | O_CREAT,0765);
    if (fd < 0)
    {
        printf("打开文件失败\n");
    }
    printf("fd = %d\n",fd);

    int x = close(fd);
    printf("x = %d\n",x);
    if  (x < 0 )
    {
        printf("关闭失败\n");
    }
    
    
    return 0;
}
