#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
int main(int argc, char const *argv[])
{
    //O_NONBLOCK  非阻塞
    int fd = open("/dev/tty",O_RDONLY );
    char buf[5]="";
    printf("请输入：\n");
    int len = read(fd,buf,5);
    close(fd);
    printf("buf = %s",buf);

    return 0;
}
