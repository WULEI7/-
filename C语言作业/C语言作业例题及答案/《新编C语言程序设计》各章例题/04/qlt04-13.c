#include <stdio.h>
void main(){
   int i1,i2,i3,i4;char c='A'; float f=3.14;double d1,d2;
   long l=1234567890;  //定义了长整型l
   char a[10];         //定义了a字符数组
   printf("Please input:\n");
   scanf("%d",&i1); scanf("%o",&i2); scanf("%x",&i3); scanf("%u",&i4);
   scanf("%f",&f);  scanf("%c",&c);  scanf("%s",a);
   printf("Output1:\n");
   printf("%d,%d,%d,%d,%f,%c,%s\n",i1,i2,i3,i4,f,c,a);
   printf("Please input again:\n");
   scanf("%ld",&l); scanf("%lf",&d1); scanf("%le",&d2);
   printf("Output2:\n%ld,%lf,%le,%20.10lf,%lg\n",l,d1,d2,d2,d2);
}
