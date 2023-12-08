#include <stdio.h>
#include <unistd.h>
int main(int argc, char const *argv[])
{
    printf("艾欧尼亚");
    int pid = fork();
    printf("，昂扬不灭\n");

    if (pid == 0)
    {
        
    }
    else if (pid > 0)
    {
        while (1);
    }
    
    return 0;
}
