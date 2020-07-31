#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#define inf 99999999
using namespace std;
int n,a,b,vis[105],dis[105],map[105][105];
void dijkstra(int x)
{
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=n;i++)
		dis[i]=map[x][i];//以x为原点 
	for(int i=1;i<=n;i++)
	{
		int k=0,minn=inf;
		for(int j=1;j<=n;j++)
			if(vis[j]==0&&dis[j]<minn)
			{
				minn=dis[j];
				k=j;
			}
		if(k==0) break;//此句很重要，因为本题可能走不通 
		vis[k]=1;
		for(int j=1;j<=n;j++)
			if(vis[j]==0&&dis[j]>dis[k]+map[k][j])
				dis[j]=dis[k]+map[k][j];
	}
}//最短路径问题，dijkstra算法 
int main()
{
	int a,b,num,t;
	scanf("%d%d%d",&n,&a,&b);
	for(int i=0;i<=n;i++)
	for(int j=0;j<=n;j++)//这题因为有可能走不通，最好从0开始初始化 
	{
		if(i==j)
			map[i][j]=0;
		else
			map[i][j]=inf;
	}//图的初始化 
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&num);
		for(int j=1;j<=num;j++)
		{
			scanf("%d",&t);
			if(j==1)
				map[i][t]=0;
			else
				map[i][t]=1;
		}
	}
	dijkstra(a);//从a点出发 
	if(dis[b]>=inf)//有可能没法达到b点 
		printf("-1\n");
	else 
		printf("%d\n",dis[b]);
	return 0;
}
