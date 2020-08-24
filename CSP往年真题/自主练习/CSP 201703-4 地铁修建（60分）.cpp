#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;
int vis[1005],dis[1005],map[1005][1005];
int dijkstra(int n)
{
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=n;i++)
		dis[i]=map[1][i];
	for(int i=1;i<n;i++)
	{
		int k=0,minmax=999999999;
		for(int j=1;j<=n;j++)
			if(vis[j]==0&&dis[j]<minmax)
			{
				minmax=dis[j];
				k=j;
			}
		vis[k]=1;
		for(int j=1;j<=n;j++)
			if(vis[j]==0&&dis[j]>max(dis[k],map[k][j]))
				dis[j]=max(dis[k],map[k][j]);
	}//注意这道题是找最小的最大值 
	return dis[n];
}
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	{
		if(i==j) map[i][j]=0;
		else map[i][j]=999999999;
	}//图的初始化 
	for(int i=0;i<m;i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		map[a][b]=map[b][a]=c;
	}
	printf("%d\n",dijkstra(n));
	return 0;
}
