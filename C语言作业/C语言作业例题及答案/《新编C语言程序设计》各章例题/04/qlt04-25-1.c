#include <stdio.h>
void main()  /*main函数根据输入的半径，输出圆的面积和周长*/
{  float r,area,circumference;     /*定义实数变量*/
   printf("Please input r:");      /*显示提示信息*/
   scanf("%f",&r);                 /*从键盘读取一个实数r*/
   area= 3.1415926 * r * r;        /*计算面积并赋给area变量*/
   circumference=2*3.1415926*r;    /*计算周长并赋给circumference变量*/
   printf("area = %f\n", area);    /*输出面积*/
   printf("circumference = %f\n",circumference); /*输出周长*/
}

