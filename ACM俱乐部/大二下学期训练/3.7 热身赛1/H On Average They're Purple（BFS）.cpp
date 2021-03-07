#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
const int num=200005;

struct edge
{
	int to,next;
}edge[num];
int cnt,head[num];
void init()
{
	for(int i=0;i<num;i++)
	{
		edge[i].next=-1;
		head[i]=-1;
	}
	cnt=0;
}
void addedge(int u,int v)
{
	edge[cnt].to=v;
	edge[cnt].next=head[u];
	head[u]=cnt++;
}

int n,m,dis[num],vis[num];
void bfs(int x)
{
	queue<int> q;
	q.push(x);
	vis[x]=1;
	while(!q.empty()&&!vis[n])
	{
		int t=q.front();
		q.pop();
		for(int i=head[t];i!=-1;i=edge[i].next)
			if(!vis[edge[i].to])
			{
				q.push(edge[i].to);
				vis[edge[i].to]=1;
				dis[edge[i].to]=dis[t]+1;
			}
	}
}

int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	init();
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int a,b;
		cin>>a>>b;
		addedge(a,b);
		addedge(b,a);
	}
	bfs(1);
	cout<<dis[n]-1<<endl;
	return 0;
}
