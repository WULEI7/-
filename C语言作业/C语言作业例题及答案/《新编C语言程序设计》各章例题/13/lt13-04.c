#include <stdio.h>
main(){
   unsigned a,b;
   printf("input a number: "); scanf("%d",&a);
   b=a>>5;
   b=b&15;
   printf("a=%d\tb=%d\n",a,b);
}
