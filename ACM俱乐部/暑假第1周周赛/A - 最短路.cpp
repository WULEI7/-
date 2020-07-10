#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;
int vis[105],dis[105],map[105][105];
int dijkstra(int n)
{
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=n;i++)
		dis[i]=map[1][i];
	for(int i=1;i<n;i++)
	{
		int k=0,minn=99999999;
		for(int j=1;j<=n;j++)
			if(vis[j]==0&&dis[j]<minn)
			{
				minn=dis[j];
				k=j;
			}
		vis[k]=1;
		for(int j=1;j<=n;j++)
			if(vis[j]==0&&dis[j]>dis[k]+map[k][j])
				dis[j]=dis[k]+map[k][j];
	}
	return dis[n];
}
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m;
	while(cin>>n>>m)
	{
		if(n==0) break;
		memset(dis,0,sizeof(dis));
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(i==j) map[i][j]=0;
				else map[i][j]=99999999;
		for(int i=0;i<m;i++)
		{
			int a,b,c;
			cin>>a>>b>>c;
			map[a][b]=map[b][a]=c;
		}
		cout<<dijkstra(n)<<endl;
	}
	return 0;
}
