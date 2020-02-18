#include <stdio.h>
void main()
{  int a,b,c,x,y=7; float z=4;
   printf("表达式=%d ",(a=3*5,a*4));     printf("a=%d ",a);/*a=15,逗号表达式60*/
   printf("表达式=%d ",(a=3*5,a*4,a+5)); printf("a=%d ",a);/*a=15,逗号表达式20*/
   printf("\n表达式=%d ",(x=(a=3,6*3))); printf("x=%d ",x);/*赋值表达式18,x=18*/
   printf("表达式=%d ",(x=a=3,6*a));     printf("x=%d ",x);/*逗号表达式18,x=3*/
   a=1;b=2;c=3;
   printf("\n%d,%d,%d ",a,b,c);     /*1,2,3*/
   printf("%d,%d,%d ",(a,b,c),b,c); /*3,2,3*/
   x=(y=y+6,y/z);
   printf("\nx=%d,y=%d\n",x,y);     /* x=3,y=13*/
}
