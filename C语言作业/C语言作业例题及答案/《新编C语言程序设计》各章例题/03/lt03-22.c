#include <stdio.h>
void main()
{   int a=2;
    a%=4-1; a+=a*=a-=a*=3;
    printf("a=%d\n",a);  /*a=0 �ȼ���a=a+(a=a*(a=a-(a=a*3)))*/
    a=12; a+=a-=a*a;
    printf("a=%d\n",a);  /*a=-264 �ȼ���a=a+(a=a-(a*a))*/
}

