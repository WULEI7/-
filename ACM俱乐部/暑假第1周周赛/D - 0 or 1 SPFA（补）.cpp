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
			dis[i]=inf;//����Ϊ���޴� 
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
}//spfa�㷨�����·�� 
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	while(~scanf("%d",&n))//��cin�ᳬʱ 
	{
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				scanf("%d",&map[i][j]);//���������ڽӾ��� 
		int ans1,ans2;//ans1��1��n�����·����ans2��1��n����С��֮�� 
		spfa(1);
		ans1=dis[n];
		ans2=dis[1];
		spfa(n);
		ans2+=dis[n];
		printf("%d\n",min(ans1,ans2));//�������ߵĽ�Сֵ 
	}
	return 0;
}
