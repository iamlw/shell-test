#include<stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
int main(int argc, char const *argv[])
{
    key_t key01 = ftok("./",230201);
    printf("k1=%u\n",key01);
    int msgid = msgget(key01,IPC_CREAT | 0666);
    printf("msgid=%d\n",msgid);

    int msgid2= msgget(key01,IPC_EXCL);
    printf("msgid2=%d\n",msgid2);

    return 0;
}
