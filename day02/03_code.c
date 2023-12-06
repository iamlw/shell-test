#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
int main(int argc, char const *argv[])
{
    int fd = open("a.txt",O_RDONLY);
    char buf[20]="";
    int len = read(fd,buf,20);
    buf[len] = '\0';
    printf("读到了%d个\n",len);
    printf("buf=%s\n",buf);
    close(fd);
    
    return 0;
}
