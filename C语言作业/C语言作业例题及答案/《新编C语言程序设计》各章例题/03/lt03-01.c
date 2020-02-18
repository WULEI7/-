#define PRICE 30      // 定义符号常量PRICE
#include <stdio.h>
main()
{
   int total;
   const int num=10;  // 定义常变量num，以后num的值不能再改变
   total=num* PRICE;  // 两个常量乘运算
   printf("total=%d",total);  // %d对应于整型量的输出，详见下一章
}
