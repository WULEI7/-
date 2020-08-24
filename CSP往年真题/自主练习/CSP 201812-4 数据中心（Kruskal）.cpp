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
}//²¢²é¼¯ 
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m,root,ans=0;
	cin>>n>>m>>root;
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
	}
	cout<<ans<<endl;
	return 0;
}
