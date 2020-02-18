#include <stdio.h>
void main() 
{  int a, b;
   scanf("%d%*c%d", &a, &b); //%*有跳过第2输入值的功能
   printf("a = %d, b = %d\n", a, b);
}
