#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#define inf 99999999
using namespace std;
int vis[1005],dis1[1005],dis2[1005],map[1005][1005];
void dijkstra(int x,int n,int dis[])//添加数组参数dis，因为这里要算n头牛的最短路径 
{
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=n;i++)
		dis[i]=map[x][i];//注意以x为原点 
	for(int i=1;i<n;i++)
	{
		int k=0,minn=inf;
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
}//最短路径问题，dijkstra算法 
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m,x;
	cin>>n>>m>>x;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(i==j) map[i][j]=0;
			else map[i][j]=inf;//图的初始化 
	for(int i=1;i<=m;i++)
	{
		int a,b,t;
		cin>>a>>b>>t;
		map[a][b]=t;
	}//边的输入 
	dijkstra(x,n,dis1);//从聚会回原农场的距离 
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++)
			 swap(map[i][j],map[j][i]);//map矩阵的转置 
	dijkstra(x,n,dis2);//从原农场去聚会的距离 
	int ans=0;
	for(int i=1;i<=n;i++)
		ans=max(ans,dis1[i]+dis2[i]);
	cout<<ans<<endl;
	return 0;
}
