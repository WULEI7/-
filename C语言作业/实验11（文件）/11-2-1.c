#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void main()
{  int x[1000],i,k;
FILE *fp2;
srand((unsigned) time(NULL));
for(i=0;i<1000;i++) x[i]=rand();
fp2=fopen("data2.dat","wt");
if (fp2==NULL)
{
   printf("Open error \n");exit(0);
}
for(k=0;k<1000;k++) fwrite(&x[k],sizeof(int),1000,fp2);
fclose(fp2);
}
