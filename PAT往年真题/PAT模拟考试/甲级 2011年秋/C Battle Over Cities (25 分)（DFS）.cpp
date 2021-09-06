#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int num=2000005;//注意：链式前向星，无向图，开两倍（最大边数1000*1000的两倍）！！！ 
int n,m,k,a,b,c,ans=0;//ans为连通分量数量 
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
}//链式前向星存图 

int vis[1010],flag;
void dfs(int x)
{
	for(int i=head[x];i!=-1;i=edge[i].next)
		if(edge[i].to!=c)
		{
			if(vis[edge[i].to]==0)
			{
				vis[edge[i].to]=1;
				dfs(edge[i].to);
			}
		}
}

int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	init();
	for(int i=1;i<=m;i++)
	{
		cin>>a>>b;
		addedge(a,b);
		addedge(b,a);
	}
	for(int i=1;i<=k;i++)
	{
		memset(vis,0,sizeof(vis));
		ans=0;
		cin>>c;
		for(int i=1;i<=n;i++)
		{
			if(vis[i]==0&&i!=c)
			{
				vis[i]=1;
				ans++;
				dfs(i);
			}
		}
		cout<<ans-1<<endl;
	}
	return 0;
}
