#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <queue>
#define inf 99999999
using namespace std;
int n,vis[305],dis[305],map[305][305];
void spfa(int x)
{
	queue<int> q;
	for(int i=1;i<=n;i++)
	{
		if(i==x)
		{
			dis[i]=inf;//自身为无限大 
			vis[i]=0;
		}
		else
		{
			dis[i]=map[x][i];
			vis[i]=1;
			q.push(i);
		}
	}
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		vis[u]=0;
		for(int i=1;i<=n;i++)
			if(dis[i]>dis[u]+map[u][i])
			{
				dis[i]=dis[u]+map[u][i];
				if(vis[i]==0)
                {
					vis[i]=1;
					q.push(i);
				}
			}
	}
}//spfa算法求最短路径 
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	while(~scanf("%d",&n))//用cin会超时 
	{
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				scanf("%d",&map[i][j]);//此题输入邻接矩阵 
		int ans1,ans2;//ans1是1到n的最短路径，ans2是1和n的最小环之和 
		spfa(1);
		ans1=dis[n];
		ans2=dis[1];
		spfa(n);
		ans2+=dis[n];
		printf("%d\n",min(ans1,ans2));//答案是两者的较小值 
	}
	return 0;
}
