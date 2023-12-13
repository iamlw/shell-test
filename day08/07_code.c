#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>
#include <stdlib.h>
pthread_cond_t cond;
pthread_mutex_t lock;
int num;
const int MAX_NUM = 100;
const int MIN_NUM = 5;

void * produce(void * arg)
{

    while (1)
    {
            sleep(1);

        pthread_mutex_lock(&lock);
        if (num >= MAX_NUM)
        {
            //库存满了
            printf("库存满了,%s开始休假\n",(char *)arg);

            pthread_cond_wait(&cond,&lock);
        }
        else{
            num++;
            printf("%s生产了一个商品,当前库存为%d\n",(char *)arg,num);
            pthread_cond_broadcast(&cond);
        }
        pthread_mutex_unlock(&lock);
    }
    return NULL;
    
}
void * sale(void * arg)
{
    while (1)
    {
        int time = rand()%5;
        sleep(time);
        pthread_mutex_lock(&lock);
        if (num <=MIN_NUM)
        {
            printf("库存不足,%s开始休假\n",(char *)arg);
            pthread_cond_wait(&cond,&lock);
        }
        else
        {
            num--;
            printf("%s销售了一个商品,当前库存为%d\n",(char *)arg,num);

            pthread_cond_broadcast(&cond);
        }
        pthread_mutex_unlock(&lock);

    }
    return NULL;
    
}

void myinit(){
    pthread_mutex_init(&lock,NULL);
    pthread_cond_init(&cond,NULL);
    num = 0;

}
int main(int argc, char const *argv[])
{
    srand(time(NULL));
    myinit();
    pthread_t t1,t2,t3,t4,t5,t6;
    pthread_create(&t1,NULL,produce,"老张");
    pthread_create(&t2,NULL,produce,"老李");

    pthread_create(&t3,NULL,sale,"小红");
    pthread_create(&t4,NULL,sale,"小白");
    pthread_create(&t5,NULL,sale,"小周");
    pthread_create(&t6,NULL,sale,"小丽");

    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
    pthread_join(t3,NULL);
    pthread_join(t4,NULL);
    pthread_join(t5,NULL);
    pthread_join(t6,NULL);
    return 0;
}
