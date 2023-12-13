#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>
void * fun(void * arg)
{
    //打印字符串
    char * str = (char * )arg;
    char b[32]={0};
    strcpy(b,str);
    printf("线程%ld开始执行\n",pthread_self());
    for (int i = 0; i < strlen(b); i++)
    {
        printf("%c\n",b[i]);
        sleep(1);
    }
    printf("线程%ld执行结束\n",pthread_self()); 

    

}
int main(int argc, char const *argv[])
{
    char buf[32]={0};

    while (1)
    {
        printf("请输入字符串\n");
        fgets(buf,32,stdin);
        buf[strlen(buf)-1]=0; 
        if (strcmp(buf,"886") == 0)
        {
            break;
        }
        
        pthread_t t;
        pthread_create(&t,NULL,fun,buf);
    }
    
   
    return 0;
}
