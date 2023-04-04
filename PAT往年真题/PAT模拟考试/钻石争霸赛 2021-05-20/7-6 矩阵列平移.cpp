#include <iostream>
#include <cstdio>
using namespace std;
int a[105][105],n,k,x;
int main()
{
	scanf("%d %d %d",&n,&k,&x);
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
		scanf("%d",&a[i][j]);
	int r=0;
	for(int j=2;j<=n;j+=2)
	{
		r=r%k+1;
		for(int i=n;i>r;i--)
			a[i][j]=a[i-r][j];
		for(int i=1;i<=r;i++)
			a[i][j]=x;
	}
	/*
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
			printf("%d ",a[i][j]);
		printf("\n");
	}
	*/
	for(int i=1;i<=n;i++)
	{
		int sum=0;
		for(int j=1;j<=n;j++)
			sum+=a[i][j];
		printf("%d",sum);
		if(i<n) printf(" ");
	}
	return 0;
}
