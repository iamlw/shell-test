#include <stdio.h>
#include <unistd.h>
int main(int argc, char const *argv[])
{
        
    printf("准备子进程创建\n");
    int pid = fork();
    printf("子进程创建成功\n");

    return 0;
}
