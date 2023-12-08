#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
 #include <unistd.h>
int main(int argc, char const *argv[])
{
    int fd = open("con.txt",O_WRONLY | O_CREAT,0666);
    dup2(fd,1);
    printf("dup2\n");

    return 0;
}
