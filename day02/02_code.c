#include <stdio.h>
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <fcntl.h>
 #include <unistd.h>
 int main(int argc, char const *argv[])
 {
 //1打开文件
// man 2 系统调用函数名
// int open(const char *pathname, int flags);
 // int open(const char *pathname, int flags, mode_t mode);
 int fileTag = open("a.txt",O_WRONLY| O_CREAT, 0644);
 if (fileTag < 0)
 {
 printf("文件不存在,文件标识符为:%d\n",fileTag);
 return 0;
 }
 printf("文件打开成功,文件标识符为:%d\n",fileTag);
 int tag = close(fileTag);
 if (tag < 0)
 {
 printf("关闭文件失败\n");
 }
 else
 {
 printf("关闭文件成功\n");
}
 return 0;
 }