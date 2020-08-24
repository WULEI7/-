#include <cstdio>
#include <iostream>
#include <algorithm>
const int maxn=1000005;
using namespace std;
int u[maxn],v[maxn],w[maxn],p[maxn],r[maxn];
int cmp(const int i,const int j)
{
	return w[i]<w[j];
}
int find(int x)
{
	return p[x]==x ? x:p[x]=find(p[x]);
}//并查集 
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m,ans=0;
	cin>>n>>m;
	for(int i=0;i<n;i++)
		p[i]=i;
	for(int i=0;i<m;i++)
		r[i]=i;
	for(int i=0;i<m;i++)
		cin>>u[i]>>v[i]>>w[i];
	sort(r,r+m,cmp);
	for(int i=0;i<m;i++)
	{
		int e=r[i];
		int x=find(u[e]);
		int y=find(v[e]);
		if(x!=y)
		{
			p[x]=y;
			if(w[e]>ans)
				ans=w[e];
		}
		if(find(1)==find(n)) break;//当1和n连通时结束 
	}
	cout<<ans<<endl;
	return 0;
}
