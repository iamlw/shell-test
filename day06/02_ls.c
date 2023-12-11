#include <stdio.h>
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
        MSG m1 ;

    msgrcv(msgid,&m1,sizeof(MSG)-sizeof(long),10,0);
    printf("%s%d岁了\n",m1.name,m1.age);
    return 0;
}
