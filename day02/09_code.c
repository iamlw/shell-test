#include <stdio.h>
#include <sys/types.h>
#include <string.h>
#include <dirent.h>

void blDIR(char *path)
{
    char filePath[256]="";
    strcpy(filePath,path);
    DIR * dir = opendir(filePath);
    if (dir == NULL)
    {
        printf("文件目录打开失败\n");
        return;
    }
    while (1)
    {
        struct dirent *d;
        d=readdir(dir);
        if (d == NULL)
        {
            break;
        }
        if (d->d_type == DT_DIR && strcmp(d->d_name,".")!=0 && strcmp(d->d_name,"..")!=0)
        {
            char newPath[256]="";
            strcpy(newPath,filePath);
            strcat(newPath,"/");
            strcat(newPath,d->d_name);
            printf("%s\n",newPath);
            blDIR(newPath);
        }
        else if (d->d_type == DT_REG)
        {
            
            printf("%s/%s\n",filePath,d->d_name);
        }
        
        
    }
    closedir(dir);
    
}

int main(int argc, char const *argv[])
{
    blDIR("/home/weiliu/shell-test");
    return 0;
}
