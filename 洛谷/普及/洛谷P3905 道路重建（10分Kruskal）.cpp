#include <cstdio>
#include <iostream>
#include <algorithm>
const int maxn=10005;
using namespace std;
int u[maxn],v[maxn],w[maxn],p[maxn],r[maxn],flag[maxn];
int cmp(const int i,const int j)
{
	return w[i]<w[j];
}//边权比较 
int find(int x)
{
	return p[x]==x ? x:p[x]=find(p[x]);
}//并查集 
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m,d,s,t,ans=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		p[i]=i;//并查集初始化 
	for(int i=0;i<m;i++)
		r[i]=i;//边的序号 
	for(int i=0;i<m;i++)
		cin>>u[i]>>v[i]>>w[i];
	cin>>d;
	for(int i=0;i<d;i++)
	{
		int a,b;
		cin>>a>>b;
		for(int i=0;i<m;i++)
			if(u[i]==a&&v[i]==b||u[i]==b&&v[i]==a)
				flag[i]=1;
	}//标记被破坏的道路 
	for(int i=0;i<m;i++)
		if(flag[i]==0)
			w[i]=0;//未被破坏的道路权值设为0 
	sort(r,r+m,cmp);
	cin>>s>>t;
	for(int i=0;i<m;i++)
	{
		int e=r[i];
		int x=find(u[e]);
		int y=find(v[e]);
		if(x!=y)
		{
			p[x]=p[y];
			ans+=w[e];//重点！这道题不能用Kruskal，因为这里不是求最大边长，而是完整路径长度 
		}
		if(find(s)==find(t)) break;//当s和t连通时结束 
	}
	cout<<ans<<endl;
	return 0;
}
