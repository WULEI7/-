#include <stdio.h>
int main()
{
	int n,m,i,j,a[1000][1000],b[1000][1000];
	scanf("%d %d",&n,&m);
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			scanf("%d",&a[i][j]);
	for(i=0;i<n;i++)
		for(j=m-1;j>=0;j--)
			b[m-1-j][i]=a[i][j];
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
			printf("%d ",b[i][j]);
		printf("\n");
	}
	return 0;
}
