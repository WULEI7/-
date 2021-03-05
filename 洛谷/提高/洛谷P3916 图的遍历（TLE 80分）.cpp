#include <iostream>
#include <cstdio>
#include <cstring>
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

int n,m,maxn,far,vis[100005];
int dfs(int x,int &a)
{
	vis[x]=1;
	if(x>a) a=x;
	for(int i=head[x];i!=-1;i=edge[i].next)
		if(!vis[edge[i].to])
		{
			vis[edge[i].to]=1;
			dfs(edge[i].to,a);
			//vis[edge[i].to]=0;
		}
}
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int a,b,ans[100005];
	//freopen("P3916_1.in","r",stdin);
	cin>>n>>m;
	init();
	for(int i=0;i<=n;i++)
		ans[i]=i;
	for(int i=1;i<=m;i++)
	{
		cin>>a>>b;
		addedge(a,b);
	}
	for(int i=1;i<=n;i++)
	{
		memset(vis,0,sizeof(vis));
		dfs(i,ans[i]);
	}
	for(int i=1;i<=n;i++)
		printf("%d ",ans[i]);
	return 0;
}
