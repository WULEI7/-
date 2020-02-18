#include <stdio.h>
void main(){
   float pi=3.14159;// 编译时显示类型转化警告信息
   int s,r=5;
   s=r*r*pi;        // 编译时显示类型转化警告信息
   printf("s=%d\n",s);
}
