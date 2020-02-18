#include <stdio.h>
void main()
{  int i;long int l;short si;unsigned int ui;char c;float f;double d;/*定义变量*/
   i =1023; l =2222; si =123; ui =1234; c ='x'; /*变量赋值*/
   f =(float)3.1415926535898; d=3.1415926535898;
   printf("i(d)=%d\n",i);printf("i(o)=%o\n",i);printf("i(x)=%x\n",i);/*输出变量值*/
   printf("l  =%ld\n",l); printf("si =%d\n",si); printf("ui =%u\n",ui);
   printf("c  =%c\n",c); printf("f  =%f\n",f);
   // f为单精度实数，不能保存足够精度，显示13位小数至多6位有效
   printf("f  =%14.13f\n",f);
   printf("d  =%14.13f\n",d); //d为双精度实数，能13位小数有效
   printf("f  =%7.3f\n",f);
   printf("-d =%-+6.4f\n",-d);
}
