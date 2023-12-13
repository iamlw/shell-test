#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
void * fun(void *arg){
    printf("线程%ld开始执行\n",pthread_self());\
    for (int i = 0; i < 5; i++)
    {
        printf("线程%ld\ti=%d\n",pthread_self(),i);

    }
    printf("线程%ld执行完毕\n",pthread_self());
    return "成功了"; 
    
}
int main(int argc, char const *argv[])
{
    pthread_t t;
    pthread_create(&t,NULL,fun,NULL);
    void *v=NULL;
    pthread_join(t,&v);
    printf("over\n");
    char * str =(char *)v;
    printf("v= %s\n",str);
    return 0;
}
