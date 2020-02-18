#include <stdio.h>
main()
{
   int r,m,n,k,t;
   scanf("%d%d",&m,&n);
   if (m<n)
   {t=m;m=n;n=t;}   /*借助变量t，交换两数*/
   k=m*n;
   r=m % n;
   while (r!=0)
   {
      m=n;
      n=r;
      r=m%n;
   }
   printf("%d %d\n",n,k/n); /* 输出最大公约数和最小公倍数*/
}
