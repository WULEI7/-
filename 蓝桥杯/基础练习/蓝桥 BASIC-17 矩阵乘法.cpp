#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	//freopen("input2.txt","r",stdin);
	int n,m,a[31][31],b[31][31],c[31][31];
	cin>>n>>m;
	for(int i=0;i<n;i++)
	for(int j=0;j<n;j++)
	{
		cin>>a[i][j];
		b[i][j]=a[i][j];
		c[i][j]=0;
	}
	if(m==0)
		for(int i=0;i<n;i++)
			c[i][i]=1;
	else if(m==1)
		for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			c[i][j]=a[i][j];
	else if(m>=2)
		for(int t=1;t<=m-1;t++)
		{
			for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				c[i][j]=0;
			for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				for(int k=0;k<n;k++)
					c[i][j]+=a[i][k]*b[k][j];
			for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				a[i][j]=c[i][j];
		}
	for(int i=0;i<n;i++)
	{
		printf("%d",c[i][0]);
		for(int j=1;j<n;j++)
			printf(" %d",c[i][j]);
		printf("\n");
	}
	return 0;
}
