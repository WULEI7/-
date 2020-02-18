#include <stdio.h>
#define SQ(y) ((y)*(y))
main(){
   int i=1;
   while(i<=5) printf("%d\n",SQ(i++));
}
