#include <stdio.h>
int main()
{  int day,x1,x2;
   day=0;
   x1=1020;
   while (x1>0)
   {
      x2=x1-x1/2-2;
      x1=x2;
      day++;
   }
   printf("day=%d\n",day);
   return 0;
}
