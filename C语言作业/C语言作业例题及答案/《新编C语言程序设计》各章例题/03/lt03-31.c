#include <stdio.h>
void main()
{  int a=1,b=2,c,d,e;
   c=(-a++)+(++b);
   d=(b--)+(++a)+a;
   e=(a/(++b))-(b/(--a));
   printf("c=%d,d=%d,e=%d\n",c,d,e);
}

