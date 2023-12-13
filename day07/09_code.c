#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>
void * sale(void * name)
{
    static int ticket = 100;
    char buf[32]= {0};
    strcpy(buf,(char * )name);

    while (ticket >0)
    {
        ticket--;
        printf("%s销售了一张票,还有%d张票\n",buf,ticket);
        sleep(1);
    }
    
}
int main(int argc, char const *argv[])
{
    pthread_t t1,t2,t3,t4;
    pthread_create(&t1,NULL,sale,"一号窗口");
    pthread_create(&t2,NULL,sale,"二号窗口");
    pthread_create(&t3,NULL,sale,"三号窗口");
    pthread_create(&t4,NULL,sale,"四号窗口");
    pthread_detach(t1);
    pthread_detach(t2);
    pthread_detach(t3);
    pthread_detach(t4);
    getchar();

    
    return 0;
}
