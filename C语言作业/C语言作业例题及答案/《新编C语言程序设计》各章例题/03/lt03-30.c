#include <stdio.h>
void main()
{  int a=10,b=20;
   printf("a=%d,b=%d\n",a,b);
   a+=b;       /*此时，a有a+b的值*/
   b=a-b;      /*此时，b有a的值*/
   a-=b;       /*此时，a有b的值*/
   printf("a=%d,b=%d\n",a,b);
}
