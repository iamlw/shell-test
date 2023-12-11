#include<stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include "02_msg.h"
int main(int argc, char const *argv[])
{
    key_t key01 = ftok("./",10);
    int msgid= msgget(key01,IPC_EXCL);

    if (msgid == -1)
    {
        msgid = msgget(key01,IPC_CREAT | 0666);
    }
    
    MSG m1 = {10,"张三","男",18};
    msgsnd(msgid,&m1,sizeof(MSG)-sizeof(long),0);
    printf("OVER\n");

    return 0;
}
