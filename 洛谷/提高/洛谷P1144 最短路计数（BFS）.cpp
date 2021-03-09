#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
const int mod=100003;

struct edge
{
	int to,next;
}edge[4000005];
int cnt,head[1000005];
void init()
{
	for(int i=0;i<4000005;i++)
		edge[i].next=-1;
	for(int i=0;i<1000005;i++)
		head[i]=-1;
	cnt=0;
}
void addedge(int u,int v)
{
	edge[cnt].to=v;
	edge[cnt].next=head[u];
	head[u]=cnt++;
}

int n,m,dis[1000005],vis[1000005],ans[1000005];
void bfs(int x)
{
	queue<int> q;
	q.push(x);
	vis[x]=1;
	ans[x]=1;
	dis[x]=0;
	while(!q.empty())
	{
		int t=q.front();
		q.pop();
		for(int i=head[t];i!=-1;i=edge[i].next)
		{
			if(!vis[edge[i].to])
			{
				q.push(edge[i].to);
				vis[edge[i].to]=1;
				dis[edge[i].to]=dis[t]+1;
			}
			if(dis[edge[i].to]==dis[t]+1)
			{
				ans[edge[i].to]+=ans[t];
				ans[edge[i].to]%=mod;
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	int a,b;
	init();
	for(int i=1;i<=m;i++)
	{
		cin>>a>>b;
		addedge(a,b);
		addedge(b,a);
	}
	bfs(1);
	for(int i=1;i<=n;i++)
		cout<<ans[i]<<endl;
	return 0;
}
