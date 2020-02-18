#include<stdio.h>
main(){
   printf("%f\n ",356.);   //356.实数常量作为double，%f对应于浮点数的输出，详见下一章
   printf("%f\n ",356);    //输出 0.000000，说明整数与%f 不匹配的
   printf("%f\n ",356.0f); // 356.0f 为float
}
