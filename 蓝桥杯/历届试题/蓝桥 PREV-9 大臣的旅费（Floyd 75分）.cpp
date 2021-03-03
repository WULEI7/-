#include <iostream>
#include <cstdio>
using namespace std;
int dis[1005][1005];
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,a,b,c,maxn=0,ans;
	cin>>n;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
		dis[i][j]=1000000000;
	for(int i=1;i<=n-1;i++)
	{
		cin>>a>>b>>c;
		dis[a][b]=dis[b][a]=c;
	}
	for(int k=1;k<=n;k++)
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	{
		int t=dis[i][k]+dis[k][j];
		if(dis[i][j]>t) dis[i][j]=t;
	}
	for(int i=1;i<n;i++)
	for(int j=i+1;j<=n;j++)
		if(dis[i][j]>maxn) maxn=dis[i][j];
	ans=(maxn+21)*maxn/2;
	cout<<ans<<endl;
	return 0;
}
