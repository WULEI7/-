#include <stdio.h>
void main()
{  int a=10,b=20;
   printf("a=%d,b=%d\n",a,b);
   a+=b;       /*��ʱ��a��a+b��ֵ*/
   b=a-b;      /*��ʱ��b��a��ֵ*/
   a-=b;       /*��ʱ��a��b��ֵ*/
   printf("a=%d,b=%d\n",a,b);
}
