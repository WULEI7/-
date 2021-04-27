#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
const int maxn=510;
int n,m,k,a[maxn][maxn],b[maxn][maxn],f[maxn][maxn][21];
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	if(k%2==1)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
				cout<<"-1"<<" ";
			cout<<endl;
		}
	}
	else
	{
		k/=2;
		for(int i=1;i<=n;i++)
		for(int j=1;j<m;j++)
			cin>>a[i][j];
		for(int i=1;i<n;i++)
		for(int j=1;j<=m;j++)
			cin>>b[i][j];
		for(int c=1;c<=k;c++)
		for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			f[i][j][c]=1e9;
			if(i>1) f[i][j][c]=min(f[i][j][c],f[i-1][j][c-1]+b[i-1][j]);
			if(i<n) f[i][j][c]=min(f[i][j][c],f[i+1][j][c-1]+b[i][j]);
			if(j>1) f[i][j][c]=min(f[i][j][c],f[i][j-1][c-1]+a[i][j-1]);
			if(j<m) f[i][j][c]=min(f[i][j][c],f[i][j+1][c-1]+a[i][j]);
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
				cout<<f[i][j][k]*2<<" ";
			cout<<endl;
		}
	}
	return 0;
}
