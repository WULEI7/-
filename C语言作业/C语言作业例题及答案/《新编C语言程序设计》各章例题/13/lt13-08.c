#include <stdio.h>
void main()
{  unsigned a,b,c; int m=5,n=4;
   printf("please enter a:");
   scanf("%o",&a);
   b=a>>(m-1);
   c=b & 0x000f; // »ò c=b & ~(~0<<n);
   printf("%o,%d\n%o,%d\n",a,a,c,c);
}
