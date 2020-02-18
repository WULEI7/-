#include <stdio.h>
int main()
{
   char c1,c2;
   c1=getchar();            /*从键盘输入一个小写字母*/
   printf("%c,%d\n",c1,c1);  /*输出该小写字母及其ASCII码值*/
   c2=c1-32;             /*转换为大写字母*/
   printf("%c,%d\n",c2,c2);  /*输出该大写字母及其ASCII码值*/
   return 0;
}
