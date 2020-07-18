#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#define inf 99999999
using namespace std;
int n,vis[305],dis[305],map[305][305];
void dijkstra(int x)//从x到n的最短路径 
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
		vis[k]=1;
		for(int j=1;j<=n;j++)
			if(vis[j]==0&&dis[j]>dis[k]+map[k][j])
				dis[j]=dis[k]+map[k][j];
	}
}//最短路径问题，dijkstra算法 
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	while(~scanf("%d",&n))
	{
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				scanf("%d",&map[i][j]);//此题直接输入邻接矩阵 
		for(int i=1;i<=n;i++)
			map[i][i]=inf;//将到自身距离设为无限大 
		int ans1,ans2;//ans1是1到n的最短路径，ans2是1和n的最小环之和 
		dijkstra(1);
		ans1=dis[n],ans2=dis[1];
		dijkstra(n);
		ans2+=dis[n];
		printf("%d\n",min(ans1,ans2));//答案是两者中较小的 
	}
	return 0;
}
