#include <stdio.h>
#define M 2
#define N 3
int main()
{
	int a[M][N],b[M][N],c[M][N],i,j;
	printf("Please input matrix A:\n");
	for(i=0;i<M;i++)
		for(j=0;j<N;j++)
			scanf("%d",&a[i][j]);
	printf("Please input matrix B:\n");
	for(i=0;i<M;i++)
		for(j=0;j<N;j++)
			scanf("%d",&b[i][j]);
	for(i=0;i<M;i++)
		for(j=0;j<N;j++)
			c[i][j]=a[i][j]+b[i][j];
	printf("Result matrix C is:\n");
	for(i=0;i<M;i++)
	{
		for(j=0;j<N;j++)
			printf("%d  ",c[i][j]);
		printf("\n");
	}
	return 0;
}
