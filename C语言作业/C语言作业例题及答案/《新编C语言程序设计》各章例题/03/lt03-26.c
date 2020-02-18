#include <stdio.h>
void main(){
   int a=2147483647,b; long c; int x= -1; unsigned int y;
   b=a+1; c=(long)a+1L;
   printf("a=%d,b=%d,c=%ld",a,b,c);
   y=x;
   printf("  x=%d,y=%d,y=%u\n",x,y,y);
}

