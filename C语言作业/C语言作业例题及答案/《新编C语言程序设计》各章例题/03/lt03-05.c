#include <stdio.h>
main()
{
   int a,b;              //�ɸ�Ϊ��unsigned int a,b;
   a=2147483647;         // ��VC++6.0 int���ֵ
   b=a+1;
   printf("%d,%d\n",a,b);//�ɸ�Ϊ��printf("%u,%u\n",a,b);
}
