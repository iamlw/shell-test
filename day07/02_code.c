#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <pthread.h>
void * fun(void * arg){
    printf("当前线程%ld开始执行\n",pthread_self());
    int * num = (int *) arg;
    sleep(*num);
    printf("线程%ld执行完毕\n",pthread_self()); 
}
void * fun2(void * arg){
    printf("当前线程%ld开始执行\n",pthread_self());
    char * num = (char *) arg;
    printf("arg = %s\n",num);
    sleep(5);
    printf("线程%ld执行完毕\n",pthread_self()); 
}
int main(int argc, char const *argv[])
{
/*     int pthread_create(pthread_t *thread, const pthread_attr_t *attr,void *(*start_routine) (void *), void *arg); */

    pthread_t t;
    int num = 3;
    pthread_create(&t,NULL,fun,&num);

    
    pthread_t t2;
    char str[] = "hello";
    pthread_create(&t2,NULL,fun2,str);
    getchar();

    return 0;
}
