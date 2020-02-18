#include <stdio.h>
main()
{  long long int i=1,n,s=1;
   printf("Please enter n:");
   scanf("%d",&n);
   for(i=1;i<=n;i++)
      s=s*i;   //随着n的增大，观察s值的变化来查找问题
   printf("%d!=%lld\n",n,s);
}
