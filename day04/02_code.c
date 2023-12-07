#include<stdio.h>
#include<sys/types.h>
#include<signal.h>
#include<unistd.h>
#include<sys/wait.h>
int main(int argc, char const *argv[])
{
    int i = 0;
    while (1)
    {
        printf("无聊\n");
        i++;
        sleep(3);
        if (i>=3)
        {
            printf("拜拜\n");
            raise(SIGKILL);
        }
        
    }
    
    return 0;
}
