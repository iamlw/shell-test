#include <stdio.h>
#include <mysql/mysql.h>
int main(int argc, char const *argv[])
{
    MYSQL mysql;
    mysql_init(&mysql);
    mysql_set_character_set(&mysql,"utf8");
    MYSQL * tag = mysql_real_connect(&mysql,"192.168.174.129","root","123456","mydata",3306,NULL,0);
 
    char sql01[] ="select * from major"; 
    mysql_query(&mysql,sql01);
    MYSQL_RES *res = mysql_store_result(&mysql);
    int column = mysql_num_fields(res);
    int row = mysql_num_rows(res);
    for (int i = 0; i < row; i++)
    {
        MYSQL_ROW row_data = mysql_fetch_row(res);

        for (int j = 0; j < column; j++)
        {
            printf("%s\t\t",row_data[j]);
        }
        printf("\n");
    }

    mysql_free_result(res);

    mysql_close(&mysql);
    printf("OVER\n");
    return 0;
}
