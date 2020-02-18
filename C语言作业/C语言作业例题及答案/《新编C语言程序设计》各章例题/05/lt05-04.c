#include <stdio.h>
main(){
   int a, b; printf("input two numbers: ");
   scanf("%d%d",&a,&b);
   if(a>b)         // 直接比较，根据比较情况得到最大值
      printf("max=%d\n",a);
   else printf("max=%d\n",b);
} 
