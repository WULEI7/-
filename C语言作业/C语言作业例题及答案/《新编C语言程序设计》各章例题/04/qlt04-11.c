#include<stdio.h>
void main()
{  int p,q; int x=8,y=8;
   p=(x++)+(x++)+(x++); q=(++y)+(++y)+(++y);
   printf("%d %d %d %d\n",p,q,x,y);
}
