#include <stdio.h>
int main()
{   int i,j,k; char ch;
   scanf("%c",&ch);
   k=ch-'A'+1;
   for(i=1;i<=k;i++)
   {
      	for (j=k-1;j>=i;j--) printf(" ");
      	for(j=1;j<=i;j++) printf("%c",'A'+j-1);
      	for(j=i-1;j>=1;j--) printf("%c",'A'+j-1);
      	printf("\n");
   }
   k=ch-'A';
   for(i=k;i>=1;i--)
   {
      	for (j=k;j>=i;j--) printf(" ");
      	for(j=1;j<=i;j++) printf("%c",'A'+j-1);
      	for(j=i-1;j>=1;j--) printf("%c",'A'+j-1);
      	printf("\n");
   }
   return 0;
}
