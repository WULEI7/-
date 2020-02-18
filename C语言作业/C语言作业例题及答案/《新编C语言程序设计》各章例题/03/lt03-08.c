#include <stdio.h>
main(){
   union       //定义共用体变量u1，详见后续章节
   {  int i;   // int i与float f共用4个字节
      float f; // i与f共用，意味着存入f，可以以整型数据看待来通过i输出。
   } u1;
   u1.f=(float)120.5;
   printf("%d  %o   %x\n",u1.i,u1.i,u1.i);
}
