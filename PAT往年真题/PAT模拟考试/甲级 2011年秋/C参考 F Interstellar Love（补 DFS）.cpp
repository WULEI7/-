#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int num=20005;

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

int vis[10005],flag;
void dfs(int x,int fa)
{
	for(int i=head[x];i!=-1;i=edge[i].next)
		if(edge[i].to!=fa)
		{
			if(vis[edge[i].to]==0)
			{
				vis[edge[i].to]=1;
				dfs(edge[i].to,x);
			}
			else
				flag=0;
		}
}

int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int T;
	cin>>T;
	for(int t=1;t<=T;t++)
	{
		int n,m,a,b,ans=0,fix=0;
		cin>>n>>m;
		init();
		memset(vis,0,sizeof(vis));
		for(int i=1;i<=m;i++)
		{
			cin>>a>>b;
			addedge(a,b);
			addedge(b,a);
		}
		for(int i=1;i<=n;i++)
			if(vis[i]==0)
			{
				vis[i]=1;
				flag=1;
				if(head[i]!=-1)
				{
					ans++;
					dfs(i,0);
					if(flag==0)
						fix++;
				}
			}
		printf("Night sky #%d: %d constellations, of which %d need to be fixed.\n\n",t,ans,fix);
	}
	return 0;
}
