#include <stdio.h>
int main()
{
int a,b,max;              /* 变量定义 */
scanf("%d,%d",&a,&b);     /* 输入变量值 */
max=a;                  /* 先把a作为较大数 */
if(max<b) max=b;         /* 通过比较判读较大数是否是b */
printf("max=%d",max);     /* 输出较大数 */
return 0;
}
