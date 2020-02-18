#include <stdio.h>
#define MAX(a,b) (a>b)?a:b
main(){
   int x,y,max;
   printf("input two numbers: "); scanf("%d%d",&x,&y);
   max=MAX(x,y);
   printf("max=%d\n",max);
}
