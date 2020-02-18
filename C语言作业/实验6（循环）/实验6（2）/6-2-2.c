#include <stdio.h>
main()
{  int i,n;
	float t,s=0; 
   scanf("%d",&n);
   for(i=1;i<=n;i++)
   {
   t=(float)1/i;
   s=s+t;
   }    //观察s,t的值的变化来查找问题
   printf("s=%f\n",s);
}
