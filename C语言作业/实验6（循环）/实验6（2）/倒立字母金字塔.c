#include <stdio.h>
int main()
{   int i,j,k; char ch;
   scanf("%c",&ch);
   k=ch-'A'+1;
   for(i=k;i>=1;i--)
   {
      for (j=k-1;j>=i;j--) printf(" ");
      for(j=1;j<=2*i-1;j++) printf("%c",'A'+k-i);
      printf("\n");
   }
   return 0;
}
