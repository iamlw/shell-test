#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <sys/types.h>
void fun01()
{
    printf("11\n");
}
void fun02()
{
    printf("22\n");
}
void fun03()
{
    printf("33\n");
}
int main(int argc, char const *argv[])
{
    atexit(fun01);
    atexit(fun02);
    atexit(fun03);
    return 0;
}
