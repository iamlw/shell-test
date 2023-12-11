#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
typedef struct info
{
    long type;
    char name[20];
    char text[20];
}INFO;

int main(int argc, char const *argv[])
{
    printf("请输入昵称\n");
    char name[20]={0};
    scanf("%s",&name);
    printf("请输入接收的数据类型\n");
    int rtype=0;
    scanf("%d",&rtype);
    printf("请输入发送的数据类型\n");
    int stype=0;
    scanf("%d",&stype);


    key_t key=ftok("./",66);
    int msgid = msgget(key,IPC_CREAT | 0666);

    int i =0;
    for (i = 0; i < 2; i++)
    {
        int pid = fork();
        if (pid==0)
        {
            break;
        }
        
    }

    if (i == 0)
    {
        while (1)
        {
            INFO info;
            msgrcv(msgid,&info,sizeof(INFO)-sizeof(long),rtype,0);
            printf("%s:%s\n",info.name,info.text);
            if (strcmp("886",info.text)==0)
            {
                break;
            }
            
        }
        _exit(0);
        
    }
    else if (i==1)
    {
        
        while (1)
        {
            INFO info;
            scanf("%s",info.text);
            info.type = stype;
            strcpy(info.name,name);
            msgsnd(msgid,&info,sizeof(INFO)-sizeof(long),0);
            if (strcmp("886",info.text)==0)
            {
                break;
            }
        }
        _exit(0);

    }
    else if (i==2)
    {
        while (1)
        {
            int pid = waitpid(-1,NULL,WNOHANG);
            if (pid == -1)
            {
                break;
            }
            
        }
        
    }
    
    
    
    
    return 0;
}
