#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#define inf 99999999
using namespace std;
int n,vis[105],dis[105],map[105][105],flag[105][105];
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
		if(k==0) break;//最好写上，因为有的题目可能走不通 
		vis[k]=1;
		for(int j=1;j<=n;j++)
			if(vis[j]==0&&dis[j]>dis[k]+map[k][j])
				dis[j]=dis[k]+map[k][j];
	}
}//最短路径问题，dijkstra算法 
int main()
{
	int m,d,s,t,w,ans=0;
	scanf("%d%d",&n,&m);
	for(int i=0;i<=n;i++)
	for(int j=0;j<=n;j++)//最好从0开始初始化，因为有的题目可能走不通 
	{
		if(i==j)
			map[i][j]=0;
		else
			map[i][j]=inf;
	}//图的初始化 
	while(m--)
	{
		scanf("%d%d%d",&s,&t,&w);
		map[s][t]=map[t][s]=w;
	}
	scanf("%d",&d);
	while(d--)
	{
		scanf("%d%d",&s,&t);
		flag[s][t]=flag[t][s]=1;
	}
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
		if(flag[i][j]==0&&map[i][j]<inf)//注意细节！ 
			map[i][j]=0;
	scanf("%d%d",&s,&t);
	dijkstra(s);//从s点出发 
	printf("%d\n",dis[t]);
	return 0;
}
