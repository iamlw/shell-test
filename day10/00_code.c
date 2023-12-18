#include <stdio.h>
#include <mysql/mysql.h>
int main(int argc, char const *argv[])
{
    MYSQL mysql;
    mysql_init(&mysql);
    mysql_set_character_set(&mysql,"utf8");
    MYSQL * tag = mysql_real_connect(&mysql,"192.168.174.129","root","123456","mydata",3306,NULL,0);
    if (tag == NULL)
    {
        printf("连接失败\n");
    }
    else
    {
        printf("连接成功\n");
        char sql01[] ="insert into major (m_name,m_schoolid) values ('护理',8)"; 
        char sql02[] ="insert into major (m_name,m_schoolid) values ('妇科',8)"; 
        char sql03[] ="select * from major"; 
        int res = mysql_real_query(&mysql,sql02,sizeof(sql02));
        if (res == 0)
        {
            printf("执行成功\n");
        }
        else
        {
            printf("执行失败\n");
        }
    }
    mysql_close(&mysql);
    printf("OVER\n");
    return 0;
}
