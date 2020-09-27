#include <cstdio>
#include <iostream>
#include <algorithm>
const int maxn=100005;
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
	int n,m,cnt,ans=0;
	cin>>n>>m;
	cnt=n-1;//需要的边数 
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
			p[x]=y;
			if(w[e]>ans)
				ans=w[e];
			cnt--;
		}
		if(cnt==0) break;
	}
	if(cnt==0)
		printf("%d\n",ans);
	else
		printf("-1\n");
	return 0;
}
