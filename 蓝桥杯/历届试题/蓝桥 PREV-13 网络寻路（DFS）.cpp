#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

struct edge
{
	int to,next;
}edge[200005];
int cnt,head[10005];
void init()
{
	for(int i=0;i<200005;i++)
		edge[i].next=-1;
	for(int i=0;i<10005;i++)
		head[i]=-1;
	cnt=0;
}
void addedge(int u,int v)
{
	edge[cnt].to=v;
	edge[cnt].next=head[u];
	head[u]=cnt++;
}

int n,m,vis[10005],ans=0;
void dfs(int x,int t)
{
	if(t==2)
	{
		int cnt=0;
		int i=head[x];
		while(i!=-1)
		{
			cnt++;
			i=edge[i].next;
		}
		ans+=cnt-1;
	}
	else
	{
		vis[x]=1;
		for(int i=head[x];i!=-1;i=edge[i].next)
			if(!vis[edge[i].to])
				dfs(edge[i].to,t+1);
		vis[x]=0;
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
	for(int i=1;i<=n;i++)
	{
		memset(vis,0,sizeof(vis));
		dfs(i,0);
	}
	cout<<ans<<endl;
	return 0;
}
