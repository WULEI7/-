#include <math.h>
#include <stdio.h>
void main()
{  float b,c,arg,area;            /*定义实型变量*/
   printf("Please input b, c ,arg:");
   scanf("%f%f%f", &b, &c, &arg); /*从键盘输入三个实数，其中arg为弧度*/
   area = b*c*sin(arg)/2;
   printf("area = %0.2f\n", area);/*0.2表示保留两位小数输出*/
}
