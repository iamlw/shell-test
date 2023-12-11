#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
typedef struct info{
    long type;
    char name[30];
    char text[128];
}INFO;
int main(int argc, char const *argv[])
{
    //1,提示用户输入必须的信息
    //1.1用户昵称
    printf("请输入您的昵称:\n");
    char name[30] = {0};
    scanf("%s",&name);
    //1.2接收的数据类型
    printf("请输入接收的数据的数据类型\n");
    int rtype = 0;
    scanf("%d",&rtype);
    //1.3发送的数据类型
    printf("请输入发送的数据的数据类型\n");
    int stype = 0;
    scanf("%d",&stype);
    //2,创建消息队列
    //2.1获取唯一key值
    key_t key = ftok("./",88);
    //2.2创建或获取消息队列
    int msgid = msgget(key,IPC_CREAT|0666);
    //3,创建2个子进程,一个进程用于发送消息,一个进程用于接收消息
    int i = 0;
    for(i = 0; i < 2; i++)
    {
        int pid = fork();
        if(pid == 0)
        {
            break;
        }
    }
    
    if(i == 0)
    {
        //接收消息
        while(1)
        {
            INFO info;
            msgrcv(msgid,&info,sizeof(INFO)-sizeof(long),rtype,0);
            printf("%s:%s\n",info.name,info.text);
            if (strcmp("886",info.text) == 0)
            {
                break;
            }
        }
        _exit(0);
    }
    else if(i == 1)
    {
        //发送消息
        while (1)
        {
            INFO info;
            scanf("%s",info.text);
            info.type = stype;
            strcpy(info.name,name);
            msgsnd(msgid,&info,sizeof(INFO)-sizeof(long),0);
            if (strcmp("886",info.text) == 0)
            {
                break;
            }
        }
        _exit(0);
    }
    else if(i == 2)
    {
        //4,收回子进程
        while(1)
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