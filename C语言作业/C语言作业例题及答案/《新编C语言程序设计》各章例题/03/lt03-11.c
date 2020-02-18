#include <stdio.h>
void main()  //从篇幅考虑 #include <stdio.h> 有时在程序前省略，后同
{
   int a,b,c;
   a=5; b=6; c=7;
   printf("  ab  c\tde\rf\n");      //注意\t，\r，\n，\b的含义
   printf("hijk\tL\bM\n");          //\b退格后把L删除了
   printf("012x4y8s3\0614w2\n");    //\061为字符'1'。注意: \ddd，d为八进制数字
   printf("012x4y8s3\0674w2\n");    //\067为字符'7'
   printf("012x4y8s3\0684w\1342\n");//\06为字符红桃符，\134为'\'字符
   printf("012x4y8s3\084w2\n");     //\0字符串结束标志,即空字符
   printf("\n"); 
}  //请注意字符串中转义符的存在情况，请仔细核查运行结果

