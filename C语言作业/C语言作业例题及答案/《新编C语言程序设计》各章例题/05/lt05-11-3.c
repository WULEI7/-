#include <stdio.h>
void main()
{  int a,b,c,max;                  /* 定义变量 */
   printf("Input a,b,c:\n");       /* 提示信息 */
   scanf("%4d%4d%4d", &a, &b, &c); /* 输入函数 */
   max=a>b?a:b;                 /* 求两数的最大值 */
   max=max>c?max:c;             /* 再与k比较，求三数的最大值 */
   printf("The maxmum value of the three data is %d\n", max); /*输出*/
}
