#include <stdio.h>
void main(){
   int a,b=322,d; float x,y=8.88; char c1='k',c2;
   a=y;     /*单精度型转整型*/
   x=b;     /*整型转单精度型*/
   d=c1;    /*字符型转整型*/
   c2=b;    /*整型转字符型*/
   printf("%d,%f,%d,%c",a,x,d,c2);
}

