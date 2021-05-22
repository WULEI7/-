#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
const int INF=0x3f3f3f3f;//无穷大 
int n,ans=0,g[105][105],dis[105],vis[105];
struct edge
{
	int u,v,d;//边的起点、终点、权值 
	bool operator < (const edge &a) const
	{
		return d>a.d;
	}
};
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	{
		cin>>g[i][j];
		if(g[i][j]==0)
			g[i][j]=INF;
	}
	priority_queue<edge> q;//优先队列 
	int temp=1,cnt=0;//当前顶点和边数 
	for(int i=1;i<=n;i++)
	{
		if(i!=temp)
		{
			dis[i]=g[temp][i];
			q.push({temp,i,g[temp][i]});
		}
	}//从结点1开始 
	while(!q.empty())
	{
		edge t=q.top();
		q.pop();
		int u=t.u,v=t.v,d=t.d;
		if(vis[v]) continue;//已经在已加入点的集合当中 
		vis[v]=1;
		cnt++;
		cout<<v<<" "<<u<<" "<<d<<endl;
		//ans+=t.d;
		if(cnt==n-1) break;
		temp=v;
		for(int i=1;i<=n;i++)
		{
			if(!vis[i]&&g[temp][i]<dis[i])
			{
				dis[i]=g[temp][i];
				q.push({temp,i,g[temp][i]});
			}
		}//更新优先队列 
	}
	//cout<<ans<<endl;
	return 0;
}
