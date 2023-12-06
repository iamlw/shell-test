#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
int main(int argc, char const *argv[])
{
    char str[]="spark";
    write(1,str,sizeof(str)-1);
    return 0;
}
