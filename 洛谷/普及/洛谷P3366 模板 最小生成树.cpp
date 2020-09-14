#include <cstdio>
#include <iostream>
#include <algorithm>
const int maxn=200005;
using namespace std;
int n,m,u[maxn],v[maxn],w[maxn],p[maxn],r[maxn];
bool cmp(const int i,const int j)
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
	cin>>n>>m;
	int flag=n-1,ans=0,a,b;
	for(int i=1;i<=n;i++)
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
			p[x]=p[y];
			flag--;
			ans+=w[e];
		}
	}
	if(flag>0)//图不连通 
		printf("orz\n");
	else
		printf("%d\n",ans);
	return 0;
}
