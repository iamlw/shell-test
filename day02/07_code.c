#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
int main(int argc, char const *argv[])
{ 
    struct stat buf;
    int tag = stat("a.txt",&buf);
    if (tag < 0)
    {
        printf("读取失败\n");
        return 0;
    }
    if (S_ISREG(buf.st_mode))
    {
        printf("是文件\n");

    }else if (S_ISDIR(buf.st_mode))
    {
        printf("是目录\n");
    }
    printf("文件大小为：%ld\n",buf.st_size);
    
    


    
    return 0;
}
