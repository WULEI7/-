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
		int k=0,maxmin=0;
		for(int j=1;j<=n;j++)
			if(vis[j]==0&&dis[j]>maxmin)
			{
				maxmin=dis[j];
				k=j;
			}
		vis[k]=1;
		for(int j=1;j<=n;j++)
			if(vis[j]==0&&dis[j]<min(dis[k],map[k][j]))
				dis[j]=min(dis[k],map[k][j]);
	}//注意这道题是找最大的最小值 
	return dis[n];
}
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t,s=1;
	cin>>t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		memset(dis,0,sizeof(dis));
		memset(map,0,sizeof(map));//这道题map初始化为0，和一般题不同 
		for(int i=0;i<m;i++)
		{
			int a,b,c;
			cin>>a>>b>>c;
			map[a][b]=map[b][a]=c;
		}
		printf("Scenario #%d:\n%d\n\n",s++,dijkstra(n));
	}
	return 0;
}
