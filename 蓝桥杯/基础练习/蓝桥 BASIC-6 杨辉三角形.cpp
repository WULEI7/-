#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int n,a[35][35];
	cin>>n;
	a[1][1]=1;
	for(int i=2;i<=n;i++)
	{
		a[i][1]=a[i][i]=1;
		for(int j=2;j<i;j++)
			a[i][j]=a[i-1][j-1]+a[i-1][j];
	}
	for(int i=1;i<=n;i++)
	{
		printf("1");
		for(int j=2;j<=i;j++)
			printf(" %d",a[i][j]);
		printf("\n");
	}
	return 0;
}
