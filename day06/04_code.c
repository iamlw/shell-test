#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <string.h>
int main(int argc, char const *argv[])
{
    int fd = open("con.txt",O_RDWR|O_CREAT,0666);
    truncate("con.txt",5);
    char *buf= (char *)mmap(NULL,5,PROT_WRITE,MAP_SHARED,fd,0);
    // buf[3]='c';
    strcpy(buf,"hello");
    munmap(buf,5);

    return 0;
}
