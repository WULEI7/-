#include <stdio.h>
main(){
   int a,b,max;
   printf("input two numbers: ");scanf("%d%d",&a,&b);
   max=a;                 // 意思是先假设a为最大（这种做法常用）
   if (max<b) max=b;      // 然后用当前的最大值max与b作比较
   printf("max=%d\n",max);// 输出两者的最大值
}
