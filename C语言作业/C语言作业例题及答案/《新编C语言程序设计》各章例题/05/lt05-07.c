#include <stdio.h>
main(){
   int a,b;  printf("please input A,B: ");
   scanf("%d%d",&a,&b);
   if(a==b) printf("A=B\n");
   else if(a>b) printf("A>B\n");
        else printf("A<B\n");
}
