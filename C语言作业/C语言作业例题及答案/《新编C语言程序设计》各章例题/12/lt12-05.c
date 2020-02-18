#include <stdio.h>
#define SQ(y) (y)*(y)
main(){
   int a,sq;
   printf("input a number:    ");
   scanf("%d",&a);
   sq=SQ(a+1);
   printf("sq=%d\n",sq);
}
