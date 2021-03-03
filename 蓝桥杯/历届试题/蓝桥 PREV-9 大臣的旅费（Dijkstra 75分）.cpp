#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int map[10005][10005];
int n,vis[10005],dis[10005];
void dijkstra(int x)
{
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=n;i++)
		dis[i]=map[x][i];//以x为原点 
	for(int i=1;i<=n;i++)
	{
		int k=0,minn=1999999999;
		for(int j=1;j<=n;j++)
			if(vis[j]==0&&dis[j]<minn)
			{
				minn=dis[j];
				k=j;
			}
		if(k==0) break;
		vis[k]=1;
		for(int j=1;j<=n;j++)
			if(vis[j]==0&&dis[j]>dis[k]+map[k][j])
				dis[j]=dis[k]+map[k][j];
	}
}//最短路径问题，dijkstra算法 
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int a,b,c,maxn=0,ans;
	cin>>n;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
		map[i][j]=1000000000;
	for(int i=1;i<=n-1;i++)
	{
		cin>>a>>b>>c;
		map[a][b]=map[b][a]=c;
	}
	for(int i=1;i<n;i++)
	{
		dijkstra(i);
		for(int j=i+1;j<=n;j++)
		{
			if(dis[j]>maxn) maxn=dis[j];
		}
	}
	ans=(maxn+21)*maxn/2;
	cout<<ans<<endl;
	return 0;
}
