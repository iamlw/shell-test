#include<stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
int main(int argc, char const *argv[])
{
    key_t k1 = ftok("./",230201);
    printf("k1=%u\n",k1);
    return 0;
}
