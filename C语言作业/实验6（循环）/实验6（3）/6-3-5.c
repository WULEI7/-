#include <stdio.h>
main()
{
   int i,j;
   for (i=0;i<=9;i++)
   {
      j=i*10+6;
      if (j%3!=0)
         continue;
      printf("%d ",j);
   }
}
