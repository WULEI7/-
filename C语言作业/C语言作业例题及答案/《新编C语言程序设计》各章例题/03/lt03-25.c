#include <stdio.h>
void main(void)
{  printf("Data type      Number of bytes\n");
   printf("------------   -------------------\n");
   printf("char           %d\n", sizeof(char));
   printf("int            %d\n", sizeof(int));
   printf("short int       %d\n", sizeof(short));
   printf("long int        %d\n", sizeof(long));
   printf("float           %d\n", sizeof(float));
   printf("double         %d\n", sizeof(double));
   printf("3.1415         %d\n", sizeof(3.1415)); //常量也能显示其占用字节数
}  // 请能自己运行显示程序结果

