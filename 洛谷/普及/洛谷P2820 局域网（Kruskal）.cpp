#include <iostream>
#include <cstdio>
#include <algorithm>
const int maxn=10005;
using namespace std;
int u[maxn],v[maxn],w[maxn],p[maxn],r[maxn];
bool cmp(int i,int j)
{
	return w[i]<w[j];
}//边权比较 
int find(int x)
{
	return p[x]==x?x:p[x]=find(p[x]);
}//并查集 
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m,tot=0,cnt=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		p[i]=i;
	for(int i=0;i<m;i++)
		r[i]=i;
	for(int i=0;i<m;i++)
	{
		cin>>u[i]>>v[i]>>w[i];
		tot+=w[i];
	}
	sort(r,r+m,cmp);
	for(int i=0;i<m;i++)
	{
		int e=r[i];
		int x=find(u[e]);
		int y=find(v[e]);
		if(x!=y)
		{
			p[x]=p[y];
			cnt+=w[e];
		}
	}
	printf("%d\n",tot-cnt);
	return 0;
}

