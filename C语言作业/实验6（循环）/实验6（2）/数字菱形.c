#include <stdio.h>
int main()
{   int i,j;
   for(i=1;i<=9;i++)
   {
      for (j=8;j>=i;j--) printf(" ");
      for(j=1;j<=2*i-1;j++) printf("%d",i);
      printf("\n");
   }
   for(i=8;i>=1;i--)
   {
      for (j=8;j>=i;j--) printf(" ");
      for(j=1;j<=2*i-1;j++) printf("%d",i);
      printf("\n");
   }
   return 0;
}
