#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int n,cnt=0,t,size[1000005],head[1000005];
long long ans=0;

struct node
{
	int dis,next,v;
}edge[2000005];

void add(int u,int v,int w)
{
	cnt++;
	edge[cnt].next=head[u];
	edge[cnt].v=v;
	edge[cnt].dis=w;
	head[u]=cnt; 
}

void dfs(int u,int f)
{
	size[u]=1;
	for(int i=head[u];i!=0;i=edge[i].next)
	{
		int v=edge[i].v;
		if(v!=f)
		{
			dfs(v,u);
			ans+=(long long)abs(size[v]-(n-size[v]))*edge[i].dis;
			size[u]+=size[v];
		}
	}
}

int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n-1;i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		add(a,b,c);
		add(b,a,c);
	}
	dfs(1,0);
	cout<<ans<<endl;
	return 0;
}
