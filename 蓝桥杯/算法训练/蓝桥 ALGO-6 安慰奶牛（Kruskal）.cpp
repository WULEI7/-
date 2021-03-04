#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int n,m,ans=0,a[10005],p[10005];
struct node
{
	int from,to,w;
}edge[100005];
bool cmp(node a,node b)
{
	return a.w<b.w;
}
int find(int x)
{
	return p[x]==x?x:p[x]=find(p[x]);
}
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	int minn=1005;
	for(int i=1;i<=n;i++)
		p[i]=i;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]<minn)
			minn=a[i];
	}
	ans=minn;
	for(int i=0;i<m;i++)
	{
		cin>>edge[i].from>>edge[i].to>>edge[i].w;
		edge[i].w*=2;
		edge[i].w+=a[edge[i].from]+a[edge[i].to];
	}
	sort(edge,edge+m,cmp);
	for(int i=0;i<m;i++)
	{
		int x=find(edge[i].from);
		int y=find(edge[i].to);
		if(x!=y)
		{
			p[x]=p[y];
			ans+=edge[i].w;
		}
	}
	cout<<ans<<endl;
	return 0;
}
