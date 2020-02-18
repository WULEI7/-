#include <stdio.h>
#define    N    4
void fun(int  (*t)[N])
{  int  j ,r[N];
   for(j=0; j<N; j++)  r[j]=t[0][j];//第一行存入临时数组 
   for(j=0; j<N; j++)
      t[0][N-j-1]=t[j][0];// 第一列成为第一行 
   for(j=0; j<N; j++)
      t[j][0]=t[N-1][j];//最后一行成为第一列 
   for(j=N-1; j>=0;j--)
      t[N-1][N-1-j]=t[j][N-1];//最后一列成为最后一行 
   for(j=N-1; j>=0; j--)
      t[j][N-1]=r[j];// 临时数组成为最后一列 
}

main()
{  int t[][N]={21,12,13,24,25,16,47,38,29,11,32,54,42,21,33,10}, i, j;
   printf("\nThe original array:\n");
   for(i=0; i<N; i++)
   {  for(j=0; j<N; j++)  printf("%2d  ",t[i][j]);
      printf("\n");
   }
   fun(t);
   printf("\nThe result is:\n");
   for(i=0; i<N; i++)
   {  for(j=0; j<N; j++)  printf("%2d  ",t[i][j]);
      printf("\n");
   }
}
