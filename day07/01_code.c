#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <pthread.h>
void * fun(void * arg){
    printf("当前线程的线程号为：%ld\n",pthread_self());
    sleep(5);
    printf("线程%ld执行完毕\n",pthread_self()); 
}
int main(int argc, char const *argv[])
{
/*     int pthread_create(pthread_t *thread, const pthread_attr_t *attr,void *(*start_routine) (void *), void *arg); */
    pthread_t t1;
    printf("当前主线程的线程号为：%ld\n",pthread_self());

    pthread_create(&t1,NULL,fun,NULL);
    while(1);
    return 0;
}
