#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int num=20005;

struct edge
{
	int to,next,w;
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
void addedge(int u,int v,int w)
{
	edge[cnt].to=v;
	edge[cnt].w=w;
	edge[cnt].next=head[u];
	head[u]=cnt++;
}
//遍历结点u的所有邻接点：
//for(int i=head[u];~i;i=edge[i].next)//~i也可以写成i!=-1 

//以上为 链式前向星 模板 

int n,maxn,far,vis[10005];
int dfs(int x,int dis)
{
	vis[x]=1;
	int flag=0;
	for(int i=head[x];i!=-1;i=edge[i].next)
		if(!vis[edge[i].to])
		{
			flag=1;
			vis[edge[i].to]=1;
			dfs(edge[i].to,dis+edge[i].w);
			vis[edge[i].to]=0;
		}
	if(flag==0)
	{
		if(dis>maxn)
		{
			maxn=dis;
			far=x;
		}
	}
}
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int a,b,c,ans;
	cin>>n;
	init();
	for(int i=1;i<=n-1;i++)
	{
		cin>>a>>b>>c;
		addedge(a,b,c);
		addedge(b,a,c);
	}
	memset(vis,0,sizeof(vis));
	dfs(1,0);
	memset(vis,0,sizeof(vis));
	dfs(far,0);
	ans=(maxn+21)*maxn/2;
	cout<<ans<<endl;
	return 0;
}
