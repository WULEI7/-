#include <stdio.h>
void main(){
   int i=5,j=5,p,q;
   p=(i++)+(i++); q=(++j)+(++j);
   printf("%d,%d,%d,%d",p,q,i,j);
}

