#include<stdio.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
int main(int argc, char const *argv[])
{
    int i =0;
    for (i = 0; i < 2; i++)
    {
        int pid = fork();
        if (pid == 0)
        {
            break;
        }
        

    }
    if (i == 0)
    {
        for (int j = 65; j < 91; j++)
        {
            char c=(char)j;
            printf("%c\n",c);
            sleep(1);
        }
        _exit(0);
        
    }
    else if (i==1)
    {
        for (int j = 1; j < 27; j++)
        {
            printf("%d\n",j);
        }
        _exit(0);
        
    }
    else{
        while (1)
        {
            int pid=waitpid(-1,NULL,WNOHANG);
            if (pid <0)
            {
                break;
            }
            
        }
        printf("OVER\n");
    }
    
    
    
    return 0;
}
