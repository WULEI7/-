#include <cstdio>
#include <iostream>
using namespace std;
int a[1005][1005];
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
		cin>>a[i][j];
	for(int i=m;i>=1;i--)
	{
		for(int j=1;j<=n;j++)
		{
			printf("%d",a[j][i]);
			if(j!=n) printf(" ");
		}
		printf("\n");
	}
	return 0;
}
