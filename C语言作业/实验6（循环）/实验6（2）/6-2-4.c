#include <stdio.h>
int main()
{   int i,j,k; char ch;
   scanf("%c",&ch);
   k=ch-'A'+1;
   for(i=1;i<=k;i++)
   {
      for (j=25;j>=i;j--) printf(" ");
      for(j=1;j<=2*i-1;j++) printf("%c",'A'+i-1);
      printf("\n");
   }
   k=ch-'A';
   for(i=k;i>=1;i--)
   {
      for (j=25;j>=i;j--) printf(" ");
      for(j=1;j<=2*i-1;j++) printf("%c",'A'+i-1);
      printf("\n");
   }
   return 0;
}
