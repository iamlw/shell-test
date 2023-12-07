#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
#include<unistd.h>
#include<sys/wait.h>
int main(int argc, char const *argv[])
{
    printf("无聊中\n");
    alarm(4);
        while (1)
    {    
        for (int i = 3; i >0; i--)
        {
            sleep(1);

            printf("倒计时：%d\n",i);
        }
        
    }
    pause();


    return 0;
}
