#include <stdio.h>
main(){
   int a,b,c,max,min;
   printf("input three numbers: ");  scanf("%d%d%d",&a,&b,&c);
   if(a>b)
      {max=a;min=b;}
   else
      {max=b;min=a;}
   if(max<c)                                                  if(max<c)max=c;
      max=c;   //此时c不可能是最小,min保持不变               if(min>c)min=c;
   else
      if(min>c)
         min=c;//此时c不可能是最大,max保持不变
      //else; 可省略，此分支c不大不小，不影响最大或最小数
   printf("max=%d\nmin=%d\n",max,min);
}
类似的求三个数的最大值，可以用条件表达式来简单实现，程序如下：
void main()
{  int a,b,c,max;                  /* 定义变量 */
   printf("Input a,b,c:\n");       /* 提示信息 */
   scanf("%4d%4d%4d", &a, &b, &c); /* 输入函数 */
   max=a>b?a:b;                 /* 求两数的最大值 */
   max=max>c?max:c;             /* 再与k比较，求三数的最大值 */
   printf("The maxmum value of the three data is %d\n", max); /*输出*/
}
