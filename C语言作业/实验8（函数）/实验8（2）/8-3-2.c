#include <stdio.h>
int sum(int x[],int n)
{  int i,s=0;
   for (i=0;i<n;i++)
      s=s+x[i];
   return s;
}
int main()
{   int i,i1,i2,result, x[10];
   for(i=0;i<10;i++) scanf("%d",&x[i]);
   scanf("%d%d",&i1,&i2);
   result=sum(x+i1,i2-i1+1);
printf("Sum=%d\n",result);
return 0;
}
