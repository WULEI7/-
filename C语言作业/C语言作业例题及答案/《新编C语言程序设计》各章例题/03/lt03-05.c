#include <stdio.h>
main()
{
   int a,b;              //可改为：unsigned int a,b;
   a=2147483647;         // 是VC++6.0 int最大值
   b=a+1;
   printf("%d,%d\n",a,b);//可改为：printf("%u,%u\n",a,b);
}
