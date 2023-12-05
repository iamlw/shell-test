#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
int main(int argc, char const *argv[])
{
    open("a.txt",O_WRONLY | O_CREAT,0765);
    return 0;
}
