#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>
int main(int argc, char const *argv[])
{
    DIR *dir=opendir("/home/weiliu/shell-test/day02");
    if (dir ==NULL)
    {
        printf("打开失败");
        return 0;
    }
    while (1)
    {
        struct dirent * p;
        p = readdir(dir);
        if (p==NULL)
        {
            break;
        }
        if (strcmp(p->d_name,".")==0 || strcmp(p->d_name,"..")==0)
        {
            continue;
        }
        
        printf("%s\n",p->d_name);
    }
    

    closedir(dir); 
    return 0;
}
