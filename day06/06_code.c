#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>
int main(int argc, char const *argv[])
{
    key_t key = ftok("./",66);
    int shmid = shmget(key,10,IPC_CREAT | 0666);
    char * buf = shmat(shmid,NULL,0);
    strcpy(buf,"hello\0world");
    shmdt(buf);
    return 0;
}
