#include <stdio.h>
main(){
   char c='k';int i=1,j=2,k=3;float x=3e+5,y=0.85;
   printf("%d,%d\n",'a'+5<c,-i-2*j>=k+1);  //请注意各运算的优先级
   printf("%d,%d\n",1<j<5,x-5.25<=x+y);
   printf("%d,%d\n",i+j+k==-2*j,k==j==i+5);
}
