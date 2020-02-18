#include <stdio.h>
main(){
   int i=1; while(i<=5) printf("%d\n",SQ(i++));
}
SQ(int y)
{
   return((y)*(y));
}
