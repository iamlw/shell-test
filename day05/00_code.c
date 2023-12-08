#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
 #include <unistd.h>
int main(int argc, char const *argv[])
{
    int fd01 = open("info.txt",O_WRONLY | O_CREAT,0666);
    int fd02 = dup(fd01);
    printf("fd01=%d\n",fd01);
    printf("fd02=%d\n",fd02);
    write(fd02,"hello dup",9);
    close(fd01);
    close(fd02);
    return 0;
}
